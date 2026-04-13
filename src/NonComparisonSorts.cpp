#include "NonComparisonSorts.h"
#include <iostream>
#include <algorithm>

// ---------------------------------------------------------------------------
// Counting Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: cpp_diagrams.md #1 -- Steps 1a, 1b, 1c (Count Phase)
// ? SEE DIAGRAM: cpp_diagrams.md #2 -- Step 2 (Placement Phase)
//
void counting_sort(std::vector<int>& data) {
    
    //   1. Find the min and max values
	int min_val = *std::min_element(data.begin(), data.end());
	int max_val = *std::max_element(data.begin(), data.end());
    //   2. Create a count array of size (max - min + 1)
	int k = max_val - min_val + 1;
	array<int> count(k, 0);
    //   3. Count occurrences of each value
	for (int val : data) {
        count[val - min_val]++;
    }
    //   4. Overwrite data with sorted values using the counts
    int idx = 0;
    for (int i = 0; i < k; ++i) {
        while (count[i]-- > 0) {
            data[idx++] = i + min_val;
        }
	}
}

// ---------------------------------------------------------------------------
// Bucket Sort
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: cpp_diagrams.md #3 -- Steps 1a, 1b (Distribution Phase)
// ? SEE DIAGRAM: cpp_diagrams.md #4 -- Steps 2-3 (Sort + Concatenate)
//
void bucket_sort(std::vector<int>& data, int num_buckets) {
    // TODO: Implement bucket sort
    //   1. Find the min and max values to determine bucket ranges
    int min_val = *std::min_element(data.begin(), data.end());
    int max_val = *std::max_element(data.begin(), data.end());
	int range = max_val - min_val + 1;
    int range_per_bucket = ceil(range / num_buckets); // ceil division

	if (data.size() <= 1) return; // Already sorted
	if (max_val == min_val) return; // range 0
    //   2. Create num_buckets empty buckets (vectors)
	std::vector<std::vector<int>> buckets(num_buckets);

    //   3. Distribute each element into its bucket
    for (int val : data) {
		int idx = (val - min_val) / range_per_bucket;
		buckets[idx].push_back(val);
    }
    
    //   4. Sort each bucket (use insertion sort or std::sort)
    for (auto& bucket : buckets) {
        std::sort(bucket.begin(), bucket.end());
    }
    //   5. Concatenate all buckets back into data
    for (int val : bucket) {
		data[idx++] = val;
    }
}

// ---------------------------------------------------------------------------
// Radix Sort (LSD)
// ---------------------------------------------------------------------------
//
// ? SEE DIAGRAM: cpp_diagrams.md #5 -- Step 0 + Pass 1 Detail
// ? SEE DIAGRAM: cpp_diagrams.md #6 -- Passes 2-3 (Stability in Action)
//
void radix_sort(std::vector<int>& data) {
    // TODO: Implement radix sort (LSD)
    //   1. Find the maximum value to determine the number of digits
	int max_val = *std::max_element(data.begin(), data.end());
    //   2. For each digit position (ones, tens, hundreds, ...):
	for (exp = 1; max_val / exp > 0; exp *= 10) {
    //      a. Use counting sort on that digit
		int digit = (data[i] / exp) % 10; // Extract the digit

        count[digi]++;
		count[i] += count[i - 1]; // Cumulative count for stability
		output[count[digit] - 1] = data[i]; // Place in output array
        count[digit]--;
    //   3. After all digit passes, data is sorted
}

// ---------------------------------------------------------------------------
// Utility
// ---------------------------------------------------------------------------
void print_vector(const std::vector<int>& data, const std::string& label) {
    if (!label.empty()) std::cout << label << ": ";
    std::cout << "[";
    for (size_t i = 0; i < data.size(); ++i) {
        std::cout << data[i];
        if (i + 1 < data.size()) std::cout << ", ";
    }
    std::cout << "]" << std::endl;
}
