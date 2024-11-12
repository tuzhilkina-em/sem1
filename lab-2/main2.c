
#include <stdio.h>
#include "l21.h"
#include <math.h>

int main(){
	printf("Вариант №62: Вычислить значение функции в точке при помощи разложения в ряд\n");
	long double x = 0;
	long double  e = 0;
	int check = 0; 
	long double end = 0;
	while (1){
		check = checkX(&x);
		if (check == 3){
			printf("Ввод прерван\n");
			return 0;
		}
		if (check == 1){
			printf("Некорректный ввод\n");
		}
		if (check == 0){
			break;
		}
	}
	while (1){
			check = checkE(&e);
			if (check == 3){
				printf("Ввод прерван\n");
				return 0;
			}
			if (check == 1){
				printf("Некорректный ввод\n");
			}
			if (check == 0){
				break;
			}
			if (check == 0){
				printf("Точность не может быть меньше или равна 0\n");
			}
	}
	int len = (-1) * log10(e);
	long double real = (1 + x) * expl(-x);
	printf("Сумма членов ряда равна    %.*Lf\n", len, func2(x, e, &end));
	printf("Число членов ряда %.0Lf\n", end);
	printf("Реальное значение функции: %.20Lf\n", real);
	printf("Погрешность равна:         %.20Lf\n", real - func2(x, e, &end));
	return 0;
}
