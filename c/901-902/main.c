#include <stdio.h>

void exercice901() {
    int *pt;
    int val1, val2, val3;

    val1 = 10;
    val2 = 20;
    val3 = 1;

    pt = &val1;
    *pt = 100;

    printf("pt: %p\n", (void *)pt);
    printf("&pt: %p\n", (void *)&pt);
    printf("*pt: %d\n", *pt);

    printf("\nOperations:\n");
    printf("*pt + 3: %d\n", *pt + 3);
    printf("pt + 2: %p\n", (void *)(pt + 2));
    *pt += 5;
    printf("*pt += 5: %d\n", *pt);
    (*pt)++;
    printf("(*pt)++: %d\n", *pt);
    ++*pt;
    printf("++*pt: %d\n", *pt);
    *(pt + 2)++; // This is undefined behavior since pt + 2 does not point to a valid address.
    printf("*(pt + 2)++: Undefined Behavior\n");
    *pt += val3;
    printf("*pt += val3: %d\n", *pt);
    *pt = *pt + val3;
    printf("*pt = *pt + val3: %d\n", *pt);
    printf("*(pt + val3): Undefined Behavior\n");
}

void exercice902() {
    int val1;
    unsigned char val2;
    char lettre;

    int *pt1 = &val1;
    unsigned char *pt2 = &val2;
    char *pt3 = &lettre;

    int **ppt1 = &pt1;
    unsigned char **ppt2 = &pt2;
    char **ppt3 = &pt3;

    val1 = 42;
    val2 = 255;
    lettre = 'A';

    printf("Initial values:\n");
    printf("val1: %d, val2: %u, lettre: %c\n", val1, val2, lettre);

    *pt1 = 100;
    *pt2 = 200;
    *pt3 = 'B';

    printf("\nAfter first indirection:\n");
    printf("val1: %d, val2: %u, lettre: %c\n", val1, val2, lettre);

    **ppt1 = 500;
    **ppt2 = 128;
    **ppt3 = 'C';

    printf("\nAfter second indirection:\n");
    printf("val1: %d, val2: %u, lettre: %c\n", val1, val2, lettre);
}

int main() {
    int choix;

    printf("Choisissez l'exercice (901 ou 902): ");
    scanf("%d", &choix);

    switch (choix) {
        case 901:
            exercice901();
            break;
        case 902:
            exercice902();
            break;
        default:
            printf("Exercice inconnu.\n");
    }

    return 0;
}
