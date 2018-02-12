# 检测数组中是否存在和为0的子数组

`Tips:` 本文中的子数组为连续子数组

给定一个数组，检测数组中是否包含了和为0的子数组。
**例如：**
给定数组： [3, 4, -7, 3, 1, 3, 1, -4, -2, -2]
输出：
> Subarray with 0 sum exists
> The sub-arrays with 0 sum are:
{ 3, 4, -7 }
{ 4, -7, 3 }
{ -7, 3, 1, 3 }
{ 3, 1, -4 }
{ 3, 1, 3, 1, -4, -2, -2 }
{ 3, 4, -7, 3, 1, 3, 1, -4, -2, -2 }

如果没有找到相对应的两个数。
输出：
> Subarray with 0 not exists

## 解决方案

我们可以快速地使用hash解决这个问题，方案是使用set来检测给定的数组中是否存在具有和为0的子数组。遍历给定的数组，直到看到元素的总和。

### C++ 实现

```C++
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
```

### Javascript 实现

```Javascript
function CheckZeroSumSubarray (arr) {
    let set = new Set() ,
        sum = 0

    set.add(0);
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i]

        if (set.has(sum)) {
            return true
        } else {
            set.add(sum)
        }
    }
    return false
}

const arr = [0 , 3, 4, -7, 3, 1, 3, 1, -4, -2, -2]

CheckZeroSumSubarray(arr) ?
    console.log("Subarray with 0 sum exists") :
    console.log("Subarray do not exists")
```

查看：[打印出全部子数组](./find-sub-array-with-0-sum.md)