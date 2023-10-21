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
    int max = array[0];
    int min = array[0];
    int range, index;
    size_t i, j;

				if (array == NULL || size <= 1)
        return;

    for (i = 1; i < size; i++) {
        if (array[i] > max)
            max = array[i];
        if (array[i] < min)
            min = array[i];
    }

    range = max - min + 1;

    int *count = malloc(range * sizeof(int));
    if (count == NULL)
        return;

    for (i = 0; i < range; i++) {
        count[i] = 0;
    }

    /* Populate the counting array */
    for (j = 0; j < size; j++) {
        count[array[j] - min]++;
    }

    /* Print the counting array */
    for (i = 0; i < range; i++) {
        if (i != 0) {
            printf(", ");
        }
        printf("%d", count[i]);
    }
    printf("\n");

    index = 0;
    for (i = 0; i < range; i++) {
        while (count[i] > 0) {
            array[index] = i + min;
            index++;
            count[i]--;
        }
    }

    free(count);
}

