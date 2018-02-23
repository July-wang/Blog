# 使用高低交替的元素重新排列数组

给定一个整数数组，重新进行排列，使得数组的第偶数个元素同时大于其左侧的元素和右侧的元素。

`Tips:` 假设数组中没有重复的元素
**例如：**
给定数组：[1, 2, 3, 4, 5, 6, 7]
输出：[1, 3, 2, 5, 4, 7, 6]
给定数组：[9, 6, 8, 3, 7]
输出：[6, 9, 3, 8, 7]

## 实现方案

一个简单的解决办法是按照升序重新排列数组。然后取另一个数组，以交替顺序从两个断点开始填充。如下步骤：
> 1、按升序排列数组（假设没有重复元素）。
> 2、取两个循环变量 i 和 j 分别指向数组的两端。（i = 0 , j = n - 1）
> 3、创建辅助数组A。使用变量K进行循环
> 4、while(i < j)
A[k++] == arr[i++]
A[k++] == arr[j--]
> 5、打印A

这个方案的的时间复杂度是O(nlogn)

### c++实现

```c++
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
```

### Javascript实现

```Javascript
function swap (arr , a , b) {
    arr[a] = [arr[b] , arr[b] = arr[a]][0];
}

function reArrangeArray (arr) {
    for (let i = 1; i < arr.length; i += 2) {
        if (arr[i - 1] > arr[i]) {
            swap(arr , i - 1 , i)
        }

        if (i + 1 < arr.length && arr[i + 1] > arr[i]) {
            swap(arr , i + 1 , i)
        }
    }
}

const arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
reArrangeArray(arr)
```