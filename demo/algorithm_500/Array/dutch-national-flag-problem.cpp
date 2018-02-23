//
//  Created by July on 8/2/18.
//  Copyright © 2018年 July. All rights reserved.
//

#include <iostream>

void normalSort (int arr[] , int n) {
    int zeroes = 0 , ones = 0 , twoes = 0;
    for (int i = 0; i < n; i ++) {
        if (arr[i] == 0) {
            zeroes ++;
        }
        if (arr[i] == 1) {
            ones ++;
        }
        if (arr[i] == 2) {
            twoes ++;
        }
    }
    int k = 0;
    while (zeroes --) {
        arr[k++] = 0;
    }
    
    while (ones --) {
        arr[k++] = 1;
    }
    
    while (k < n) {
        arr[k++] = 2;
    }
}

void swap (int arr[] , int i , int j) {
    arr[i] = (arr[j] ^= arr[i] ^= arr[j]) ^ arr[i];
}

void threeWayPartition (int arr[] , int end) {
    int start = 0, mid  = 0;
    int privot = 1;
    
    while (mid <= end) {
        if (arr[mid] < privot) {
            swap(arr, start, mid);
            ++ start;
            ++ mid;
        } else if (arr[mid] > privot) {
            swap(arr , mid, end);
            -- end;
        } else {
            ++ mid;
        }
    }
}

void printArray (int arr[] , int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main () {
    int arr[] = {0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "The original array is : ";
    printArray(arr , n);

    normalSort(arr , n);
     
    std::cout << "The rearranged array is : ";
    printArray(arr , n);

    int arr2[] = {0, 1, 2, 2, 1, 0, 0, 2, 0, 1, 1, 0};
    int m = sizeof(arr2) / sizeof(arr2[0]);
    std::cout << "The original array is : ";
    printArray(arr2 , m);
    
    threeWayPartition(arr2 , n-1);
    
    std::cout << "The rearranged array is : ";
    printArray(arr2 , m);
    
}