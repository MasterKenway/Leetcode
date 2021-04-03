//
// Created by Kenway on 4/3/2021.
//
#include "sort.h"


void heap_adjust(vector<int> &data, int cur, int tail) {
    int parent = cur, child = cur * 2 + 1, temp = data[cur];
    while (child < tail) {
        if (child + 1 < tail && data[child] < data[child + 1]) child++;
        if (data[child] > temp) {
            data[parent] = data[child];
            parent = child;
        } else {
            break;
        }
        child = child * 2 + 1;
    }
    data[parent] = temp;
}

void heap_sort(vector<int> &data) {
    int size = data.size();
    for (int i = (size - 1) / 2; i >= 0; --i) {
        heap_adjust(data, i, size);
    }

    for (int i = size - 1; i >= 0; --i) {
        swap(data[0], data[i]);
        heap_adjust(data, 0, i);
    }
}


int main() {
    vector<int> temp, data = {1, 3, 2, 10, 8, 9, 4, 6, 5, 7};
    heap_sort(data);
    output_vector(data);
    return 0;
}