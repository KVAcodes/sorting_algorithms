#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order using
 *		the Shell sort algorithm and Knuth sequence.
 * @array: the array to be sorted.
 * @size: the length of the array.
 *
 * Return: Nothing(void).
 */
void shell_sort(int *array, size_t size)
{
	size_t gap = 1, count;
	int count_2;

	while (gap * 3 + 1 < size)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (count = gap; count < size; count++)
		{
			for (count_2 = count - gap; count_2 >= 0; count_2 -= gap)
			{
				if (array[count_2 + gap] < array[count_2])
					swap_int(array + count_2 + gap,
							array + count_2);
				else
					break;

			}
		}
		print_array(array, size);
	}
}

/**
 * swap_int - swaps the int values contained in two different pointers.
 * @ptr1: first pointer to int.
 * @ptr2: second pointer to int.
 *
 * Return: Nothing(void).
 */
void swap_int(int *ptr1, int *ptr2)
{
	int tmp = *ptr1;
	*ptr1 = *ptr2;
	*ptr2 = tmp;
}
