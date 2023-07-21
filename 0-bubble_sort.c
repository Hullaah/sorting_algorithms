#include "sort.h"
/**
 * bubble_sort - sorts an array of integers in ascending order using the Bubble
 * sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void (does not have a return value.)
*/
void bubble_sort(int *array, size_t size)
{
	size_t tmp, i, j, k;

	for (i = 0; i < size; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			k = j + 1;
			if (array[k] < array[j])
			{
				tmp = array[k];
				array[k] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}
}
