#include "sort.h"

/**
 * quick_sort - sorts an array of integer in ascending order using the
 *		Quick sort algorithm.
 * @array: The array to sort.
 * @size: The size of array <array>.
 *
 * Return: Nothing(void).
 */
void quick_sort(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_sort_recursion(array, 0, size - 1, size);
}

/**
 * partition - partitions a portion of an array using the last element
 *	       of the portion as the pivot.
 * @array: the entire array.
 * @start: start index of the portion.
 * @end: last index of the portion.
 * @size: size of array.
 *
 * Description: This function takes in an array and the start and end indices
 * of the portion, it uses the last element in the portion as a pivot and sets
 * every elem less and greater than it to the left and right of it respectively
 * and returns the index of the pivot at the end of the partitioning.
 *
 * Return: the index of pivot.
 */
size_t partition(int *array, int start, int end, size_t size)
{
	int pivot = array[end], pIndex = start, count, tmp;

	for (count = start; count < end; count++)
	{
		if (array[count] <= pivot)
		{
			tmp = array[count];
			array[count] = array[pIndex];
			array[pIndex] = tmp;
			pIndex++;
		}
	}
	array[end] = array[pIndex];
	array[pIndex] = pivot;

	print_array(array, size);

	return (pIndex);
}

/**
 * quick_sort_recursion - solves the recursion aspect of quick sort.
 * @array: the array to sort.
 * @start: start of portion.
 * @end: end of portion
 * @size: size of array
 *
 * Return: Nothing(void function).
 */
void quick_sort_recursion(int *array, int start, int end, size_t size)
{
	int pIndex;

	if (start < end)
	{
		pIndex = partition(array, start, end, size);
		quick_sort_recursion(array, start, pIndex - 1, size);
		quick_sort_recursion(array, pIndex + 1, end, size);
	}
}
