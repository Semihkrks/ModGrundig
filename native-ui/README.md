# Native visual motion candidate

`motion.c` is an allocation-free C99 visual interpolation helper for a future
MIPS/MUF adapter. It is **not integrated with VolumeControlFrame or libmuf**.
It does not call audio, HDMI-CEC, routing, key handling, timers or drawing APIs.
The existing audio path must accept input immediately; only the displayed bar
position should be interpolated. Mute and ARC state stay outside this helper.

## Contract

- Initialize one `mg_motion` state, then retarget using the latest visual level.
- Levels are clamped to 0..100; samples return fixed-point 0..10000.
- Sample once per actual redraw/timer, using a monotonic uint32 millisecond clock.
- Retarget first samples the current position, preserving position continuity
  during rapid reversal. Velocity continuity is not guaranteed by this quadratic
  ease-out function. It stores no queue, allocates nothing and uses no floats.
- Recommended visual durations are 150 or 200 ms. Zero snaps immediately,
  including when the target has not changed. An identical nonzero-duration target
  does not restart the animation. Durations above 60000 ms are clamped.
- Unsigned elapsed subtraction handles clock rollover. Callers must not supply
  backward timestamps or leave an active state unobserved for a complete uint32
  clock period (~49.7 days), which cannot be distinguished from short elapsed time.
- Calls on a state must be serialized on its UI thread. Initialize before use;
  pointers must be non-null. The state contains no synchronization primitives.

All intermediate arithmetic fits 32 bits with this range/duration contract.
The target value is suitable for the numeric label; the sample is suitable for
the thin bar. An adapter must convert to widget pixel geometry and invalidate
only the changed area. This file makes no framebuffer or resource allocation.

## Firmware evidence and limitations

The analyzed build is GMGRMR V03.017.04. In libmuf,
`MWidget::StartAnimation` at **0x2e259b4c** starts a 50 ms async timer;
`MWidget::OnAnimationTimer` at **0x2e25a1c8** uses `counter * 50`;
`MAnimation::SetDuration` at **0x2e22bae8** floors duration to 50 ms multiples.
In dvbt_board, `ArUIManager::GetAnimationEnabled` at **0x00555ed4** returns 0
in this build. Its call sites must be evaluated individually; this helper does
not change that getter or enable global animations.

Evidence: [UI code and timer analysis](../docs/UI_KOD_YAPISI.md),
[duration C](../analiz/native/ui-targeted/libmuf/2e22bae8.c),
[animation gate C](../analiz/native/ui-targeted/dvbt_board/00555ed4.c).

A nominal 50 ms tick offers only three intervals over 150 ms and four over
200 ms. This is not measured TV frame rate and cannot support a 60 fps claim.
Host tests validate the interpolation contract only. No compatible MIPS SDK or
cross-compiler was identified in this implementation task; host compilation
does not establish target ABI, renderer performance or TV behavior. A future
adapter still needs validated widget bindings, lifecycle/timer cancellation,
redraw behavior and testing on the actual target before integration is complete.
No firmware image has been modified, repacked or uploaded by this work.

## Reproduce host tests (WSL)

```sh
gcc -std=c99 -Wall -Wextra -Werror -pedantic native-ui/motion.c \
  native-ui/test_motion.c -o /tmp/modgrundig-test-motion
/tmp/modgrundig-test-motion
```

The tests cover exact 150/200 ms endpoints, monotonic up/down motion, rapid
alternating input, continuous retarget positions, repeated-target deadlines,
clamping, immediate mode, single millisecond duration, large time intervals,
rollover and maximum-duration arithmetic. `test-result.json` records the host
run, not a firmware or TV pass.
