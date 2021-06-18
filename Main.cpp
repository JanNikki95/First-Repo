#include <thread>
#include <vector>
#include <iostream>
#include "Timer.h"
#include <immintrin.h>
#include <thread>

using namespace std;

using std::chrono::high_resolution_clock;
using std::chrono::duration_cast;
using std::chrono::duration;
using std::chrono::milliseconds;


void packadd(float a[8], float b[8], float c[8]) {
		
	__m256 pa = _mm256_load_ps(a);
	__m256 pb = _mm256_load_ps(b);

	__m256 tmp = _mm256_add_ps(pa, pb);

	_mm256_store_ps(c, tmp);
}

int fib(int i) {
	if (i == 0) return 0;
	if (i == 1) return 1;
	return fib(i - 1) + fib(i - 2);
}
constexpr float float_true = std::bit_cast<float>(-1);

#define Iterations 10

int main(int argc, char* argv[]) {

	/*std::chrono::duration<double> timer = std::chrono::milliseconds(0);
	for (uint64_t i = 0; i < Iterations; ++i) {
		std::chrono::time_point<std::chrono::system_clock> a = std::chrono::system_clock::now();
		std::this_thread::sleep_for(20ms);
		std::chrono::time_point<std::chrono::system_clock> b = std::chrono::system_clock::now();
		timer += b - a;
	}
	auto mu_double = duration_cast<std::chrono::milliseconds>(timer);
	std::cout << "elapsed time (" << "Test" << "): "
		<< mu_double.count() / (double)(Iterations) << "ms" << std::endl;*/

	int counter = 0;
	auto duration = 2s;
	std::chrono::time_point<std::chrono::system_clock> start = std::chrono::system_clock::now();
	do {
		std::this_thread::sleep_for(1ms);
		++counter;
	} while ((std::chrono::system_clock::now() - start) < duration);
	
	cout << "Counter: " << counter << '\n';

	cin.get();
}