#include <stdio.h>

int findMajorityElement(int array[], int size) {
    // Base case: when the array contains only one element
    if (size == 1) {
        return array[0];
    }

    // Divide the array into two halves
    int mid = size / 2;
    int leftMajority = findMajorityElement(array, mid);
    int rightMajority = findMajorityElement(array + mid, size - mid);

    // If both halves have the same majority element, return it
    if (leftMajority == rightMajority) {
        return leftMajority;
    }

    // count the occurrences of the left and right majority elements
    int leftCount = 0, rightCount = 0;
    for (int i = 0; i < size; i++) {
        if (array[i] == leftMajority) {
            leftCount++;
        } else if (array[i] == rightMajority) {
            rightCount++;
        }
    }

    // Return the majority element of the entire array
    if (leftCount > size/2)
    {
        return leftMajority;
    }
    else if (rightCount > size/2)
    {
        return rightMajority;
    }
    else
    {
        return -1;
    }
}

int main() {
    int arr[] = {3, 3, 3, 2, 4, 4, 2, 1, 4};
    int size = sizeof(arr) / sizeof(arr[0]);
    int majorityElement = findMajorityElement(arr,size);
    printf("The majority element of the array is: %d\n", majorityElement);
    return 0;
}
