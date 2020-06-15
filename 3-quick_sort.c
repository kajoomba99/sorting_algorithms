#include "sort.h"
/**
 * partition - partition
 * @arr: arr
 * @low: low
 * @high: high
 * @size: size
 * Return: int
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1);
	int j;
	int temp = 0;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] < pivot)
		{
			i++;
			if (i != j)
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
				print_array(arr, size);
			}
		}
	}
	if (arr[high] < arr[i + 1])
	{
		temp = arr[i + 1];
		arr[i + 1] = arr[high];
		arr[high] = temp;
		print_array(arr, size);
	}
	return (i + 1);
}
/**
 * quickSort - quickSort
 * @arr: arr
 * @low: low
 * @high: high
 * @size: size
 */
void quickSort(int arr[], int low, int high, size_t size)
{
	if (low < high)
	{

		int pi = partition(arr, low, high, size);

		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}
/**
 * quick_sort - quick_sort
 * @array: array
 * @size: size
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}
