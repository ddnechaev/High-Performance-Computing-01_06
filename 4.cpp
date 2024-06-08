//При помощи трёх уровней вложенных параллельных областей породите 8
// нитей (на каждом уровне параллельную область должны исполнять 2 нити).
// Посмотрите, как будет исполняться программа, если запретить вложенные параллельные области.
#include <omp.h>
#include <iostream>

int main() {
    // Установим количество нитей для каждой параллельной области
    omp_set_num_threads(2);
    // Включим вложенную параллельность
    omp_set_nested(1);
    // Включим максимальный уровень вложенности
    omp_set_max_active_levels(3);

    #pragma omp parallel
    {
        int level1 = omp_get_thread_num();
        #pragma omp parallel
        {
            int level2 = omp_get_thread_num();
            #pragma omp parallel
            {
                int level3 = omp_get_thread_num();
                printf("Уровень 1: Нить %d, Уровень 2: Нить %d, Уровень 3: Нить %d\n",
                       level1, level2, level3);
            }
        }
    }
    return 0;
}
