//
// Created by Kenway on 4/2/2021.
//

#include "sort.h"

void merge(vector<int> &data, int left, int right, int mid, vector<int> &temp) {
    int i = left, j = mid + 1, cur = left;
    while (i <= mid && j <= right) {
        if (data[i] < data[j]) temp[cur++] = data[i++];
        else temp[cur++] = data[j++];
    }
    while (i <= mid) temp[cur++] = data[i++];
    while (j <= right) temp[cur++] = data[j++];
    copy(temp.begin() + left, temp.begin() + right + 1, data.begin() + left);
}

void merge_sort(vector<int> &data, int left, int right, vector<int> &temp) {
    if (left < right) {
        int mid = (left + right) / 2;
        merge_sort(data, left, mid, temp);
        merge_sort(data, mid + 1, right, temp);
        merge(data, left, right, mid, temp);
    }
}


int main() {
    vector<int> temp, data = {1, 3, 2, 10, 8, 9, 4, 6, 5, 7};
    temp.assign(data.size(), 0);
    merge_sort(data, 0, data.size() - 1, temp);
    output_vector(data);
    return 0;
}