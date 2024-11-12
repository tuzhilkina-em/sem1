#include "functions.h"

int main(){
	int n = 0; 			//Длина массива
	int k = 0;			//Индекс вызываемого элемента
	int new = 0;		//Значение нового элемента для функции add
	int s =  0;			//Переменная выбора команды
	int diap0 = 0;		//Начальное значение диапазона для таска
	int diap1 = 0;		//Конечное значение диапазона для таска
	int check = 0;		//Для проверки корректности ввода



    while(1){

		printf("Введите количество элементов массива \n");
   	    check = getinput(&n);
   	    
    	if (check == 1){
    		printf("Некорректный ввод \n");
    		continue;
    	}
		if (n <=  0){
    		printf("Некорректный ввод \n");
			continue;
		}
    	if (check == 2){
    		printf("Ввод прерван \n");
    		return 0;
    	}
    	break;
    }
    
	int *mas = inicialization(n);								//Инициализация массива без диалога, то есть создание массива длины n, заполненного нулями
    print(mas, n);													//Вызов функции вывода массива

	while(1){
		printf("Введите команду \n");
		printf(" 1 - Инициализация массива \n");
		printf(" 2 - Добавление нового элемента в массив \n");
		printf(" 3 - Удаление элемента из массива \n");
		printf(" 4 - Выполнение индивидуального задания \n");
		printf(" 5 - Вывод текущего массива \n ");


		check = scanf("%d", &s);								

		if (check == EOF){					//Выход при прерывании ввода 
			printf("Ввод прерван\n");
			break;
		}								

		switch(s){

			case(1):						//Инициализация массива 


			    while(1){
					printf("Введите количесво элемнетов массива \n");
			   	    check = getinput(&n);
			   	    
			    	if (check == 1){
			    		printf("Некорректный ввод \n");
			    		continue;
			    	}
					if (n <=  0){
			    		printf("Некорректный ввод \n");
						continue;
					}
			    	if (check == 2){
			    		printf("Ввод прерван \n");
						free(mas);
			    		return 0;
			    	}
			    	break;
			    }

				free(mas);					//Очищение текущего массивa	
				mas = inicialization(n);	//Вызов функции для повторной инициализации
				
				check = dialogue(mas, n);
				if (check == 2){
					free(mas);
					return 0;
				}
				break;
				
			case(2):

				while(1){ 			// Проверка введенного индекса

					printf("Введите индекс добавляемого элемента \n");
					check = getinput(&k);

					if (k < 0){
						printf("Некорректный ввод \n");
						continue;
					}
					if (check == 1){
						printf("Некорректный ввод \n");
						continue;
					}
					if (check == 2){
						printf("Ввод прерван \n");
						free(mas);
						return 0;
					}
					break;	
				}//while check case21

				while(1){ 			// Проверка введенного индекса

					printf("Введите значение нового элемента\n");
					check = getinput(&new);

					if (check == 1){
						printf("Некорректный ввод \n");
						continue;
					}
					if (check == 2){
						printf("Ввод прерван \n");
						free(mas);
						return 0;
					}
					break;
				}//while case22	

				
				add(n, &mas, k, new);
				n++;
				break;

			case(3): 									//Удаление элемента 

				while(1){

					printf("Введите индекс удаляемого элемента \n");

					check = getinput(&k);				 //Ввод индекса удаляемого элемнета с последующей проверкой

					if (k < 0){
						printf("Некорректный ввод \n");
						continue;
					}
					if (k > n){
						printf("Индекс не существует \n");
						continue;
					}

					if (check == 1){
						printf("Некорректный ввод \n");
						continue;
					}
					if (check == 2){
						printf("Ввод прерван \n");
						free(mas);
						return 0;
					}
					break;
				}//while case 31

				
				del(n, &mas, k);			//Вызов функции для удаления элемента из массива по индексу 
				n--;
				break;


			case(4):  //Индивидуалье задание 

				printf("Вариант №84 В исходной последовательности найти все числа, лежащие в заданном диапазоне значений. \n");
				printf("Сформировать новую последовательность из их номеров в исходной последовательности. Удалить обнаруженные числа в исходной последовательности. \n");

				while(1){ 			

					printf("Введите начальное значение диапазона \n");

					check = getinput(&diap0);		//Ввод начального значения диапазона с последующей проверкой

					if (check == 1){
						printf("Некорректный ввод \n");
						continue;
					}
					if (check == 2){
						printf("Ввод прерван \n");
						free(mas);
						return 0;
					}
					break;
				}//while case41	

				while(1){ 			

					printf("Введите конечное значение диапазона \n");

					check = getinput(&diap1);		//Ввод конечного значения диапазона с последующей проверкой

					if (diap1 < diap0){
						printf("Неверный диапазон значений: Конечное значение diap1 не может быть меньше начального diap0 \n ");
						continue;
					}

					if (check == 1){
						printf("Некорректный ввод \n");
						continue;
					}
					if (check == 2){
						printf("Ввод прерван \n");
						free(mas);
						return 0;
					}
					break;
				}//while case42


				int *newmas = NULL;
				int newn = 0;		 //Длина нового массива 

				indtask(diap0, diap1, &mas, &n, &newmas, &newn);
				

			

				print(mas, n);
				print(newmas, newn);
				free(newmas);
				break;


			case(5):
				print(mas, n);
				continue;


			default:
				printf("Некорректный ввод, выберете команду из списка:\n");

		}//к switch		
	print(mas, n);	
	}//while	
	free(mas);
	return 0;
}//main
