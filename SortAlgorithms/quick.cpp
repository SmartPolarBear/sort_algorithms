#include "sort.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

void quick_swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}

void quick_sort(int arr[], size_t len)
{
	if (len <= 1) // Nothing to do for a single number
	{
		return;
	}

	size_t pivot_index = (1 + abs(rand())) % len;

	quick_swap(arr[0], arr[pivot_index]); // let the first be the selected pivot

	size_t last = 0;
	for (size_t i = 1; i < len; i++)
	{
		if (arr[i] < arr[0])
		{
			quick_swap(arr[i], arr[++last]);
		}
	}

	quick_swap(arr[0], arr[last]);

	quick_sort(arr, last);
	quick_sort(arr + last + 1, len - last - 1);
}
