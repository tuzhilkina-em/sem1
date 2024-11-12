#include <stdio.h>
#include "l21.h"
#include <math.h>


int main(){
	printf("Вариант №62: Вычислить значение функции в точке при помощи разложения в ряд\n");
	long double x = 0;
	int n = 0;
	int check = 0; 
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
			check = checkN(&n);
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
			if (check == 2){
				printf("Число членов ряда должно быть не меньше 2\n");
			}
	}
	long double real = (1 + x) * expl(-x);
	printf("Сумма членов ряда равна    %.20Lf\n", func1(x, n));
	printf("Реальное значение функции: %.20Lf\n", real);
	printf("Погрешность равна:         %.20Lf\n", real - func1(x, n));
	return 0;
}
