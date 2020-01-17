#pragma once
#include <vector>
#include <algorithm>
#include <cmath>

class bucket_sort
{
public:
	static void sort(int* array, const int array_size);
};

inline void bucket_sort::sort(int* array, const int array_size) // inline just to keep with the others. Can't use a template because this is int only
{
	const int bucket_count = std::sqrt(array_size);
	auto* buckets = new std::vector<int>[bucket_count];
	int max = INT_MIN;
	
	
	for (int i = 0; i < array_size; i++)
		if (array[i] > max)
			max = array[i];

	// buckets * array val * max + 1
	
	for(int i = 0; i < array_size; i++)
		buckets[int(std::floor(bucket_count * array[i] / (max + 1)))].push_back(array[i]); // max + 1 so the max resolves to bucket_count - 1

	for (int i = 0; i < bucket_count; i++)
	{
		std::sort(buckets[i].begin(), buckets[i].end()); // I know, this is cheating, but I already wrote insertion sort
		if (i != 0)
			buckets[0].insert(buckets[0].end(), buckets[i].begin(), buckets[i].end()); // insert all the vectors into the first one, so we can convert it back
	}

	for (int i = 0; i < array_size; i++)
		array[i] = buckets[0][i];

	delete[] buckets;
}
