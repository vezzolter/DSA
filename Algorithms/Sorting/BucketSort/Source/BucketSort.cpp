// Source file for Bucket Sort
// by vezzolter
// August 03, 2024


#include <vector>
#include <algorithm> // sort();
#include <cmath>     // sqrt(); ceil();

#include "BucketSort.h"


int findMax(const std::vector<int>& arr) {
    return *std::max_element(arr.begin(), arr.end());
}

int findMin(const std::vector<int>& arr) {
    return *std::min_element(arr.begin(), arr.end());
}

void bucketSort(std::vector<int>& arr) {
    int n = arr.size();
    int nBuckets = static_cast<int>(std::ceil(std::sqrt(n)));

    int minVal = findMin(arr);
    int maxVal = findMax(arr);
    int rangePerBucket = (maxVal - minVal + 1) / nBuckets + 1;

    std::vector<std::vector<int>> buckets(nBuckets);
    for (int i = 0; i < n; ++i) {
        int idBucket = (arr[i] - minVal) / rangePerBucket;
        buckets[idBucket].push_back(arr[i]);
    }

    arr.clear();
    for (int i = 0; i < nBuckets; ++i) {
        std::sort(buckets[i].begin(), buckets[i].end());
        for (int j = 0; j < buckets[i].size(); ++j) {
            arr.push_back(buckets[i][j]);
        }
    }
}