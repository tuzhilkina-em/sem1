#include "functions.h"

int* inicialization(int n){						//Функция выделения памяти для массива длиной n


	int *mas = (int*)calloc(n*sizeof(int));		//Работа с памятью

	if(mas == NULL){							//Проверка памяти(создан ли массив)
		return NULL;
	}


	return mas;
}

int getinput(int *n){
	int check = 0;
	int elem = 0;

	check = scanf("%d", &elem);					//Ввод длины массива

	if (check == 0){		
		while (getchar() != '\n');
		return 1;
	}
	if (check == EOF){
		return 2;
	}

	*n = elem; 
	return 0;		
}

int dialogue(int *mas, int n){		//Диалоговая функция ввода элементов массива 
	int check = 0;
	int s = 0;						//Переменная ввода элемента массива

	for(int i = 0; i < n; i++){		//Цикл заполнения массива
		printf("Введите %d элемент массива\n", i);
		check = getinput(&s);	//Ввод значений масива

		if (check == 1){
			i--;
			continue;
		}
		if (check == 2){
			return 2;;
		}

		mas[i] = s;
	
	}
	
	return 0;
}


int add(int n, int **mas, int k, int new){						//Функция добавлеиния элемента в массив
	int *newmas = (int*)realloc(*mas, (n + 1) * sizeof(int));	//Увеличение памяти массива для добавляемого элемента
	*mas = newmas;

	if (k >= n){												//Если индекс добавляемого элемента больше длины массива - добаляем элемент на последнюю позицию в массиве
		(*mas)[n] = new;
		return 0;
	}

	for(int i = n; i > k; i--){									//Цикл сдвига элементов
		(*mas)[i] = (*mas)[i - 1];
	}
	(*mas)[k - 1]  = new;										//присвоение к-му элементу новое значение
	return 0;	
}


int del(int n, int **mas, int k){								//Функция удаления элемента по индексу
	for(int i = k; i < n; i++){									//
		(*mas)[i] = (*mas)[i + 1];
		}

	int *newmas = (int*)realloc(*mas, (n - 1) * sizeof(int));	//Уменьшение объема используемой памяти при удалении элемента 
	*mas = newmas;
	return 0;
}

int indtask(int diap0, int diap1, int **mas, int *n, int **newmas, int *len){	//Индивидуальное задание 
	int count = -1;

	for(int i = 0; i < *n; i++){

		count++;
		if (((*mas)[i] >= diap0)&&((*mas)[i] <= diap1)){
			add(*len, &*newmas,  *len, count);
			*len += 1;
			del(*n, &*mas, i);
			*n -= 1;
			i--;
		}
	}
	return 0;
}

int print(int *mas, int n){
	for(int i = 0; i < n; i++){
		printf("%d ", mas[i]);
	}
	printf("\n");
	return 0;
}
