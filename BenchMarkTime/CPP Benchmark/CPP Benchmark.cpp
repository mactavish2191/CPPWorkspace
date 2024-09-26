#include <vector>
#include <iostream>
#include <chrono>
#include <omp.h>

void parallel_sum(std::vector<double> &sum, const std::vector<double> &va, const d::vector<double> &vb);

int main() {
    auto nr_elements = 90'000'000;
    std::vector<double> sum(nr_elements), va(nr_elements, 1.0), vb(nr_elements, 2.0);

    auto start = std::chrono::steady_clock::now();
    parallel_sum(sum, va, vb);
    auto end = std::chrono::steady_clock::now();

    // Print the elapsed time
    auto time_diff = end - start;
    std::cout << std::chrono::duration <double, std::milli> (time_diff).count() << " ms" << std::endl;

    return 0;
}
