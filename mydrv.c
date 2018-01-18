#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

//include your code


//replace malloc here with the appropriate version of mymalloc
#define MALLOC my_malloc
//replace free here with the appropriate version of myfree
#define FREE my_free
//define DUMP_HEAP() to be the dump_heap() function that you write
#define DUMP_HEAP() dump_heap()

//Whether to turn on verbose heap debug output
#define HEAP_DEBUG

//You can adjust how many things are allocated
#define TIMES 100

//If you want to make times bigger than 100, remove the call to qsort and do something else.
//Then remove this check.
#if TIMES >= 1000
#error "TIMES is too big, qsort will switch to mergesort which requires a temporary malloc()ed array"
#endif


void test1()
{

	char * one = MALLOC(10);


#ifdef HEAP_DEBUG
	printf("heap content after test1:\n");
	DUMP_HEAP();
#endif

	FREE(one);

#ifdef HEAP_DEBUG
	printf("heap content after test1 free:\n");
	DUMP_HEAP();
#endif
}


void test2()
{
	char * one = MALLOC(10);
	char * two = MALLOC(20);


#ifdef HEAP_DEBUG
	printf("heap content after test2:\n");
	DUMP_HEAP();
#endif

	FREE(one);
	FREE(two);

#ifdef HEAP_DEBUG
	printf("heap content after test2 free:\n");
	DUMP_HEAP();
#endif
}

void test3()
{
	char * one = MALLOC(5);
	char * two = MALLOC(10);
	char * three = MALLOC(20);
	char * four = MALLOC(20);
	char * five = MALLOC(10);
	char * six = MALLOC(30);
	char * seven = MALLOC(10);


#ifdef HEAP_DEBUG
	printf("heap content after first MALLOC:\n");
	DUMP_HEAP();
#endif

	FREE(one);
	FREE(six);

#ifdef HEAP_DEBUG
	printf("heap content after first free:\n");
	DUMP_HEAP();
#endif

	one = MALLOC(4);

#ifdef HEAP_DEBUG
	printf("heap content after second MALLOC:\n");
	DUMP_HEAP();
#endif

	FREE(three);
	FREE(four);
	FREE(five);
#ifdef HEAP_DEBUG
	printf("heap content after second free:\n");
	DUMP_HEAP();
#endif

	three = MALLOC(5);
	four = MALLOC(10);
#ifdef HEAP_DEBUG
	printf("heap content after third MALLOC:\n");
	DUMP_HEAP();
#endif

	FREE(one);
	FREE(two);
	FREE(three);
	FREE(four);
	FREE(seven);
#ifdef HEAP_DEBUG
	printf("heap content after final free:\n");
	DUMP_HEAP();
#endif
}

int main()
{
	srand((unsigned int)time(NULL));
#ifdef HEAP_DEBUG
	printf("\nheap content at beginning:\n");
	DUMP_HEAP();
#endif
	printf("\n\n\nBEGIN TEST 1\n\n");
	test1();
	printf("\n\n\nBEGIN TEST 2\n\n");
	test2();
	printf("\n\n\nBEGIN TEST 3\n\n"); 
	test3(); 
	return 0;
}
