#include <map>
#include <unordered_map>
#include <benchmark/benchmark.h>

enum class Items {
  Zero = 0,
  One,
  Two,
  Three,
  Four,
  Five
};

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

// Register the function as a benchmark
BENCHMARK(BM_MapSquareBracketsAccessValid);
BENCHMARK(BM_MapSquareBracketsAccessMissing);
BENCHMARK(BM_MapFindAccessValid);
BENCHMARK(BM_MapFindAccessMissing);

BENCHMARK(BM_UnorderedMapSquareBracketsAccessValid);
BENCHMARK(BM_UnorderedMapSquareBracketsAccessMissing);
BENCHMARK(BM_UnorderedFindAccessValid);
BENCHMARK(BM_UnorderedFindAccessMissing);

BENCHMARK_MAIN();
