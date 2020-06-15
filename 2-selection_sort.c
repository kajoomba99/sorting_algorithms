#include "sort.h"
/**
 * selection_sort - selection_sort
 * @array: array
 * @size: size
 */
void selection_sort(int *array, size_t size)
{
	size_t i = 0, j = 0, menor = 0, tmp = 0;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		menor = i;
		for (j = i; j < size; j++)
		{
			if (array[j] < array[menor])
				menor = j;
		}

		if (i != menor)
		{
			tmp = array[i];
			array[i] = array[menor];
			array[menor] = tmp;
			print_array(array, size);
		}
	}
}
