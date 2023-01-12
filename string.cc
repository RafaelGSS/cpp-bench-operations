#include <benchmark/benchmark.h>
#include <string>

static void StringCreation(benchmark::State& state) {
  for (auto _ : state) {
    std::string created_string("hello");
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(created_string);
  }
}

static void StringCopy(benchmark::State& state) {
  std::string x = "hello";
  for (auto _ : state) {
    std::string copy(x);
  }
}

BENCHMARK(StringCopy);
BENCHMARK(StringCreation);
