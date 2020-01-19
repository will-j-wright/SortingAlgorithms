#pragma once

template<class T>
class quicksort
{
private:
	static void sort(T* array, const int start, const int end);
	static int partition(T* array, const int start, const int end);
public:
	static void sort(T* array, const int array_size);
};

template <class T>
void quicksort<T>::sort(T* array, const int start, const int end)
{
	if(start < end)
	{
		const int p = partition(array, start, end);
		sort(array, start, p - 1);
		sort(array, p + 1, end);
	}
}

template <class T>
int quicksort<T>::partition(T* array, const int start, const int end) // Lomuto partition scheme
{
	int p_val = array[end];
	int i = start;
	for(int j = start; j < end; j++)
	{
		if(array[j] < p_val)
		{
			std::swap(array[i], array[j]);
			i++;
		}
	}
	std::swap(array[i], array[end]);
	return i;
}

template <class T>
void quicksort<T>::sort(T* array, const int array_size)
{
	sort(array, 0, array_size - 1);
}
