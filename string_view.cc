#include <benchmark/benchmark.h>
#include <string_view>

static void StringViewCreation(benchmark::State& state) {
  for (auto _ : state) {
    std::string_view created_string("hello");
    // Make sure the variable is not optimized away by compiler
    benchmark::DoNotOptimize(created_string);
  }
}

static void StringViewCopy(benchmark::State& state) {
  std::string_view x = "hello";
  for (auto _ : state) {
    std::string_view copy(x);
  }
}

BENCHMARK(StringViewCopy);
BENCHMARK(StringViewCreation);
