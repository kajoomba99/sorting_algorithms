#include "sort.h"

/**
 * partition - find partition using Lomuto scheme
 * @array: array to sort
 * @lo: firts element of array
 * @hi: latest of array
 * @size: array size
 * Return: index partition
 */
size_t partition(int *array, size_t lo, size_t hi, size_t size)
{
	int pivot, aux;
	size_t i, j;

	i = lo - 1;
	pivot = array[hi];
	for (j = lo; j < hi; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
				print_array(array, size);
			}
		}
	}
	if (array[hi] < array[i + 1])
	{
		aux = array[i + 1];
		array[i + 1] = array[j];
		array[j] = aux;
		print_array(array, size);
	}
	return (i + 1);
}

/**
 * quicksort - sort partition recur
 * @array: array to sort
 * @lo: firts element of array
 * @hi: latest of array
 * @size: array size
 * Return: void
 */
void quicksort(int *array, size_t lo, size_t hi, size_t size)
{
	size_t part;

	if (lo < hi)
	{
		part = partition(array, lo, hi, size);
		quicksort(array, lo, part - 1, size);
		quicksort(array, part + 1, hi, size);
	}
}

/**
 * quick_sort - sorts an array of integers in
 * ascending order using the Quick sort algorithm
 * @array: array to sort
 * @size: array size
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort(array, 0, size - 1, size);
}