#include <stdio.h>

int find_majority_element(int arr[], int n) {
    int count[n];
    for (int i = 0; i < n; i++) {
        count[i] = 0;
    }
    int majority = 0;
    int max_count = 0;
    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        if (count[arr[i]] > max_count) {
            majority = arr[i];
            max_count = count[arr[i]];
        }
    }
    if (max_count > n / 2) {
        return majority;
    } else {
        return -1;
    }
}

int main() {
    int arr[] = {3, 3, 4, 2, 4, 4, 2, 4, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    int majority_element = find_majority_element(arr, n);
    if (majority_element != -1) {
        printf("The majority element is %d\n", majority_element);
    } else {
        printf("There is no majority element in the array\n");
    }
    return 0;
}
