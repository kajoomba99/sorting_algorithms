#include "sort.h"
/**
 * shell_sort - shell_sort
 * @array: array
 * @size: size
 */
void shell_sort(int *array, size_t size)
{
	size_t interval = 1, outer = 0, inner = 0;
	int vti = 0; /*Value to insert*/

	if (!array || size < 2)
		return;

	while (interval < size / 3)
		interval = interval * 3 + 1;

	while (interval > 0)
	{
		for (outer = interval; outer < size; outer++)
		{
			/* select value to be inserted */
			vti = array[outer];
			inner = outer;

				/*shift element towards right*/
				while (inner > interval - 1 && array[inner - interval] >= vti)
				{

					array[inner] = array[inner - interval];
					inner = inner - interval;
				}

			/* insert the number at hole position */
			array[inner] = vti;
		}
		/* calculate interval*/
		interval = (interval - 1) / 3;
		print_array(array, size);
	}
}
