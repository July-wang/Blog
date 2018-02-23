# 对只包含1 ，2，3的数组进行排序（荷兰三色国旗问题）

给定一个只包含1，2，3的数组，按线性时间数组进行排序并使用恒定的空间。
**例如**
>输入：{0,1,2,2,1,0,0,2,0,1,1,0}
>输出：{0,0,0,0,0,1,1,1,1,2,2,2}

## 解决方案一

简单的解决办法是执行计数排序，我们分别计算0，1和2的数量，然后按照正确的顺序将它们放入数组中。上述解决方案的时间复杂度为O(n)，但是需要循环2次遍历数组。

### 实现

```c++
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
    std::cout << zeroes << " " << ones << " "  << twoes << std::endl;
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
}
```

## 解决方案二

我们也可以使用另一个方法，仅在一次遍历中重新排列数组。我们把1看做为privot，将数组分成3个区间，值小于privot ，值等于privot，值大于privot。

> Below linear-time partition routine is similar to three-way Partitioning for Dutch national flag problem

### 方案二实现

```c++
#include <iostream>
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

    threeWayPartition(arr , n - 1);

    std::cout << "The rearranged array is : ";
    printArray(arr , n);
}
```

上述解决方案的时间复杂度为O(n) ，空间复杂度为O(1)。

查看：[使用荷兰国旗算法的快速排序](./quicksort-using-dutch-national-flag-algorithm.md)