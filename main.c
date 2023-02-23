#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "sort.h"

enum SortingAlgorithms {
	BUBBLESORT = 0,
	SELECTIONSORT,
	INSERTIONSORT,
	QUICKSORT,
	MERGESORT
};

int algorithm = 0;

void displayArray(int *elements, size_t start, size_t end) {
	size_t i = start;
	
	for(; i <= end ; i++) {
		printf("%d\n", elements[i]);	
	}
}

int* readArray(size_t *size) {
	size_t i;
	int *array;

	scanf("%lu", size);
	array = calloc(sizeof(int), *size);

	for (i = 0 ; i < (*size) ; i++) scanf("%d", array + i);	

	return array; 
}

void readFlags(int argc, char** argv) {
	int i;

	for (i = 1 ; i < argc ; i++) {
		if(argv[i][0] == '-') {
			if (strcmp(argv[i] + 1, "m") == 0) {
				if (strcmp(argv[i + 1], "bubble") == 0) algorithm = 0;
				else if(strcmp(argv[i + 1], "selection") == 0) algorithm = 1;
				else if(strcmp(argv[i + 1], "insertion") == 0) algorithm = 2;
				else if(strcmp(argv[i + 1], "quick") == 0) algorithm = 3;
				else if(strcmp(argv[i + 1], "merge") == 0) algorithm = 4;
				else {
					printf("Unknown sorting method \"%s\"\n", argv[i + 1]);				
					exit(0);
				}

				i += 1;

			}
		}
	}	
}

int main(int argc, char** argv) {
	size_t lastElementIndex = 0;

	readFlags(argc, argv);

	int *elements = readArray(&lastElementIndex);
	
	lastElementIndex--;

	switch (algorithm) {
		case 0:
			bubblesort(elements, 0, lastElementIndex);
			break;

		case 1:
			selectionsort(elements, 0, lastElementIndex);
			break;

		case 2:
			insertionsort(elements, 0, lastElementIndex);
			break;
		
		case 3:
			quicksort(elements, 0, lastElementIndex);
			break;

		case 4:
			mergesort(elements, 0, lastElementIndex);
	} 

	displayArray(elements, 0, lastElementIndex);

	free(elements);

	return 0;
}
