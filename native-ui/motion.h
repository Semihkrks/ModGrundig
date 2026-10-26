#ifndef MODGRUNDIG_MOTION_H
#define MODGRUNDIG_MOTION_H

#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Visual units: 0..10000 corresponds to volume 0..100. */
#define MG_MOTION_SCALE 100
#define MG_MOTION_MAX 10000
#define MG_MOTION_MAX_DURATION_MS 60000U

typedef struct {
    int32_t origin;
    int32_t target;
    uint32_t started_ms;
    uint32_t duration_ms;
} mg_motion;

/* Initialize before use; timestamps must be monotonic modulo uint32_t wrap. */
void mg_motion_init(mg_motion *motion, int level, uint32_t now_ms);
/* Sampled ease-out, with no allocation or floating-point arithmetic. */
int32_t mg_motion_sample(mg_motion *motion, uint32_t now_ms);
/* Retarget the current visual position; duration 0 means immediate. */
void mg_motion_retarget(mg_motion *motion, int level, uint32_t now_ms,
                        uint32_t duration_ms);

#ifdef __cplusplus
}
#endif

#endif
