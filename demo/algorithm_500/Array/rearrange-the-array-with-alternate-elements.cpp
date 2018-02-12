//
//  Created by July on 8/2/18.
//  Copyright © 2018年 July. All rights reserved.
//

#include <iostream>

void printArray (int arr[] , int n) {
    std::cout << "[ ";
    for (int i = 0; i < n ; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

void swap (int arr[] , int i , int j ) {
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    //更简洁的办法
    //arr[i] = (arr[j]^=arr[i]^=arr[j])^arr[i];
}

void reArrangeArray (int arr[] , int n) {
    for (int i = 1; i < n; i += 2) {
        if (arr[i - 1] > arr[i]) {
            swap(arr , i - 1 , i);
        }
        
        if (i + 1 < n && arr[i + 1] > arr[i]) {
            swap(arr , i + 1 , i);
        }
    }
}

int main () {
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    std::cout << "The original array is : ";
    printArray(arr , n);
    
    reArrangeArray(arr , n);
    
    std::cout << "The rearranged array is : ";
    printArray(arr , n);
    
}