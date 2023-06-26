#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in
 * ascending order using the Bubble sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i = 0, l= 0;
	int swapped = 0, tmp;

	for (i = 0; i < size; i++)
	{
		for (l = 0; l < size - 1 - i; l++)
		{
			if (array[l] > array[l + 1])
			{
				tmp = array[l];
				array[l] = array[l + 1];
				array[l + 1] =  tmp;
				swapped = 1;
				print_array(array, size);
			}
		}
		if (!swapped)
			break;
	}
}
