#include <unordered_map>
#include <benchmark/benchmark.h>
#include "./utils.h"

static void BM_UnorderedMapSquareBracketsAccessValid(benchmark::State& state) {
  std::unordered_map<Items, int> m {
    { Items::Zero, 0 }, { Items::One, 1 }, { Items::Two, 2 },
    { Items::Three, 3 }, { Items::Four, 4 },
  };

  for (auto _ : state) {
    auto value = m[Items::Three];
    auto b = 1;
    if (!value) {
      ++b;
    }
  }
}

static void BM_UnorderedMapSquareBracketsAccessMissing(benchmark::State& state) {
  std::unordered_map<Items, int> m {
    { Items::Zero, 0 }, { Items::One, 1 }, { Items::Two, 2 },
    { Items::Three, 3 }, { Items::Four, 4 },
  };

  for (auto _ : state) {
    auto value = m[Items::Five];
    auto b = 1;
    if (!value) {
      ++b;
    }
  }
}

static void BM_UnorderedFindAccessValid(benchmark::State& state) {
  std::unordered_map<Items, int> m {
    { Items::Zero, 0 }, { Items::One, 1 }, { Items::Two, 2 },
    { Items::Three, 3 }, { Items::Four, 4 },
  };

  for (auto _ : state) {
    auto it = m.find(Items::Three);
    auto b = 1;
    if (it == m.end()) {
      ++b;
    } else {
      auto value = it->second;
    }
  }
}

static void BM_UnorderedFindAccessMissing(benchmark::State& state) {
  std::unordered_map<Items, int> m {
    { Items::Zero, 0 }, { Items::One, 1 }, { Items::Two, 2 },
    { Items::Three, 3 }, { Items::Four, 4 },
  };

  for (auto _ : state) {
    auto it = m.find(Items::Five);
    auto b = 1;
    if (it == m.end()) {
      ++b;
    } else {
      auto value = it->second;
    }
  }
}

BENCHMARK(BM_UnorderedMapSquareBracketsAccessValid);
BENCHMARK(BM_UnorderedMapSquareBracketsAccessMissing);
BENCHMARK(BM_UnorderedFindAccessValid);
BENCHMARK(BM_UnorderedFindAccessMissing);
