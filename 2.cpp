#include <vector>
#include <iostream>
#include <omp.h>

int main() {
    int n = 50000000;
    std::vector<float> vec1(n), vec2(n), result(n);

    // Инициализация векторов случайными значениями
    #pragma omp parallel for
    for (int i = 0; i < n; ++i) {
        vec1[i] = static_cast<float>(rand()) / RAND_MAX;
        vec2[i] = static_cast<float>(rand()) / RAND_MAX;
    }

    double start_time = omp_get_wtime();

    // Сложение векторов с использованием shared
    #pragma omp parallel shared(vec1, vec2, result)
    {
        #pragma omp for
        for (int i = 0; i < n; ++i) {
            result[i] = vec1[i] + vec2[i];
        }
    }

    double end_time = omp_get_wtime();

    std::cout << "Время выполнения: " << (end_time - start_time) << " секунд" << std::endl;
    std::cout << "Размер результата: " << result.size() << std::endl;
    std::cout << "Первый элемент результата: " << result[0] << std::endl;

    return 0;
}
