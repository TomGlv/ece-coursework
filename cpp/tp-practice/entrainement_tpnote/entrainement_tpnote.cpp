#include <stdio.h>
#include <stdlib.h>

void tableau() {
	int tab[10] = { 1,2,3,4,5,6,7,8,9,10 };
	for (int i = 0; i < 10; i++) {
		printf("%d\n", tab[i]);
	}
	tab[4] = 50;

	for (int i = 0; i < 10; i++) {
		printf("%d\n", tab[i]);
	}
}
void xpositif(){
	int x;
	x = 1;
		if (x > 0) {
			printf("mabite");
		}
		else {
			printf("mateub");
			}
}

int main(){
	xpositif();
	return 0;
}