#include <stdio.h>

int main() {
    int i,val1,l,L,I,h,X,k,b,e,j;
    printf("\t\n1:rectangle\t\n2:triangle\t\n3:losange\t\n4:sapin\t\n5:sablier \t\n6:x \t\n7:z",&val1);
    scanf("%d",&val1);
    switch (val1) {
        case 1 ://dans le cas ou la variable vaut 1
            printf("choisir longueur et largeur du rectangle");
            scanf("%d %d", &L, &l);
            printf("\n");
            for (i = 1; i <= L; i++) {
                for (I = 1; I <= l; I++) {
                    printf("*");
                }
                printf("\n");
            }
            break;
        case 2 ://dans le cas ou la variable vaut 2
            printf("rentrez la hauteur h\n");
            scanf("%d", &h);
            l = h * 2 - 1;
            X = 1;
            for (i = 0; i < h; i++) {
                for (I = -1; I < (l / 2 - i); I++) {
                    printf(" ");
                };
                for (k = 0; k < X; k++) {
                    printf("*");
                };
                printf("\n");
                X += 2;
            };
        break;
        case 3 :
            printf ("rentrer la hauteur h\n");
            scanf("%d", &h);
            l = h * 2 - 1;
            X = 1;
            for (i = 0; i < h; i++) {
                for (I = 0; I < (l/2- i); I++) {
                    printf(" ");
                };
                for (k = 0; k < X; k++) {
                    printf("*");
                };
                printf("\n");
                X += 2;
            };
            X = h;
            for (i = h; i > 0; i--) {
                for (I = 0; I < (h - i); I++) {
                    printf(" ");
                };
                for (k = l; k>0; k--) {
                    printf("*");
                }
                printf("\n");
                l-=2;
            }
            break;
        case 4 :
            printf("rentrez la hauteur h\n");
            scanf("%d", &h);
            l = h * 2 - 1;
            X = 1;
            for (i = 0; i < h; i++) {
                printf("\t");
                for (I = 0; I < (l / 2 - i); I++) {
                    printf(" ");
                };
                for (k = 0; k < X; k++) {
                    printf("*");
                };
                printf("\n");
                X += 2;
            }
            l = h * 2 - 1;
            X = 2;
            for (i = 0; i < h; i++) {
                printf("\t");
                for (I = 0; I < (l / 2 - i); I++) {
                    printf(" ");
                };
                for (k = 0; k < X; k++) {
                    printf("*");
                };
                for (I = 0; I < (l / 2 - i); I++) {
                    printf(" ");
                };
                printf("\n");
                X += 3;
                printf(" ");
                scanf("%d %d", &L, &val1);
                printf("\n");
                for (i = 1; i <= val1; i++) {
                    for (I = 1; I <= l; I++) {
                        printf("*");
                    }
                    printf("\n");
            }
            break;
        case 5 :
            printf ("rentrer la hauteur h\n");
            scanf("%d", &h);
            l = h * 2 - 1;
            X = h;
            for (i = h; i > 0; i--) {
                for (I = 0; I < (h - i); I++) {
                    printf(" ");
                };
                for (k = l; k>0; k--) {
                    printf("*");
                }
                printf("\n");
                l-=2;
            }
            l = h * 2 - 1;
            X =1;
            for (i = 0; i < h; i++) {
                for (I = 0; I < (l/2- i); I++) {
                    printf(" ");
                };
                for (k = 0; k < X; k++) {
                    printf("*");
                };
                printf("\n");
                X += 2;
            };
            break;
            case 6:
                printf("rentrez la hauteur h\n");
                scanf("%d",&h);
                b=0;
                e=h;
                for(i=0;i<h;i++){
                    for(j=1;j<h;j++){
                        if(j==b || j==e)
                            printf("*");
                        else printf(" ");
                    };
                    printf("\n");
                    e-=1;
                    b+=1;
                }
            case 7 ://dans le cas ou la variable vaut 1
            printf("choisir longueur et hauteur du Z");
            scanf("%d %d", &L, &h);
            for (I = h; I < 8; I++)
                printf(" ");
            for (i = 0; i < L; i++)
                printf("*");
            h = h-2;
            l = h * 2 - 1;
            X = 1;
            for (i = 0; i < h; i++) {
                printf("\n");
                for (I = 0; I <= (l / 2 - i); I++) {
                    printf(" ");
                };
                printf("*");
            };
            printf("\n");
            X += 2;
            for (i = 0; i < L; i++)
                printf("*");
            break;
            default : printf("Choisis une des options proposees !");
    }
    return 0;
}
}