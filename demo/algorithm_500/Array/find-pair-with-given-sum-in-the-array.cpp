//
//  Created by July on 8/2/18.
//  Copyright © 2018年 July. All rights reserved.
//

#include <iostream>
#include <unordered_set>

bool zeroSumSubarray (int A[] , int n) {
    std::unordered_set<int> set;

    set.insert(0);
    
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        
        if (set.find(sum) != set.end()) {
            return true;
        } else {
            set.insert(sum);
        }
    }
    return false;
}

int main () {
    int A[] = {3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    int n = sizeof(A) / sizeof(A[0]);
    
    zeroSumSubarray(A, n) ?
        std::cout << "Subarray with 0 sum exists" << std::endl :
        std::cout << "Subarray do not exists" << std::endl;


}