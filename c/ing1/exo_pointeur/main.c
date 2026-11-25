#include <stdio.h>

int main() {
    int val1;
  char val2;
    char lettre;
    int *pt1;
   char *pt2;
    char *pt3;
    int **ppt1;
     char **ppt2;
    char **ppt3;
    pt1 = &val1;
    pt2 = &val2;
    pt3 = &lettre;
    ppt1 = &pt1;
    ppt2 = &pt2;
    ppt3 = &pt3;
    val1 = 10;
    val2 = 'A';
    lettre = 'Z';
    printf("Valeurs initiales:\n");
    printf("val1 = %d\n", val1);
    printf("val2 = %c\n", val2);
    printf("lettre = %c\n\n", lettre);
    *pt1 = 20;
    *pt2 = 'B';
    *pt3 = 'Y';
    printf("Valeurs apres modification (1ere indirection):\n");
    printf("val1 = %d\n", val1);
    printf("val2 = %c\n", val2);
    printf("lettre = %c\n\n", lettre);
    **ppt1 = 30;
    **ppt2 = 'C';
    **ppt3 = 'X';
    printf("Valeurs apres modification (2eme indirection):\n");
    printf("val1 = %d\n", val1);
    printf("val2 = %c\n", val2);
    printf("lettre = %c\n", lettre);

    return 0;
}
