#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void countSort(int *array, size_t size, int exp);
int getMax(int *array, size_t size);

/**
 * getMax - Returns the maximum element from an array
 * @array: The array
 * @size: Size of the array
 * Return: The maximum element
 */
int getMax(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - Counting sort based on the significant digit
 * @array: The array to be sorted
 * @size: Size of the array
 * @exp: The current significant digit
 */
void countSort(int *array, size_t size, int exp)
{
	int *output = malloc(size * sizeof(int));
	int count[10] = {0};
	size_t i;

	if (output == NULL)
		return;

	for (i = 0; i < size; i++)
		count[(array[i] / exp) % 10]++;
	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];
	for (i = size - 1; (int)i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}
	for (i = 0; i < size; i++)
		array[i] = output[i];

	free(output);
}

/**
 * radix_sort - Sorts an array of integers using LSD Radix Sort
 * @array: The array to be sorted
 * @size: Size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max = getMax(array, size);
	int exp;

	if (!array || size < 2)
		return;
	for (exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		if (exp != 1)
			print_array(array, size);
	}
}
