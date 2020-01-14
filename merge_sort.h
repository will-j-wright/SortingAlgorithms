#pragma once
#include <cmath>

template<class T>
class merge_sort
{
private:
	static void merge_array(T* array, const int start, const int half, const int end);
	static void m_sort(T* array, int start, int end);
public:
	static void sort(T* array, const int array_size);
};

template <class T>
void merge_sort<T>::merge_array(T* array, const int start, const int half, const int end)
{
	const int arr_size_1 = half - start + 1;
	const int arr_size_2 = end - half;

	T* arr_1 = new T[arr_size_1];
	T* arr_2 = new T[arr_size_2];

	for(int i = 0; i < arr_size_1; i++) // copy the first half
		arr_1[i] = array[start + i];
	for(int i = 0; i < arr_size_2; i++) // copy the second half 
		arr_2[i] = array[half + 1 + i];

	int itr_1 = 0; // pointer loc for array 1
	int itr_2 = 0; // pointer loc for array 2
	int m_itr = start; // pointer loc for main array
	while(itr_1 < arr_size_1 && itr_2 < arr_size_2)
	{
		if(arr_1[itr_1] <= arr_2[itr_2])
		{
			array[m_itr] = arr_1[itr_1];
			itr_1++;
		}
		else
		{
			array[m_itr] = arr_2[itr_2];
			itr_2++;
		}
		m_itr++;
	}

	while(itr_1 < arr_size_1)
	{
		array[m_itr] = arr_1[itr_1];
		itr_1++;
		m_itr++;
	}
	while (itr_2 < arr_size_2)
	{
		array[m_itr] = arr_2[itr_2];
		itr_2++;
		m_itr++;
	} // both conditions can never both be true, so we don't have to worry about that
	delete[] arr_1;
	delete[] arr_2;
}

template <class T>
void merge_sort<T>::m_sort(T* array, const int start, const int end)
{
	if(start < end)
	{
		const int half = (start + end) / 2;
		m_sort(array, start, half);
		m_sort(array, half + 1, end);
		merge_array(array, start, half, end);
	}
}

template <class T>
void merge_sort<T>::sort(T* array, const int array_size)
{
	m_sort(array, 0, array_size - 1);
}

