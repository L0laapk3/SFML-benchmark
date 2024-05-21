#include <SFML/Graphics/Transform.hpp>
#include <benchmark/benchmark.h>
#include <random>
#include <vector>
#include "xoshiro256ss.h"


static xoshiro256ss g;
static std::uniform_real_distribution<float> dist( -1E6f, 1E6f );

static sf::Transform randTransf() {
#ifdef FASTER_TRANSFORM
	return { dist(g), dist(g), dist(g), dist(g), dist(g), dist(g) };
#else
	return { dist(g), dist(g), dist(g), dist(g), dist(g), dist(g), dist(g), dist(g), dist(g) };
#endif
}



static void BM_transform_combine(benchmark::State& state) {
	auto inputA = randTransf(), inputB = randTransf();
	sf::Transform output;

	for (auto _ : state)
		benchmark::DoNotOptimize(output = inputA.combine(inputB));

	state.SetItemsProcessed(state.iterations());
}
BENCHMARK(BM_transform_combine)->MinTime(4);

static void BM_transform_getInverse(benchmark::State& state) {
	auto inputA = randTransf();
	sf::Transform output;

	for (auto _ : state)
		benchmark::DoNotOptimize(output = inputA.getInverse());

	state.SetItemsProcessed(state.iterations());
}
BENCHMARK(BM_transform_getInverse)->MinTime(4);

static void BM_transform_translate(benchmark::State& state) {
	auto inputA = randTransf();
	auto inputB = sf::Vector2f{ dist(g), dist(g) };
	sf::Transform output;

	for (auto _ : state)
		benchmark::DoNotOptimize(output = inputA.translate(inputB));

	state.SetItemsProcessed(state.iterations());
}
BENCHMARK(BM_transform_translate)->MinTime(4);

static void BM_transform_rotate(benchmark::State& state) {
	auto inputA = randTransf();
	auto inputB = sf::radians(dist(g));
	sf::Transform output;

	for (auto _ : state)
		benchmark::DoNotOptimize(output = inputA.rotate(inputB));

	state.SetItemsProcessed(state.iterations());
}
BENCHMARK(BM_transform_rotate)->MinTime(4);

static void BM_transform_scale(benchmark::State& state) {
	auto inputA = randTransf();
	auto inputB = sf::Vector2f{ dist(g), dist(g) };
	sf::Transform output;

	for (auto _ : state)
		benchmark::DoNotOptimize(output = inputA.scale(inputB));

	state.SetItemsProcessed(state.iterations());
}
BENCHMARK(BM_transform_scale)->MinTime(4);


BENCHMARK_MAIN();