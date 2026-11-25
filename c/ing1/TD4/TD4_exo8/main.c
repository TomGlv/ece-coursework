#include <stdio.h>
int f(int n){
    int u0,u1,un,i;
    u0=0;
    u1=1;
    for (i=0;i<=n-2;i++){
        un = u0 + u1;
        u0 = u1;
        u1=un;
    }
    return un;
}
int main() {
    int n,z;
    do {
        printf("saisir un entier positif");
        scanf("%d",&n);
    }while (n<=1);
    z= f(n);
    printf("suite fibonnaci : u%d = %d",n,z);
    return 0;
}