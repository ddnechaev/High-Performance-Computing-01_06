//Выполнить сложение двух векторов, содержащих от 50 млн. вещественных значений
// (предварительно заполнить векторы случайными значениями, предусмотреть выделение и
//  освобождение областей памяти для векторов с помощью функций стандартной библиотеки С++).
//  Вычислить и вывести на экран время выполнения сложения, с использованием функций библиотеки OpenMP.
// Вывести на экран размер и любой элемент результирующего вектора.

#include <iostream>
#include <omp.h>
#include <cstdlib>

int main() {
    const size_t N = 50000000; // Размер векторов
    double *a = new double[N];
    double *b = new double[N];
    double *c = new double[N];

    // Заполнение векторов случайными значениями
    #pragma omp parallel for
    for (size_t i = 0; i < N; ++i) {
        a[i] = rand() / (double)RAND_MAX;
        b[i] = rand() / (double)RAND_MAX;
    }

    double start_time = omp_get_wtime(); // Начало отсчёта времени

    // Сложение векторов
    #pragma omp parallel for
    for (size_t i = 0; i < N; ++i) {
        c[i] = a[i] + b[i];
    }

    double end_time = omp_get_wtime(); // Конец отсчёта времени

    std::cout << "Время выполнения: " << (end_time - start_time) << " секунд" << std::endl;
    std::cout << "Размер результирующего вектора: " << N << std::endl;
    std::cout << "Элемент результирующего вектора (c[0]): " << c[0] << std::endl;

    // Освобождение памяти
    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}

