#include <math.h>
#include <stdio.h>
long double func2(long double x, long double e, long double *end){
	long double num = 2;
	long double predv = 0;
	long double rez = 0;
	long double summ = 1;
	predv = (-1) * pow(x, num) / num; //Первое слагаемое суммы ряда 
	rez = predv;
	while (fabsl(rez) > e){
		summ += rez;
		rez = predv * (-1) * x * (num /(num - 1)) / (num + 1);
		num += 1;
		predv = rez;
	}
	*end = num;
	return summ;	
}
