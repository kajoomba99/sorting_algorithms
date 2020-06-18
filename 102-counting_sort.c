#include "sort.h"
/**
 * get_max - get_max
 * @array: array of integers
 * @size: size of the array
 * Return: the max number of the array
 */
int get_max(int *array, size_t size)
{
	int i = 0;
	int max = array[0];

	for (i = 1; i < (int)size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}

	return (max);
}
/**
 * counting_sort - counting_sort
 * @array: array
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int i = 0;
	int max = get_max(array, size);
	int *output = malloc(sizeof(int) * size);
	int *count = malloc(sizeof(int) * (max + 1));

	if (!output)
		return;

	if (!count)
	{
		free(output);
		return;
	}

	for (i = 0; i <= max; ++i)
		count[i] = 0;

	for (i = 0; i < (int)size; i++)
		count[array[i]]++;

	for (i = 1; i <= max; i++)
		count[i] += count[i - 1];

	for (i = (int)size - 1; i >= 0; i--)
	{
		output[count[array[i]] - 1] = array[i];
		count[array[i]]--;
	}

	for (i = 0; i < (int)size; i++)
		array[i] = output[i];

	print_array(count, max + 1);
	free(output), free(count);
}
