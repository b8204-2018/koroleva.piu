#include <iostream>
#include "func.h"

    int main() {
        int t, mark = 0;
        printf("Введите количество попыток\n");
        scanf("%d\n", &t);
        for (int i = 0; i < t; i++){
            static float x, y;
            scanf("%f\t%f", &x, &y);
            mark += hit(x, y);
        }
        printf("Ваш результат\n");
        printf("%d\n", mark);
        return 0;
}