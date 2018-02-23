//
//  Created by July on 8/2/18.
//  Copyright © 2018年 July. All rights reserved.
//

#include <iostream>

void sort (int arr[] , int n) {
    int zeros = 0;
    for (int i = 0; i < n; i ++) {
        if (arr[i] == 0) {
            zeros ++;
        }
    }
    
    int k = 0;
    while (zeros --) {
        arr[k++] = 0;
    }
    
    while (k < n) {
        arr[k++] = 1;
    }
}

void sort2 (int arr[] , int n) {
    int k = 0;
    
    for (int i = 0; i < n; i ++) {
        if (arr[i] == 0) {
            arr[k++] = 0;
        }
    }
    
    for (int j = k; j < n; j++) {
        arr[k++] = 1;
    }
}

void printArray (int arr[] , int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void swap (int arr[] , int i , int j) {
    arr[i] = (arr[j] ^= arr[i] ^= arr[j]) ^ arr[i];
}

void sort3 (int arr[] , int n) {
    int privot = 1;
    int j = 0;
    
    for (int i = 0; i < n; i ++) {
        if (arr[i] < privot) {
            swap(arr, i, j);
            j++;
        }
    }
}

int main () {
    int arr[] = {1 , 0 , 1 , 0 , 1 , 0 , 0 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "The original array is : ";
    printArray(arr , n);
    
    sort(arr , n);
    
    std::cout << "The rearranged array is : ";
    printArray(arr , n);

    int arr2[] = {1 , 0 , 1 , 0 , 1 , 0 , 0 , 1};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "The original array is : ";
    printArray(arr2 , m);
    
    sort2(arr2 , m);
    
    std::cout << "The rearranged array is : ";
    printArray(arr2 , m);

    int arr3[] = {1 , 0 , 1 , 0 , 1 , 0 , 0 , 1};
    int o = sizeof(arr3) / sizeof(arr3[0]);
    std::cout << "The original array is : ";
    printArray(arr3 , o);
    
    sort3(arr3 , o);
    
    std::cout << "The rearranged array is : ";
    printArray(arr3 , m);
}