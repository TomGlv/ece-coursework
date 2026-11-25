#include <stdio.h>
void f(int *pa, int *pb)
{
    *pa = (*pa)*(*pa);
    *pb = (*pb)*(*pb);
    printf("%d %d",*pa,*pb);
}

int main(void) {
    int a,b;
    printf("saisir 2 entiers : ");
    scanf("%d %d",&a,&b);
    int *pa =&a;
    int *pb = &b;
    f(&a,&b);
    return 0;
}
