#include <omp.h>
#include <iostream>
#include <unistd.h> // Для использования функции sleep()

int main() {
    #pragma omp parallel sections
    {
        #pragma omp section
        {
            std::cout << "Задача 1 начата нитью " << omp_get_thread_num() << std::endl;
            sleep(1); // Имитация длительной работы
            std::cout << "Задача 1 завершена нитью " << omp_get_thread_num() << std::endl;
        }

        #pragma omp section
        {
            std::cout << "Задача 2 начата нитью " << omp_get_thread_num() << std::endl;
            sleep(2); // Имитация длительной работы
            std::cout << "Задача 2 завершена нитью " << omp_get_thread_num() << std::endl;

            std::cout << "Задача 3 начата нитью " << omp_get_thread_num() << std::endl;
            sleep(2); // Имитация длительной работы
            std::cout << "Задача 3 завершена нитью " << omp_get_thread_num() << std::endl;
        }

        #pragma omp section
        {
            std::cout << "Задача 4 начата нитью " << omp_get_thread_num() << std::endl;
            sleep(1); // Имитация длительной работы
            std::cout << "Задача 4 завершена нитью " << omp_get_thread_num() << std::endl;
        }
    }
    return 0;
}
