#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order using
 * the Counting sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, max = array[0];
	int *output_array, *count_array;
	size_t j;

	if (size <= 1)
		return;

	for (j = 1; j < size; j++)
	{
	       if (array[j] > max)
		       max = array[j];
	}
	count_array = malloc(sizeof(int) * (max + 1));
	if (count_array == NULL)
		return;

	for (i = 0; i <= max; i++)
		count_array[i] = 0;
	for (j = 0; j < size; j++)
		count_array[array[j]]++;

	print_array(count_array, max + 1);
	for (i = 1; i <= max; i++)
		count_array[i] += count_array[i - 1];

	output_array = malloc(sizeof(int) * size);
	if (output_array == NULL)
	{
		free(count_array);
		return;
	}
	for (i = size - 1; i >= 0; i--)
	{
		output_array[count_array[array[i]] - 1] = array[i];
		count_array[array[i]]--;
	}
	for (size_t i = 0; i < size; i++)
		array[i] = output_array[i];
	free(output_array);
	free(count_array);
}
