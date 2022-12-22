#include <benchmark/benchmark.h>
#include <array>
#include "./utils.h"

static void BM_StdArraySquareBracketsAccessValid(benchmark::State& state) {
  std::array<int, static_cast<size_t>(Items::kCount)> m { 0, 1, 2, 3, 4, 5 };

  for (auto _ : state) {
    auto value = m[static_cast<size_t>(Items::Three)];
    auto b = 1;
    if (!value) {
      ++b;
    }
  }
}

BENCHMARK(BM_StdArraySquareBracketsAccessValid);
