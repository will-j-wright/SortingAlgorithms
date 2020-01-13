#pragma once
#include <algorithm>
#include <random>

template<class T>
class bogo_sort
{
public:
	static void sort(T* array, const int array_size);
};

template <class T>
void bogo_sort<T>::sort(T* array, const int array_size)
{
	std::random_device rd;
	std::mt19937 g(rd());
	for (int i = 0; i < array_size - 1; i++)
	{
		if (array[i] > array[i + 1])
		{
			std::shuffle(&array[0], &array[array_size], g);
			i = -1;
			continue;
		}
	}
}
