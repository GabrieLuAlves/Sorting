#ifndef SORT_H
#define SORT_H

void bubblesort(int* elements, const size_t first, const size_t last);
void selectionsort(int* elements, const size_t first, const size_t last);
void insertionsort(int *elements, const size_t first, const size_t last);
void quicksort(int *elements, const size_t first, const size_t last);
void mergesort(int *elements, const size_t first, const size_t last);
/***
 * Soon...
 */
/*
void heapsort(int* elements, const size_t first, const size_t last);
void shellsort(int* elements, const size_t first, const size_t last);
*/

#endif
