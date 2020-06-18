#include "sort.h"

/**
 * swap - function that swaps integers
 * @a: first integer
 * @b: second integer
 */
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * quick_sort_hoare - Function for quick sort algorithm
 * @array: array to sort
 * @size: size of the array
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort_hoare(array, 0, size - 1, size);
}

/**
 * quicksort_hoare - Function that do the recursion
 * @array: array to sort
 * @low: low position
 * @high: high position
 * @size: size of the array
 */
void quicksort_hoare(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = partition(array, low, high, size);
		quicksort_hoare(array, low, p - 1, size);
		quicksort_hoare(array, p, high, size);
	}
}

/**
 * partition - Function that splits the pivot positions
 * @array: array
 * @start: start of the array
 * @end: end of the array
 * @size: size of the array
 * Return: the lowest value
 */
int partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end];
	int i, j;

	i = start - 1;
	j = end + 1;

	while (i < j)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			j--;
		} while (array[j] > pivot);
		if (i < j)
		{
			swap(&array[i], &array[j]);
			print_array(array, size);
		}
	}
	return (i);
}
