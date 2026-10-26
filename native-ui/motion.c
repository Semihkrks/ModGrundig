#include "motion.h"

static int32_t visual_level(int level)
{
    if (level < 0) {
        return 0;
    }
    if (level > 100) {
        return MG_MOTION_MAX;
    }
    return (int32_t)level * MG_MOTION_SCALE;
}

void mg_motion_init(mg_motion *motion, int level, uint32_t now_ms)
{
    motion->origin = visual_level(level);
    motion->target = motion->origin;
    motion->started_ms = now_ms;
    motion->duration_ms = 0U;
}

int32_t mg_motion_sample(mg_motion *motion, uint32_t now_ms)
{
    uint32_t elapsed = now_ms - motion->started_ms;
    uint32_t progress;
    uint32_t ease;
    int32_t delta;

    if (motion->duration_ms == 0U || elapsed >= motion->duration_ms) {
        motion->origin = motion->target;
        motion->duration_ms = 0U;
        return motion->target;
    }
    /* Duration is capped at 60000; every intermediate fits in 32 bits. */
    progress = (elapsed * 10000U) / motion->duration_ms;
    ease = 10000U - ((10000U - progress) * (10000U - progress)) / 10000U;
    delta = motion->target - motion->origin;
    return motion->origin + (delta * (int32_t)ease) / 10000;
}

void mg_motion_retarget(mg_motion *motion, int level, uint32_t now_ms,
                        uint32_t duration_ms)
{
    int32_t target = visual_level(level);
    int32_t current = mg_motion_sample(motion, now_ms);

    if (duration_ms == 0U) {
        mg_motion_init(motion, level, now_ms);
        return;
    }
    /* Repeat notifications must not postpone an already active transition. */
    if (target == motion->target) {
        return;
    }
    motion->origin = current;
    motion->target = target;
    motion->started_ms = now_ms;
    motion->duration_ms = duration_ms > MG_MOTION_MAX_DURATION_MS
        ? MG_MOTION_MAX_DURATION_MS : duration_ms;
}
