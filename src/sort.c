#include <stdio.h>
#include <stdlib.h>

void swap(int* array, const size_t indexA, const size_t indexB) {
	int aux = array[indexA];
	array[indexA] = array[indexB];
	array[indexB] = aux;
}


size_t partition(int *elements, const size_t first, const size_t last, const size_t pivotIndex) {
	size_t i = first, j = last;

	int pivot = elements[pivotIndex];

	swap(elements, pivotIndex, last);

	while (1) {
		while (elements[i] <= pivot && i <= j) i++;
		while (elements[j] > pivot && i <= j) j--;
		if (i < j) {
			swap(elements, i, j);
		}
		else {
			break;
		}
	}

	return j;
}

void quicksort(int *elements, const size_t first, const size_t last) {
	size_t pivotIndex = first;

	size_t newPivotIndex = partition(elements, first, last, pivotIndex);

	if (newPivotIndex > 0 && (newPivotIndex - 1) > first) {
		quicksort(elements, first, newPivotIndex - 1);
	}
	if ((newPivotIndex + 1) < last){
		quicksort(elements, newPivotIndex + 1, last);
	}
}

void mergesort(int *elements, const size_t start, const size_t end) {
	if(end > start) {
		size_t middle = (end + start) / 2;

		mergesort(elements, start, middle);
		mergesort(elements, middle + 1, end);

		size_t i = start, j = middle + 1, k = 0;
		
		int buffer[end - start + 1];

		while(i <= middle && j <= end) {
			if(elements[i] <= elements[j]) buffer[k++] = elements[i++];
			else buffer[k++] = elements[j++];
		}

		while (i <= middle) buffer[k++] = elements[i++];
		while (j <= end) buffer[k++] = elements[j++];

		k = 0;
		i = start;
	
		while (i <= end) {
			elements[i++] = buffer[k++];
		}
	}

}

void bubblesort(int* elements, const size_t start, const size_t end) {
	char flag = 1;
	size_t i = start;
	size_t j = end;

	while (flag){
		flag = 0;

		for (i = start; i < j ; i++) {
			if (elements[i] > elements[i + 1]) {
				swap(elements, i, i + 1);
				flag = 1;
			}
		}

		j -= 1;
	}
}

void selectionsort(int *elements, const size_t start, const size_t end) {
	size_t pos = 0, i = 0, j = 0;	

	for (i = start ; i < end ; i++) {
		pos = i;

		for (j = i + 1 ; j <= end ; j++) {
			if (elements[j] <= elements[pos]) {
				pos = j;
			}
		}

		swap(elements, i, pos);
	}
}

void insertionsort(int *elements, const size_t start, const size_t end) {
	size_t i, j;
	
	for (j = start + 1 ; j <= end ; j++) {
		i = j;
		while (i > 0 && elements[i] < elements[i - 1]) {
			swap(elements, i, i - 1);
			i--;
		}
	}
}
