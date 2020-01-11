#pragma once

template<class T>
class selection_sort
{
private:
	static void s_sort_iterative(T* array, const int array_size);
	static void s_sort_recursive(T* array, const int array_size, const int start = 0);
	static int s_sort_find_min_index(T* array, const int array_size, const int prev_min = 0, const int start = 0);
public:
	static void sort(T* array, const int array_size, bool use_recursive);
};

template <class T>
void selection_sort<T>::s_sort_iterative(T* array, const int array_size)
{
	for(int i = 0; i < array_size; i++)
	{
		int min_index = i;
		for(int j = i; j < array_size; j++)
		{
			if (array[j] < array[min_index])
				min_index = j;
		}
		std::swap(array[i], array[min_index]);
	}
}

template <class T>
void selection_sort<T>::s_sort_recursive(T* array, const int array_size, const int start)
{
	if (start == array_size)
		return;
	std::swap(array[s_sort_find_min_index(array, array_size, start, start)], array[start]);
	s_sort_recursive(array, array_size, start + 1);
}

template <class T>
int selection_sort<T>::s_sort_find_min_index(T* array, const int array_size, const int prev_min, const int start)
{
	if (start == array_size - 1)
		return array[prev_min] <= array[start] ? prev_min : start;
	if (array[prev_min] <= array[start])
		return s_sort_find_min_index(array, array_size, prev_min, start + 1);
	else
		return s_sort_find_min_index(array, array_size, start, start + 1);
}

template <class T>
void selection_sort<T>::sort(T* array, const int array_size, bool use_recursive)
{
	use_recursive ? s_sort_recursive(array, array_size) : s_sort_iterative(array, array_size);
}
