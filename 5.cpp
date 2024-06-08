//Написать пример реализации директивы For с опцией nowait, проиллюстрировать
// работу (печатать номер текущей #include <omp.h>
#include <iostream>

int main() {
    // Устанавливаем количество нитей
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        // Используем 'for' с опцией 'nowait'
        #pragma omp for nowait
        for (int i = 0; i < 10; i++) {
            int thread_id = omp_get_thread_num();
            printf("Итерация %d выполнена нитью %d\n", i, thread_id);
        }

        // Дополнительная работа, которая выполняется без ожидания завершения цикла 'for'
        #pragma omp single
        {
            printf("Эта часть кода выполняется нитью %d, без ожидания завершения предыдущего цикла 'for'.\n", omp_get_thread_num());
        }
    }

    return 0;
}
итерации и номер потока, выполнившего свою часть цикла).