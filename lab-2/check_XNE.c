#include <math.h>
#include <stdio.h>

int checkX(long double *x){
	printf("Введите параметр х:\n");
	int cx = scanf("%Lf", &*x);
	if (cx == EOF){
		return 3;
	}
	if (cx == 0){
		while (getchar() != '\n');
		return 1;
	}
	return 0;
}

int checkN(int *n){
	printf("Введите число членов ряда:\n");
	int cn = scanf("%d", &*n);
	if (cn == EOF){
		return 3;
	}
	if (cn == 0){
		while (getchar() != '\n');
		return 1;
	}
	if (*n < 2){
		return 2;
	}
	return 0;
} 

int checkE(long double *e){
	printf("Введите значение точности:\n");
	int ce = scanf("%Lf", &*e);
	if (ce == EOF){
		return 3;
	}
	if (ce == 0){
		while (getchar() != '\n');
		return 1;
	}
	if (*e < 0){
		return 2;
	}
	return 0;
} 
