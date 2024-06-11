//
// Created by christian on 21/05/24.
//
#include <stdio.h>
#include <stdlib.h>

int*    generatearray(void)
{
    int array[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    return (array);
}

int main(void)
{
    int count;
    int size;
    int i;
    int *array;
    int *array2;

    count = 0;
    size = 10;
    array = malloc(sizeof (int) * size);
    if (array == NULL)
    {
        printf("Memory allocation failed.\n");
        return (1);
    }
    size *= 2;
    array2 = realloc(array, sizeof (int) * size);
    if (array2 == NULL)
    {
        printf("Memory allocation failed...\n");
        return (1);
    }
    else
        array = array2;
    i = 0;
    while (i < size/2)
    {
        array[i] = i;
        i++;
        count++;
    }
    i = 0;
    while (i < count)
    {
        printf("%i", array[i]);
        i++;
    }
    printf("\n");
    printf("size: %i, count %i", size, count);
    free (array);
    return (0);
}