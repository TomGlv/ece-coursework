#include <stdio.h>
void permut (float* x, float *y) {
    float temp;
    temp=*x;
    *x=*y;
    *y=temp;
    printf("dans permut : x=%f y=%f\n",*x,*y);}
int main() {
    float x, y;
    printf("saisir deux reels: ");
    scanf("%f %f", &x, &y);
    permut(&x, &y);
    printf("dans le main apres permut : x=%f y=%f\n", x, y);
    return 0;
}