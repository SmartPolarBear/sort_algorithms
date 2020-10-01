#include "sort.h"

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <chrono> 

using namespace std;
using namespace std::chrono;

constexpr size_t DATA_SET_MIN = 50;
constexpr size_t DATA_SET_MAX = 100;

static inline size_t random_range(size_t nmin, size_t nmax)
{
	return  nmin + static_cast<size_t>(rand()) % (nmax - nmin + 1);
}

static inline size_t get_random_size()
{
	return random_range(DATA_SET_MIN, DATA_SET_MAX);
}

int data_set[DATA_SET_MAX] = { 0 };


int main()
{
	while (true)
	{
		memset(data_set, 0, sizeof(data_set));
		srand(time(nullptr));

		size_t dsize = get_random_size();
		for (size_t i = 0; i < dsize; i++)
		{
			data_set[i] = random_range(1, 100);
		}

		cout << "Primary:" << endl;
		for (size_t i = 0; i < dsize; i++)
		{
			cout << data_set[i] << " ";
		}
		cout << endl;

		int* data_copy = new int[dsize];

		// Quicksort test
		memcpy(data_copy, data_set, sizeof(int) * dsize);

		auto start = high_resolution_clock::now();
		quick_sort(data_copy, dsize);
		auto stop = high_resolution_clock::now();

		cout << "Quicksort: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;
		for (size_t i = 0; i < dsize; i++)
		{
			cout << data_copy[i] << " ";
		}
		cout << endl;


		// Merge sort test
		memcpy(data_copy, data_set, sizeof(int) * dsize);

		start = high_resolution_clock::now();
		merge_sort(data_copy, dsize);
		stop = high_resolution_clock::now();

		cout << "Mergesort: " << duration_cast<microseconds>(stop - start).count() << " ms" << endl;
		for (size_t i = 0; i < dsize; i++)
		{
			cout << data_copy[i] << " ";
		}
		cout << endl;

		char c = getchar(); // pause
	}

	return 0;
}