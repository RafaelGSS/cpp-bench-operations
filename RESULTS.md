### 2023-01-12T17:05:56-03:00
```
Running ./app
Run on (6 X 3950 MHz CPU s)
CPU Caches:
  L1 Data 32 KiB (x6)
  L1 Instruction 32 KiB (x6)
  L2 Unified 512 KiB (x6)
  L3 Unified 16384 KiB (x2)
Load Average: 0.98, 0.80, 0.75
***WARNING*** CPU scaling is enabled, the benchmark real time measurements may be noisy and will incur extra overhead.
-------------------------------------------------------------------------------------
Benchmark                                           Time             CPU   Iterations
-------------------------------------------------------------------------------------
StringViewCopy                                   1.02 ns         1.01 ns    690035385
StringViewCreation                               14.3 ns         14.3 ns     49297160
StringViewCreateOptional                         5.04 ns         5.04 ns    133880151
StringViewCreateEmpty                            14.1 ns         14.1 ns     49743652
BM_UnorderedMapSquareBracketsAccessValid         52.8 ns         52.8 ns     13342655
BM_UnorderedMapSquareBracketsAccessMissing       53.1 ns         53.1 ns     13234043
BM_UnorderedFindAccessValid                      62.4 ns         62.4 ns     10981774
BM_UnorderedFindAccessMissing                    64.1 ns         64.0 ns     10918000
BM_StdArraySquareBracketsAccessValid             3.82 ns         3.82 ns    183224528
BM_MapSquareBracketsAccessValid                  55.9 ns         55.9 ns     12598821
BM_MapSquareBracketsAccessMissing                67.7 ns         67.7 ns     10297041
BM_MapFindAccessValid                            61.5 ns         61.4 ns     11245882
BM_MapFindAccessMissing                          48.9 ns         48.9 ns     14378853
StringCopy                                       8.91 ns         8.90 ns     78619526
StringCreation                                   41.9 ns         41.9 ns     16596055
```
