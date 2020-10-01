#include "sort.h"

#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int* arr_new = nullptr;

void merge(int arr[], size_t l1, size_t r1, size_t l2, size_t r2)
{
	size_t p1 = l1, p2 = l2, t = l1;

	while (p1 <= r1 && p2 <= r2)
	{
		if (arr[p2] < arr[p1])
		{
			arr_new[t++] = arr[p2];
			p2++;
		}
		else
		{
			arr_new[t++] = arr[p1];
			p1++;
		}
	}

	if (p1 <= r1)
	{
		for (size_t i = p1; i <= r1; i++)
		{
			arr_new[t++] = arr[i];
		}
	}

	if (p2 <= r2)
	{
		for (size_t i = p2; i <= r2; i++)
		{
			arr_new[t++] = arr[i];
		}
	}

	for (size_t i = l1; i <= r2; i++)
	{
		arr[i] = arr_new[i];
	}

	return;
}

void msort(int arr[], size_t l, size_t r)
{
	size_t mid = (r + l) / 2;

	if (l == r)
	{
		return;
	}

	msort(arr, l, mid);
	msort(arr, mid + 1, r);

	merge(arr, l, mid, mid + 1, r);
}

void merge_sort(int arr[], size_t len)
{
	arr_new = new int[len];

	memset(arr_new, 0, sizeof(int) * len);

	msort(arr, 0, len - 1);

	delete[] arr_new;
}
