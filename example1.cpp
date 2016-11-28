
#include <vector>
#include <iostream>
#include <benchmark/benchmark_api.h>

void BM_sum_vector(benchmark::State &state){
    while(state.KeepRunning()){
        size_t n = state.range(0);
        std::vector<double> vec(n, 1.0);
        double sum = 0;
        for(auto & item : vec){
            sum += item;
        }
    }
}
BENCHMARK(BM_sum_vector)->RangeMultiplier(2)->Range(2, 81);


static void BM_memcpy(benchmark::State &state) {
  char *src = new char[state.range(0)];
  char *dst = new char[state.range(0)];
  memset(src, 'x', state.range(0));
  while (state.KeepRunning())
    memcpy(dst, src, state.range(0));
  state.SetBytesProcessed(int64_t(state.iterations()) *
                          int64_t(state.range(0)));
  delete[] src;
  delete[] dst;
}
 BENCHMARK(BM_memcpy)->Arg(8)->Arg(64)->Arg(512)->Arg(1 << 10)->Arg(8 << 10);

static void square_n_operation(benchmark::State &state) {
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


BENCHMARK(square_n_operation)
    ->RangeMultiplier(2)
    ->Range(1 << 8, 1 << 14)
    ->Complexity();

BENCHMARK_MAIN()
