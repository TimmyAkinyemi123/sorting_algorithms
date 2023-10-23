#include <stdio.h>
#include "sort.h"

void heapify(int *array, size_t size);
void swap(int *array, size_t a, size_t b);
void sift_down(int *array, size_t size, size_t root, size_t max);

/**
 * swap - Swaps two elements in an array
 * @array: The array
 * @a: Index of the first element
 * @b: Index of the second element
 */
void swap(int *array, size_t a, size_t b)
{
	int temp = array[a];

	array[a] = array[b];
	array[b] = temp;
}

/**
 * sift_down - Sifts down an element in the heap
 * @array: The array
 * @size: Size of the array
 * @root: Index of the root element
 * @max: Maximum index in the heap
 */
void sift_down(int *array, size_t size, size_t root, size_t max)
{
	size_t largest, left, right;

	largest = root;
	left = 2 * root + 1;
	right = 2 * root + 2;

	if (left < max && array[left] > array[largest])
		largest = left;

	if (right < max && array[right] > array[largest])
		largest = right;

	if (largest != root)
	{
		swap(array, root, largest);
		print_array(array, size);
		sift_down(array, size, largest, max);
	}
}

/**
 * heapify - Converts an array into a max-heap
 * @array: The array
 * @size: Size of the array
 */
void heapify(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);
}

/**
 * heap_sort - Sorts an array of integers using the Heap sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = size / 2 - 1; i >= 0; i--)
		sift_down(array, size, i, size);

	for (i = size - 1; i > 0; i--)
	{
		swap(array, 0, i);
		print_array(array, size);
		sift_down(array, size, 0, i);
	}
}
