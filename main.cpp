#include <iostream>

int main() {
    int n, s = 0;
    printf("%s\n", "Введите количество элементов массива");
    scanf("%d", &n);
    int arr[n];
    int* p = arr;
    printf("%s\n", "Введите элементы массива");
    for (int i = 0; i < n; i++){
        scanf("%d", p);
        p = p + 1;
    }
    p = arr;
    printf("%s\n", "Массив содержит следующие элементы");
    for (int i = 0; i < n; i++){
        s +=  *p;
        printf("%d\t", *p);
        p = p + 1;
    }
    printf("%s\t%d", "Сумма элементов массива", s);
    return 0;
}