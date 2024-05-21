# test results

Ran on a 13900kf under WSL. Compiled with clang 18.1.4.

### Old (SFML/SFML 53ade4b)

```cpp
-------------------------------------------------------------------------------------------------
Benchmark                                       Time             CPU   Iterations UserCounters...
-------------------------------------------------------------------------------------------------
BM_transform_combine/min_time:4.000          2.64 ns         2.64 ns   2121118680 items_per_second=378.547M/s
BM_transform_getInverse/min_time:4.000       1.12 ns         1.12 ns   4978865605 items_per_second=890.346M/s
BM_transform_translate/min_time:4.000        2.09 ns         2.09 ns   2673725429 items_per_second=479.336M/s
BM_transform_rotate/min_time:4.000           8.66 ns         8.66 ns    651674658 items_per_second=115.518M/s
BM_transform_scale/min_time:4.000            2.57 ns         2.57 ns   2182173196 items_per_second=388.433M/s
```

### New (L0laapk3/SFML 3f84010)

```cpp
-------------------------------------------------------------------------------------------------
Benchmark                                       Time             CPU   Iterations  UserCounters...
-------------------------------------------------------------------------------------------------
BM_transform_combine/min_time:4.000          1.69 ns         1.69 ns   3325438781  items_per_second=593.03M/s
BM_transform_getInverse/min_time:4.000      0.553 ns        0.553 ns   10134886287 items_per_second=1.80678G/s
BM_transform_translate/min_time:4.000        1.39 ns         1.39 ns   3978370735  items_per_second=718.688M/s
BM_transform_rotate/min_time:4.000           7.58 ns         7.58 ns    737395540  items_per_second=131.899M/s
BM_transform_scale/min_time:4.000            1.69 ns         1.69 ns   3315908628  items_per_second=590.678M/s
```