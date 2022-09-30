#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *		 using the Bubble sort algorithm.
 * @array: the array to sort.
 * @size: size of the array <array>.
 *
 * Return: Nothing(void function).
 */
void bubble_sort(int *array, size_t size)
{
	size_t count, count_2, tmp, flag;

	if (size < 2)
		return;

	for (count = 0; count < size - 1; count++)
	{
		flag = 0;
		for (count_2 = 0; count_2 < size - count - 1; count_2++)
		{
			if (array[count_2] > array[count_2 + 1])
			{
				tmp = array[count_2];
				array[count_2] = array[count_2 + 1];
				array[count_2 + 1] = tmp;
				print_array(array, size);
				flag = 1;
			}
		}
		if (flag == 0)
			break;
	}

}
