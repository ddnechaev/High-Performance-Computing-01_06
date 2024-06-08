#include <omp.h>
#include <iostream>

int main() {
    int sum = 0;
    const int n = 100;

    #pragma omp parallel for reduction(+:sum)
    for (int i = 1; i <= n; i++) {
        sum += i;
        int thread_id = omp_get_thread_num();
        printf("Нить %d добавляет %d, промежуточная сумма = %d\n", thread_id, i, sum);
    }

    std::cout << "Итоговая сумма чисел от 1 до 100: " << sum << std::endl;

    return 0;
}
