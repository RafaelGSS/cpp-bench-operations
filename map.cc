#include <map>
#include <benchmark/benchmark.h>
#include "./utils.h"

static void BM_MapSquareBracketsAccessValid(benchmark::State& state) {
  std::map<Items, int> m {
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

static void BM_MapSquareBracketsAccessMissing(benchmark::State& state) {
  std::map<Items, int> m {
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

static void BM_MapFindAccessValid(benchmark::State& state) {
  std::map<Items, int> m {
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

static void BM_MapFindAccessMissing(benchmark::State& state) {
  std::map<Items, int> m {
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

BENCHMARK(BM_MapSquareBracketsAccessValid);
BENCHMARK(BM_MapSquareBracketsAccessMissing);
BENCHMARK(BM_MapFindAccessValid);
BENCHMARK(BM_MapFindAccessMissing);
