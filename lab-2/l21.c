#include <math.h>

long double func1(long double x, int n){
	long double num = 2;
	long double predv = 0;
	long double rez = 0;
	long double summ = 1;
	predv = (-1) * pow(x, num) / num; //Первое слагаемое суммы ряда 
	rez = predv;
	while (num <= n){
		summ += rez;
		rez = predv * (-1) * x * (num /(num - 1)) / (num + 1);
		num += 1;
		predv = rez;
	}
	return summ;	
}
