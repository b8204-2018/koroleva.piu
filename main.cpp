#include <iostream>

int main() {

int a, b;
scanf("%d\t%d", &a, &b);
int *p1 = &a, *p2 = &b;
*p1 = *p1 + *p2;
*p2 = -(*p2 - *p1);
*p1 = *p1 - *p2;
printf("%d\t%d", a, b);

return 0;
}
