//
//  Created by July on 8/2/18.
//  Copyright © 2018年 July. All rights reserved.
//

#include <map>
#include <iostream>
#include <unordered_map>

void PrintOrderMap (std::map<int , int>& m) {
    std::cout << "[ ";
    for (auto it = m.begin(); it != m.end(); ++it ) {
        std::cout << it->second << " ";
    }
    std::cout << "]" << std::endl;
    
}

void getZeroSumSubarray1 (int A[] , int n) {
    for (int i = 0; i < n; i ++) {
        int sum = 0;
        std::map<int, int> map;
        map.insert(std::pair<int , int>(i , A[i]));
        
        for (int j = i; j < n; j ++) {
            map.insert(std::pair<int , int>(j , A[j]));
            
            sum += A[j];
            
            if (sum == 0) {
                PrintOrderMap(map);
            }
        }
    }
}

void getZeroSumSubarray2 (int A[] , int n) {
    // 创建一个空的multi_map存储所有总和相同的子数组的结束索引
    std::unordered_multimap<int, int> map;
    // 在map中插入 pair (0 , -1) ，防止当索引为0时，和为0 
    map.insert(std::pair<int , int>(0 , -1));
    
    int sum = 0;
    // 遍历数组
    for (int i = 0; i < n; i++) {
        sum += A[i];
        // 如果sum已经存在，那么至少有一个子数组和为0
        if (map.find(sum) != map.end()) {
            auto it = map.find(sum);

            
            while (it != map.end() && it->first == sum) {
                std::cout << "[ ";
                for (int j = it->second + 1; j <= i; j++) {
                    std::cout << A[j] << " ";
                }
                std::cout << "]" << std::endl;
                it ++;
            }
        }
        map.insert(std::pair<int , int>(sum , i));
    }
}

int main () {
    int A[] = {0 , 3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    int n = sizeof(A) / sizeof(A[0]);
    
    std::cout << "方法一" << std::endl;
    getZeroSumSubarray1(A , n);
    std::cout << "方法二" << std::endl;
    getZeroSumSubarray2(A , n);
}