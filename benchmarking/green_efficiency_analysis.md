# Green Efficiency Analysis

## Measurement Methodology

All programs were written in C and timed with `clock()` from `<time.h>`, converting clock ticks to seconds with `CLOCKS_PER_SEC`. Each program was compiled with `gcc -O2` and run three times in a GitHub Codespaces environment. Only the algorithmic section was inside each timed region, and printing was kept outside it. For the instrumentation lab, every phase (build, process, reduce) was timed around its function call, and TOTAL started before the first phase and ended after the last one, so TOTAL is at least as large as each part.

## Observed Performance Differences

The baseline loop of 100000000 iterations took 0.091282, 0.135127 and 0.116827 seconds in the three runs. The average is about 0.114 seconds, and the spread between the fastest and slowest run is roughly 0.044 seconds. This shows that even a deterministic computation does not give identical timings.

The algorithm comparison showed a far larger difference. The naive algorithm took 1.118905, 0.955935 and 0.934382 seconds, averaging 1.003074 seconds. The single-pass algorithm took 0.000005, 0.000010 and 0.000005 seconds, averaging 0.000007 seconds. The naive version was therefore about 150461 times slower. The ratio is approximate because the single-pass time is near the resolution of `clock()`. Both versions give the same count, so the gap comes only from the algorithm: the naive one repeats work in nested loops (quadratic), while the single-pass one reads each element once (linear).

In the instrumentation lab, the average timings were TOTAL 0.000306 seconds, BUILD_DATA 0.000164, PROCESS 0.000071 and REDUCE 0.000064. Building the dataset used about 54 percent of the total, process about 23 percent and reduce about 21 percent. The three parts add up to slightly less than TOTAL, because TOTAL also includes the small gaps between calls.

## Relation Between Runtime and Energy Consumption

Energy used by a processor is approximately its power draw multiplied by the time it is busy. If power stays roughly constant while the CPU is working, a program that runs for less time uses less energy. The naive algorithm kept the CPU busy for about 1.0 second, while the single-pass algorithm needed about 0.000007 seconds for the same result. Under that simple model, the single-pass version would use a tiny fraction of the energy. This is a reasoned estimate based on measured runtime, not a measured energy value.

## Limitations of the Experiment

Energy was never measured. Only CPU time was recorded, so the link between runtime and energy is an assumption that power stays constant. The experiment ran in a shared cloud environment, where other workloads can add noise, as the baseline variation of 0.091 to 0.135 seconds shows. Only three runs per program were made, which is too few for strong statistics. The instrumentation lab timings are a few hundred microseconds, close to the resolution of `clock()`, so small differences between them are not reliable. The compiler optimization level may also change how loops are executed.

## Practical Engineering Takeaway

Choosing a better algorithm gave a far larger gain than any other change observed here: a difference of about five orders of magnitude, compared with variation of tens of milliseconds between runs of the same loop. Engineers should measure first, find which phase dominates, and fix the algorithm before tuning small details. In this lab, dataset building was the largest phase, so that is where effort would go first. Less runtime generally means less energy, which makes efficient algorithms a practical way to build greener software.
