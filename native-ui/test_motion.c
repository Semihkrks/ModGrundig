#include "motion.h"

#include <stdio.h>
#include <stdlib.h>

static unsigned checks;

#define CHECK(expression) do { \
    ++checks; \
    if (!(expression)) { \
        fprintf(stderr, "FAIL line %d: %s\n", __LINE__, #expression); \
        exit(EXIT_FAILURE); \
    } \
} while (0)

int main(void)
{
    mg_motion motion;
    uint32_t t;
    int32_t previous;
    int32_t current;
    unsigned i;

    mg_motion_init(&motion, -1, 0U);
    CHECK(mg_motion_sample(&motion, 0U) == 0);
    mg_motion_init(&motion, 101, 0U);
    CHECK(mg_motion_sample(&motion, 0U) == 10000);

    mg_motion_init(&motion, 0, 0U);
    mg_motion_retarget(&motion, 100, 0U, 200U);
    CHECK(mg_motion_sample(&motion, 0U) == 0);
    CHECK(mg_motion_sample(&motion, 50U) == 4375);
    CHECK(mg_motion_sample(&motion, 100U) == 7500);
    CHECK(mg_motion_sample(&motion, 150U) == 9375);
    CHECK(mg_motion_sample(&motion, 200U) == 10000);

    mg_motion_retarget(&motion, 0, 200U, 150U);
    previous = 10000;
    for (t = 200U; t <= 350U; ++t) {
        current = mg_motion_sample(&motion, t);
        CHECK(current <= previous && current >= 0);
        previous = current;
    }
    CHECK(previous == 0);

    mg_motion_init(&motion, 0, 0U);
    mg_motion_retarget(&motion, 100, 0U, 200U);
    current = mg_motion_sample(&motion, 50U);
    mg_motion_retarget(&motion, 0, 50U, 150U);
    CHECK(mg_motion_sample(&motion, 50U) == current);
    CHECK(mg_motion_sample(&motion, 100U) < current);
    CHECK(mg_motion_sample(&motion, 200U) == 0);

    /* Latest input wins; no target queue accumulates under a key burst. */
    mg_motion_init(&motion, 50, 0U);
    for (i = 1U; i <= 1000U; ++i) {
        t = i * 3U;
        current = mg_motion_sample(&motion, t);
        mg_motion_retarget(&motion, (i % 2U) != 0U ? 100 : 0, t, 150U);
        CHECK(mg_motion_sample(&motion, t) == current);
        CHECK(current >= 0 && current <= 10000);
    }
    CHECK(mg_motion_sample(&motion, 3150U) == 0);

    /* An unchanged target preserves its original completion deadline. */
    mg_motion_init(&motion, 0, 0U);
    mg_motion_retarget(&motion, 80, 0U, 200U);
    for (t = 10U; t < 200U; t += 10U) {
        mg_motion_retarget(&motion, 80, t, 200U);
        CHECK(motion.started_ms == 0U);
    }
    CHECK(mg_motion_sample(&motion, 200U) == 8000);

    mg_motion_retarget(&motion, -100, 201U, 0U);
    CHECK(mg_motion_sample(&motion, 201U) == 0);
    mg_motion_retarget(&motion, 1000, 202U, 0U);
    CHECK(mg_motion_sample(&motion, 202U) == 10000);
    mg_motion_retarget(&motion, 0, 203U, 200U);
    mg_motion_retarget(&motion, 0, 204U, 0U);
    CHECK(mg_motion_sample(&motion, 204U) == 0);

    /* Unsigned elapsed handles a single clock rollover. */
    mg_motion_init(&motion, 0, UINT32_MAX - 49U);
    mg_motion_retarget(&motion, 100, UINT32_MAX - 49U, 200U);
    CHECK(mg_motion_sample(&motion, 0U) == 4375);
    CHECK(mg_motion_sample(&motion, 150U) == 10000);
    mg_motion_retarget(&motion, 0, 151U, 200U);
    CHECK(mg_motion_sample(&motion, 1000000000U) == 0);

    /* Huge duration cannot overflow multiplication or exceed the bound. */
    mg_motion_retarget(&motion, 100, 1000000000U, UINT32_MAX);
    CHECK(motion.duration_ms == MG_MOTION_MAX_DURATION_MS);
    CHECK(mg_motion_sample(&motion, 1000030000U) == 7500);
    CHECK(mg_motion_sample(&motion, 1000060000U) == 10000);

    mg_motion_retarget(&motion, 0, 1000060001U, 1U);
    CHECK(mg_motion_sample(&motion, 1000060001U) == 10000);
    CHECK(mg_motion_sample(&motion, 1000060002U) == 0);

    /* Dense up/down sweeps validate direction, range, exact endpoints. */
    for (i = 0U; i <= 100U; ++i) {
        int target = (int)(100U - i);
        mg_motion_init(&motion, (int)i, 0U);
        mg_motion_retarget(&motion, target, 0U, 200U);
        previous = (int32_t)i * 100;
        for (t = 0U; t <= 200U; ++t) {
            current = mg_motion_sample(&motion, t);
            CHECK(current >= 0 && current <= 10000);
            CHECK(target >= (int)i ? current >= previous : current <= previous);
            previous = current;
        }
        CHECK(previous == (int32_t)target * 100);
    }

    printf("{\"status\":\"pass\",\"checks\":%u,\"profile\":\"host-c99\","
           "\"firmware_integrated\":false}\n", checks);
    return EXIT_SUCCESS;
}
