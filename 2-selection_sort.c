#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order using
 *		    the Selection sort algorithm.
 * @array: The array to be sorted in place.
 * @size: The size of the array <array>.
 *
 * Return: Nothing(void).
 */
void selection_sort(int *array, size_t size)
{
	size_t flag, count, count_2, curr_min, tmp;

	if (size < 2)
		return;

	for (count = 0; count < size - 1; count++)
	{
		curr_min = count;
		flag = 0;
		for (count_2 = curr_min + 1; count_2 < size; count_2++)
		{
			if (array[count_2] < array[curr_min])
			{
				curr_min = count_2;
				flag = 1;
			}
		}
		if (flag == 1)
		{
			tmp = array[count];
			array[count] = array[curr_min];
			array[curr_min] = tmp;
			print_array(array, size);
		}
	}
}
