/*
	Assigned by:
	Sagiv Yahav - 322807033
	Student2_Full_Name #ID
*/

#define _CRT_SECURE_NO_WARNINGS

/* Libraries */

#include <stdio.h>
#include <malloc.h>
#include <math.h>

/* Constant definitions */

#define N 3
#define ROWS 4
#define COLS 5

/* Type definitions */

typedef struct number
{
	unsigned long long num;
	int sum;
} Number;

typedef struct triad
{
	int i, j, value;
} Triad;

typedef struct item
{
	Triad data;
	struct item* next;
} Item;

/* Function declarations */

void Ex1();
void Ex2();
void Ex3();

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size);
int** matrixMaxNeighbor(int A[][COLS], int rows, int cols);
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2);

/* Declarations of auxiliary functions */

int isPrime(int num);
int digitSum(unsigned long long num);

int neighborMax(int A[][COLS], int rows, int cols, int i, int j);
int** allocMatrix(int rows, int cols);

Triad createThree(int i, int j, int value);
// insert - to declare the function yourself

void printArray(Number* arr, int size);
void inputMatrix(int A[][COLS], int rows, int cols);
void printMatrix(int A[][COLS], int rows, int cols);
void printDynamicMatrix(int** A, int rows, int cols);
void freeMatrix(void** A, int rows);
void inputDynamicMatrix(int** A, int rows, int cols);
void printList(Item* lst);
void freeList(Item* lst);

/* ------------------------------- */

int main()
{
	int select = 0, i, all_Ex_in_loop = 0;
	printf("Run menu once or cyclically?\n(Once - enter 0, cyclically - enter other number) ");
	if (scanf("%d", &all_Ex_in_loop) == 1)
		do
		{
			for (i = 1; i <= N; i++)
				printf("Ex%d--->%d\n", i, i);
			printf("EXIT-->0\n");
			do {
				select = 0;
				printf("please select 0-%d : ", N);
				scanf("%d", &select);
			} while ((select < 0) || (select > N));
			switch (select)
			{
			case 1: Ex1(); break;
			case 2: Ex2(); break;
			case 3: Ex3(); break;
			}
		} while (all_Ex_in_loop && select);
	return 0;
}


/* Function definitions */

void Ex1()
{

	int n1, n2;
	printf("Please enter a minimum number and a maximum number:\n");
	printf("n1 =");
	scanf_s("%d", &n1);
	printf("\nn2 = ");
	scanf_s("%d", &n2);
	int p_size = n2 - n1;

	Number* result = primeSums(n1, n2, &p_size);
	printf("There are %d numbers whice their digit's sum is a prime number! \n", p_size);
	printArray(result, p_size);


}
void Ex2()
{
	/* Called functions:
		inputMatrix, printMatrix, matrixMaxNeighbor, printDynamicMatrix, freeMatrix */
		/* Write Code Here! */
}

void Ex3()
{
	/* Called functions:
		allocMatrix, inputDynamicMatrix, printDynamicMatrix, createThreeLists, printList, freeMatrix, freeList */
		/* Write Code Here! */
}

Number* primeSums(unsigned long long n1, unsigned long long n2, int* p_size)
{
	int capacity = 10; //just a beggining number that will multiply by 2 if p_size is bigger/equal to him
	Number* arr = (Number*)malloc(capacity * sizeof(Number));
	if (arr == NULL) return 0;
	*p_size = 0; //we want to count how many items are in the new array and return it
	
	while (n1 <= n2) { // this line is because we are moving n1++ every iteration of the loop
		int sum = digitSum(n1); 
		if (isPrime(sum)) { //if sum is a prime number then enter
			if (*p_size == capacity) { //checking if p_size value is bigger\equal to capacity
				capacity *= 2; //as required
				arr = realloc(arr, capacity * sizeof(Number)); //assuming there's enough memory to allocate (as said in the instructions)
			}
			arr[*p_size].num = n1; 
			arr[*p_size].sum = sum;
			(*p_size)++; //p_size value will return by refferance in ex1
		}
		n1++;

	
	}

	arr = realloc(arr, (*p_size) * sizeof(Number)); // don't know if needed but re allocating the array size to p_size value so there will be no extra trash values
	return arr;
}

int** matrixMaxNeighbor(int A[][COLS], int rows, int cols)
{
	/* Called functions:
		neighborMax, allocMatrix */
		/* Write Code Here! */
}
void createThreeLists(int** A, int rows, int cols, Item** pL1, Item** pL2)
{
	/* Called functions:
		createThree, insert */
		/* Write Code Here! */
}



/* Definitions of auxiliary functions */

/* Write Definitions Here! */
int isPrime(int num)
{
	if (num < 2) return 0;//0 and 1 are not primer numbers
	if (num == 2)return 1; // 2 is a special case for a prime number
	if (num % 2 == 0) return 0;//if the number is a an even number and bigger than 2 then it's not a prime number
	int limit = sqrt(num); // no need to go through all numbers until num 
	for (int i = 3;i <= limit ; i += 2) {// jumping +2 because if num%EvenNumber == 0 then it's not a prime number
		if (num % i == 0) return 0;
	}
	return 1;
}

int digitSum(unsigned long long num)
{
	if (num < 10) return num;

	return digitSum(num / 10) + num % 10; 
}

void printArray(Number* arr, int size)
{
	for (int i = 0; i < size; i++) {
		printf("Num = %d ,", arr[i].num);
		printf("Sum = %d\n", arr[i].sum);
		
	}

}
