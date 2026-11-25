#include <stdio.h>

void f(){
    int x;
    printf("%d",x);
}
int main() {
    int x;
    printf("saisir un entier : \n");
    scanf ("%d",&x);
    f();
    return 0;
}
