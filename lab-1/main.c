#include <stdio.h>
#include "l11.h"
#include "l12.h"

int main(){
	int vvd = 0;
	printf("Введите число в десятичной системе счисления vvd: " );
	scanf("%d", &vvd);
	int arc = conversion_to_binary(vvd);
	int rez = reverse(arc);
	printf("Значение vvd в двоичной системе равно: %d\n", rez);
	return 0;
}
