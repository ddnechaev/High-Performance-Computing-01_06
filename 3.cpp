#include <omp.h>
#include <iostream>

int main() {
    // Инициализируем OpenMP, чтобы убедиться, что библиотека корректно настроена
    omp_set_dynamic(0); // Отключаем динамическое регулирование количества нитей
    omp_set_num_threads(omp_get_max_threads()); // Устанавливаем максимальное количество нитей

    // Получаем и выводим максимальное количество нитей
    int max_threads = omp_get_max_threads();
    std::cout << "Максимальное количество нитей: " << max_threads << std::endl;

    return 0;
}
