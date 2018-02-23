# 使用荷兰国旗算法的快速排序

对包含许多重复元素的使用快速排序进行高效地执行。
**例如**
>输入：{ 2, 6 , 5 , 2 , 6 , 8 , 6 , 1 , 2 , 6}
>输出：{ 1, 2 , 2 , 2 , 5 , 6 , 6 , 6 , 6 , 8}

## 执行方案

Quicksort对于包含许多重复元素的执行能力比较差。当所有元素全部相等时，问题更加明显。然后在每次循环时，左侧分区为空（没有值小于privot），右侧分区只减少一个元素（privot被移除）。因此对数组中包含相等值进行排序，该算法花费了二次时间。

为了解决这个问题，可以对数组进行分区，将数组分成三组：值小于privot，值等于privot，值大于privot。等于privot的值已经排序，所以只需要对小于和大于privot的分区进行排序。这种线性时间分区程序（linear-time partition routine）类似于荷兰国旗问题（Dutch national flag problem）的三路分区。

### 实现

```c++
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
```

该算法最好的情况就是，当所有元素（或者一个k<=n子集元素）全部相等。在所有元素相同的情况下，修改后的quicksort将在空数组上执行最多两次递归，从而在线性时间内完成。