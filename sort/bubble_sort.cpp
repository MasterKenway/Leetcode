//
// Created by Kenway on 4/2/2021.
//

#include "sort.h"

void bubble_sort(vector<int> &data) {
    int size = data.size();
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (data[j] > data[j + 1]) swap(data[j], data[j + 1]);
        }
    }
}

int main() {
    vector<int> data = {1, 3, 2, 10, 8, 9, 4, 6, 5, 7};
    bubble_sort(data);
    output_vector(data);
    return 0;
}