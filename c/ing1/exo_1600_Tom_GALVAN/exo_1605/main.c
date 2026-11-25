#include <stdio.h>
int P(int i, int y) {
    int res;
    if (y == 0) {
        res = 1;
    } else {
        res = i * P(i, y - 1);
    }
    return res;
}
int main() {
    int i, y;
    printf("Entrer nombre et puissance : ");
    scanf("%d %d", &i, &y);
    int resu = P(i, y);
    printf("Le resultat de %d a la puissance %d est : %d\n", i, y, resu);
    return 0;
}