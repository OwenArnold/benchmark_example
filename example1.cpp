#include <vector>
#include <benchmark/benchmark_api.h>

namespace {
// Example 1.a
void BM_sum_vector(benchmark::State &state){
    while(state.KeepRunning()){
      size_t n = 100;
        std::vector<double> vec(n, 1.0);
        double sum = 0;
        for(auto & item : vec){
            sum += item;
        }
    }
}
BENCHMARK(BM_sum_vector);

// Example 1.b
void BM_sum_vector_with_arg(benchmark::State &state) {
  while (state.KeepRunning()) {
    size_t n = state.range(0);
    std::vector<double> vec(n, 1.0);
    double sum = 0;
    for (auto &item : vec) {
      sum += item;
    }
  }
}
BENCHMARK(BM_sum_vector_with_arg)->Arg(50);

// Example 1.c
void BM_sum_vector_with_range(benchmark::State &state) {
  while (state.KeepRunning()) {
    size_t n = state.range(0);
    std::vector<double> vec(n, 1.0);
    double sum = 0;
    for (auto &item : vec) {
      sum += item;
    }
  }
}
BENCHMARK(BM_sum_vector_with_range)->RangeMultiplier(2)->Range(2, 81);

// Example 1.d
static void BM_square_n_operation(benchmark::State &state) {
  size_t n = state.range(0);
  std::vector<size_t> vec(n, 1);
  while (state.KeepRunning()) {

    size_t total = 0;
    for (size_t j = 0; j < n; ++j) {
      for (size_t i = 0; i < n; ++i) {
        benchmark::DoNotOptimize(total += vec[i]);
      }
    }
  }
  state.SetComplexityN(n);
}
BENCHMARK(BM_square_n_operation)
    ->RangeMultiplier(2)
    ->Range(1 << 8, 1 << 14)
    ->Complexity();
}

BENCHMARK_MAIN()
