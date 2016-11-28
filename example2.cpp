#include <benchmark/benchmark_api.h>
#include <iostream>
namespace {

// Example 2.a
class MyBenchmark : public benchmark::Fixture {
private:
  std::vector<double> m_buffer;

public:
  MyBenchmark() : benchmark::Fixture(), m_buffer(10000, 1.0) {}

  virtual void SetUp(benchmark::State &) override {}

  virtual void TearDown(benchmark::State &) override {}

  void do_time_only_computation(benchmark::State &state) {
    while (state.KeepRunning()) {
      double sum = 0;
      for (auto &item : m_buffer) {
        benchmark::DoNotOptimize(sum += item);
      }
    }
  }

  virtual ~MyBenchmark() {}
};
BENCHMARK_F(MyBenchmark, BM_time_only_computation)(benchmark::State &state) {
  do_time_only_computation(state);
}

void sum_over_vector(benchmark::State &state) {
  while (state.KeepRunning()) {
    double sum = 0;
    std::vector<double> buffer;
    for (auto &item : buffer) {
      benchmark::DoNotOptimize(sum += item);
    }
  }
}

// Example 2.b
void BM_with_frequency(benchmark::State &state) {

  sum_over_vector(state);
  // Indicate how many items have been processed to get the frequency
  state.SetItemsProcessed(state.iterations() * 1);
}
BENCHMARK(BM_with_frequency);

// Example 2.a
void BM_with_repetitions(benchmark::State &state) { sum_over_vector(state); }
BENCHMARK(BM_with_repetitions)->Repetitions(6)->ReportAggregatesOnly(true);
}
