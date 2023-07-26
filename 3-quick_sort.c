#include "sort.h"
/**
 * swap - swaps two integers
 * @a: first integer
 * @b: second integer
 * Return: void (does not have a return value)
*/
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * partition - partitions the array using the param high as pivot
 * @low: lower index for partitioning
 * @high: pivot for partitioning
 * @array: array to be partitioned
 * @size: size of array
 * Return: the new pivot for the next partitioning
 * Description: It uses the  high as the pivot arranging all the elements
 * smaller than or equal to the pivot on the left and arranging the elements
 * larger than the pivot to the left. Then the pivot is placed in between
 * the left and right elements.
*/
int partition(int *array, int low, int high, int size)
{
	int pivot = low - 1, i;

	for (i = low; i < high; i++)
	{
		if (array[i] <= array[high])
		{
			pivot += 1;
			swap(&array[i], &array[pivot]);
		}
	}
	pivot++;
	swap(&array[i], &array[pivot]);
	print_array(array, size);
	return (pivot);
}
/**
 * quick_sort_base - base for the implementation of the quick sort function
 * @array: array too be sorted
 * @high: pivot index for partitioning and sorting
 * @low: lower index for partitioning and sorting
 * @size: size of array
 * Return: void ( does not have a return value)
*/
void quick_sort_base(int array[], int low, int high, int size)
{
	int pivot;

	if (low < high)
	{
		pivot = partition(array, low, high, size);
		quick_sort_base(array, low, pivot - 1, size);
		quick_sort_base(array, pivot + 1, high, size);
	}
}
/**
 * quick_sort - sorts an array of integers in ascending order using the
 * Quick sort algorithm
 * @array: array to be sorted
 * @size: size of array
 * Return: void (does not have a return value)
*/
void quick_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;
	quick_sort_base(array, 0, size - 1, size);
}
