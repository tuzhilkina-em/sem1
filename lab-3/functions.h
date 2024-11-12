#ifndef FUNCTIONS_H
#define FUNCTIONS_H
#include <stdio.h>
#include <stdlib.h>
int* inicialization(int n);
int add(int n, int **mas, int k, int new);
int del(int n, int **mas, int k);
int indtask(int diap0, int diap1, int **mas, int *n, int **newmas, int *len);
int print(int *mas, int n);
int dialogue(int *mas, int n);
int getinput(int *n);
#endif 
