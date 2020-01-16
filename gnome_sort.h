#pragma once

template<class T>
class gnome_sort
{
public:
	static void sort(T* array, const int array_size, int start = 0);
};

template <class T>
void gnome_sort<T>::sort(T* array, const int array_size, const int start)
{
	if (start == array_size - 1)
		return;
	if (array[start] < array[start + 1])
		sort(array, array_size, start + 1);
	else
	{
		std::swap(array[start], array[start + 1]);
		if (start != 0)
			sort(array, array_size, start - 1);
		else
			sort(array, array_size, start);
	}
}
