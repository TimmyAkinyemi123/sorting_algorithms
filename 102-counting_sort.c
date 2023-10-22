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
    int i, max = min = array[0] *count, range, *result;
    size_t k;

    if (size <= 1)
        return;
    for (i = 1; i < size; i++)
    {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }
    range = max - min + 1;
    count = malloc(range * sizeof(int));
    if (!count)
        return;
    for (i = 0; i < range; i++)
        count[i] = 0;
    for (k = 0; k < size; k++)
        count[array[k] - min]++;
    for (i = 0; i < range; i++)
    {
        if (i == range - 1)
            printf("%d\n", count[i]);
        else
            printf("%d, ", count[i]);
    }
    k = 0;
    result = malloc(size * sizeof(int));
    if (!result)
    {
        free(count);
        return;
    }
    for (i = 0; i < range; i++)
    {
        while (count[i] > 0)
        {
            result[k] = i + min;
            k++;
            count[i]--;
        }
    }
    for (k = 0; k < size; k++)
        array[k] = result[k];
    free(count);
    free(result);
}
