#include <stdio.h>
#include <unistd.h>
void heure(int *pa,int *pb)
{
    int i,I;
    *pa=-1;
    *pb=-1;
    for (i=0;i<=23;i++) {
        *pa=*pa+1;
        for (I=0;I<60;I++){
        printf(" %dl:",*pa);
        if (*pb==59)
            *pb=0;
        else
            *pb=*pb+1;
        printf("%d\n",*pb);
        sleep(1);
        }
}}
int main() {
    int a,b;
    heure(&a,&b);
    return 0;
}