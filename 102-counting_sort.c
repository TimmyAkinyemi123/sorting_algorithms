#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in ascending order
 * using the Counting Sort algorithm.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int *count, *result, range, max, min, i;
	size_t j;

	if (size <= 1)
		return;
	max = array[0], min = array[0];
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
		if (array[j] < min)
			min = array[j];
	}
	range = max - min + 1;
	count = malloc(range * sizeof(int));
	if (!count)
		return;
	for (i = 0; i < range; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j] - min]++;
	for (i = 0; i < range; i++)
		printf(i == range - 1 ? "%d\n" : "%d, ", count[i]);
	j = 0, result = malloc(size * sizeof(int));
	if (!result)
	{
		free(count);
		return;
	}
	for (i = 0; i < range; i++)
	{
		while (count[i] > 0)
		{
			result[j] = i + min;
			j++, count[i]--;
		}
	}
	for (j = 0; j < size; j++)
		array[j] = result[j];
	free(count), free(result);
}
