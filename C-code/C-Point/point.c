/*************************************************************************
	用变量a给出下面的定义
a) 一个整型数
b)一个指向整型数的指针( A pointer to an integer) 
c)一个指向指针的的指针，它指向的指针是指向一个整型数( A pointer to a pointer to an intege)r 
d)一个有10个整型数的数组( An array of 10 integers) 
e) 一个有10个指针的数组，该指针是指向一个整型数的。(An array of 10 pointers to integers) 
f) 一个指向有10个整型数数组的指针( A pointer to an array of 10 integers)
g) 一个指向函数的指针，该函数有一个整型参数并返回一个整型数(A pointer to a function that takes an integer as an argument and returns an integer) 
h) 一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数( An array of ten pointers to functions that take an integer argument and return an integer )

答案是
a) int a; // 一个整型数 An integer 
b) int *a; // 一个指向整型数的指针 A pointer to an integer 
c) int **a; // 一个指向指针的的指针 A pointer to a pointer to an integer 
d) int a[10]; // 一个有10个整型数的数组 An array of 10 integers 
e) int *a[10]; // 一个有10个指针的数组 An array of 10 pointers to integers 
f) int (*a)[10]; // 一个指向有10个整型数数组的指针 A pointer to an array of 10 integers 
g) int (*a)(int); // 一个指向函数的指针 A pointer to a function a that takes an integer argument and returns an integer 
h) int (*a[10])(int); // 一个有10个指针的数组，指向一个整形函数并有一个整形参数 An array of 10 pointers to functions that take an integer argument and return an integer 
 ************************************************************************/

#include<stdio.h>

int gg(int n){
	printf("%d\n", n);
	return n - 1;
}
int main()
{
    int a;              //一个整型数
    int *b;             //一个指向整型数的指针
    int **c;            //一个指向指针的的指针
    
    int dd[10];          //一个有10个整型数的数组数
    int *e[10];         //一个有指向有10个指针的数组，该指针是指向一个整型数的。
    int (*f)[10];       //一个指向10个整型数数组的指针。
    
    int (*g)(int);      //一个指向函数的指针，该函数有一个整型参数并返回一个整型数
    int (*h[10])(int);  //一个有10个指针的数组，该指针指向一个函数，该函数有一个整型参数并返回一个整型数。

	a = 100;	
	b = &a;
	c = &b;
	printf("%d %d %d\n", a, *b, **c);

	int d[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	f = d;
	int i;
	for (i = 0; i < 10; i++){
		e[i] = &d[i];
		printf("%d ", d[i]);
		printf("%d ", (*f)[i]);	
		printf("%d ", *e[i]);
 	}
	printf("\n");
	
	g = gg;
	printf("%d\n", g(1001));
	h[1] = gg;
	printf("%d\n", h[1](111));

	return 0;	
}
