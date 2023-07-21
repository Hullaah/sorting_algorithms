#include "sort.h"
/**
 * selection_sort -  sorts an array of integers in ascending order using the
 * Selection sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void (does not have a return value)
*/
void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, smallest;

	for (i = 0; i < size - 1; i++)
	{
		smallest = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[smallest])
				smallest = j;
		}
		tmp = array[smallest];
		array[smallest] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
}
