//
//  Created by July on 8/2/18.
//  Copyright © 2018年 July. All rights reserved.
//

#include <iostream>

std::pair<int , int> Partition(int arr[] , int start , int end) {
    int mid = start , privot = arr[end];
    
    while (mid <= end) {
        if (arr[mid] < privot) {
            std::swap(arr[start], arr[mid]);
            ++ start;
            ++ mid;
        } else if ( arr[mid] > privot) {
            std::swap(arr[mid], arr[end]);
            -- end;
        } else {
            ++ mid;
        }
    }
    
    return std::make_pair(start - 1 , mid);
}

void quickSort (int arr[] , int start , int end) {
    if (start >= end) {
        return;
    }
    
    if ( start - end == 1) {
        if (arr[start] < arr[end]) {
            std::swap(arr[start], arr[end]);
        }
        return;
    }
    std::pair<int, int> pivot = Partition(arr, start, end);
    //对左侧分区进行排序
    quickSort(arr, start, pivot.first);
    //对右侧分区进行排序
    quickSort(arr, pivot.second, end);
}

void printArray (int arr[] , int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main () {
    int arr[] = { 2, 6 , 5 , 2 , 6 , 8 , 6 , 1 , 2 , 6};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "The original array is : ";
    printArray(arr , n);

    quickSort(arr , 0 , n-1);
    
    std::cout << "The rearranged array is : ";
    printArray(arr , n); 
}