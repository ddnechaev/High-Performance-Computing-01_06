#include <omp.h>
#include <iostream>

int main() {
    const int n = 4;
    const int m = 4;

    // Устанавливаем количество нитей
    omp_set_num_threads(4);

    #pragma omp parallel
    {
        // Используем 'for' с опцией 'collapse' для двух циклов
        #pragma omp for collapse(2)
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int thread_id = omp_get_thread_num();
                printf("Итерация (i=%d, j=%d) выполнена нитью %d\n", i, j, thread_id);
            }
        }
    }

    return 0;
}
