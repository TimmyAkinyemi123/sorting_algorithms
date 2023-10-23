#include <stdio.h>
#include "sort.h"

void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir);
void bitonic_merge(int *array, size_t low, size_t count, int dir);
void swap(int *array, size_t a, size_t b);

/**
 * swap - Swaps two elements in the array
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
 * bitonic_merge - Merges two subarrays of the bitonic sequence
 * @array: The array
 * @low: Starting index of the first subarray
 * @count: Number of elements to merge
 * @dir: Sort direction (1 for ascending, 0 for descending)
 */
void bitonic_merge(int *array, size_t low, size_t count, int dir)
{
	size_t k, i;

	if (count > 1)
	{
		k = count / 2;
		for (i = low; i < low + k; i++)
		{
			if ((array[i] > array[i + k]) == dir)
				swap(array, i, i + k);
		}
		bitonic_merge(array, low, k, dir);
		bitonic_merge(array, low + k, k, dir);
	}
}

/**
 * bitonic_sort_recursive - Recursively performs Bitonic Sort
 * @array: The array
 * @low: Starting index of the subarray
 * @count: Number of elements to sort
 * @dir: Sort direction (1 for ascending, 0 for descending)
 */
void bitonic_sort_recursive(int *array, size_t low, size_t count, int dir)
{
	size_t k;

	if (count > 1)
	{
		k = count / 2;
		printf("Merging [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
		print_array(array + low, count);
		bitonic_sort_recursive(array, low, k, 1);
		bitonic_sort_recursive(array, low + k, k, 0);
		bitonic_merge(array, low, count, dir);
		printf("Result [%lu/%lu] (%s):\n", count, count * 2, dir ? "UP" : "DOWN");
		print_array(array + low, count);
	}
}

/**
 * bitonic_sort - Sorts an array of integers using the Bitonic sort algorithm
 * @array: The array to be sorted
 * @size: Size of the array (must be a power of 2)
 */
void bitonic_sort(int *array, size_t size)
{
	int dir = 1;

	if (size > 1)
	{
		printf("Merging [%lu/%lu] (%s):\n", size, size, dir ? "UP" : "DOWN");
		print_array(array, size);
		bitonic_sort_recursive(array, 0, size, dir);
	}
}
