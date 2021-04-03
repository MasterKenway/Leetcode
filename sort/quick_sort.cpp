//
// Created by Kenway on 4/3/2021.
//

#include "sort.h"

void quick_sort(vector<int> &data, int left, int right) {
    if (left < right) {
        int pivot = data[left], size = data.size(), j = left;
        for (int i = left + 1; i < right; ++i) {
            if (pivot > data[i]) {
                swap(data[j++], data[i]);
            }
        }
        data[j] = pivot;

        quick_sort(data, left, j);
        quick_sort(data, j + 1, right);
    }
}

int main() {
    vector<int> temp, data = {1, 3, 2, 10, 8, 9, 4, 6, 5, 7};
    quick_sort(data, 0, data.size());
    output_vector(data);
    return 0;
}