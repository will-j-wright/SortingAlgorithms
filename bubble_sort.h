#pragma once

template<class T>
class bubble_sort
{
private:
	static void b_sort_recursive(T* array, const int array_size);
	static void b_sort_iterative(T* array, const int array_size);
public:
	static void sort(T* array, const int array_size, const bool use_recursive);
};

template <class T>
void bubble_sort<T>::b_sort_recursive(T* array, const int array_size)
{
	if (array_size == 1)
		return;

	for (int i = 0; i < array_size - 1; i++)
		if (array[i] > array[i + 1])
			std::swap(array[i], array[i + 1]);
	
	b_sort_recursive(array, array_size - 1);
}

template <class T>
void bubble_sort<T>::b_sort_iterative(T* array, const int array_size)
{
	for(int i = array_size; i > 0; i--)
		for(int j = 0; j < i - 1; j++)
			if (array[j] > array[j + 1])
				std::swap(array[j], array[j + 1]);
}

template <class T>
void bubble_sort<T>::sort(T* array, const int array_size, const bool use_recursive)
{
	use_recursive ? b_sort_recursive(array, array_size) : b_sort_iterative(array, array_size);
}
