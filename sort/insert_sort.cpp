//
// Created by Kenway on 4/2/2021.
//


#include "sort.h"

int insert_sort(vector<int> &data) {
    int size = data.size(), tmp;
    for (int i = 0; i < size; ++i) {
        int j = i - 1;
        tmp = data[i];
        while (j >= 0 && tmp < data[j]) {
            data[j + 1] = data[j];
            j--;
        }
        data[j + 1] = tmp;
    }
}

int main() {
    vector<int> data = {1, 3, 2, 10, 8, 9, 4, 6, 5, 7};
    insert_sort(data);
    output_vector(data);
    return 0;

}