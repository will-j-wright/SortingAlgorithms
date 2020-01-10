#pragma once

template<class T>
class insertion_sort
{
private:
	static void i_sort_recursive(T* array, const int count);
	static void i_sort_iterative(T* array, const int array_size);
public:
	static void sort(T* array, const int array_size, bool use_recursive);
};

template <class T>
void insertion_sort<T>::i_sort_recursive(T* array, const int count) // Execution time is equal to iterative, but memory is O(n) instead of O(1), so this implementation is actually worse
{
	if (count > 0)
	{
		i_sort_recursive(array, count - 1);
		T cur = array[count];
		int i = count - 1;
		for(; i >= 0 && array[i] > cur; i--)
			array[i + 1] = array[i];
		array[i + 1] = cur;
	}
}

template <class T>
void insertion_sort<T>::i_sort_iterative(T* array, const int array_size)
{
	for (int i = 0; i < array_size; i++)
		for (int j = i; j > 0 && array[j - 1] > array[j]; j--)
			std::swap(array[j], array[j - 1]);
}

template <class T>
void insertion_sort<T>::sort(T* array, const int array_size, bool use_recursive)
{
	use_recursive ? i_sort_recursive(array, array_size - 1) : i_sort_iterative(array, array_size);
}
