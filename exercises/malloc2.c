//
// Created by christian on 21/05/24.
//
#include <stdio.h>
#include <stdlib.h>

int    *generate_array(int size)
{
    int i;
    int *array;

    i = 0;
    array = malloc(sizeof(int) * size);
    while (i < size)
    {
        array[i] = i;
        i++;
    }
    return (array);
}

int main(void)
{
    int size;
    int i;
    int *array;

    size = 20;
    array = generate_array(size);
    i = 0;
    while (i < size)
    {
        printf("%i", array[i]);
        i++;
    }
    printf("\n");
    free (array);
    return (0);
}