#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - Sorts an array of integers in
 * ascending order using Counting sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 */
void counting_sort(int *array, size_t size)
{
	int i, max = array[0], *count, index = 0;
	size_t j;

	if (array == NULL || size <= 1)
		return;
	for (j = 1; j < size; j++)
	{
		if (array[j] > max)
			max = array[j];
	}

	count = malloc((max + 1) * sizeof(int));
	if (count == NULL)
		return;
	for (i = 0; i <= max; i++)
		count[i] = 0;
	for (j = 0; j < size; j++)
		count[array[j]]++;

	/* Print the counting array */
	for (i = 0; i <= max; i++)
	{
		if (i != 0)
			printf(", ");
		printf("%d", count[i]);
	}
	printf("\n");

	for (i = 0; i <= max; i++)
	{
		while (count[i] > 0)
		{
			array[index] = i;
			index++;
			count[i]--;
		}
	}
	free(count);
}
