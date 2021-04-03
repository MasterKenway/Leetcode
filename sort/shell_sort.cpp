//
// Created by Kenway on 4/2/2021.
//
#include "sort.h"

void shell_sort(vector<int> &data, int interval) {
    int tmp, k, size = data.size();
    for (int i = interval; i < size; ++i) {
        tmp = data[i];
        k = i - interval;
        while (k >= 0 && tmp < data[k]) {
            data[k + interval] = data[k];
            k -= interval;
        }
        data[k + interval] = tmp;
    }
}



int main() {
    vector<int> data = {1, 3, 2, 10, 8, 9, 4, 6, 5, 7};
    int size = data.size(), interval = 3;
    while (interval > 0) {
        shell_sort(data, interval);
        interval--;
    }
    output_vector(data);
    return 0;
}