# 在线性时间内对二进制数组进行排序、

给定一个二进制数组，按照限行时间和固定空间进行排序。

**例如：** 如下所示
> 已知： {1,0,1,0,1,0,0,1}
> 输出： {0,0,0,0,1,1,1,1}

## 解决方案

### 方法一

普通的解决方法是计算数组中存在的0的数量（k），并将数组的前K个索引填充0，剩下的所有索引填充1。
或者我们还可以计算数组中存在的1的个数（k），并将数组的前K个索引填充1，剩下的所有索引填充0。

#### c++实现

```c++
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

void printArray (int arr[] , int n) {
    std::cout << "[ ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << "]" << std::endl;
}

int main () {
    int arr[] = {1 , 0 , 1 , 0 , 1 , 0 , 0 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The original array is : ";
    printArray(arr , n);

    sort(arr , n);

    std::cout << "The rearranged array is : ";
    printArray(arr , n);
}
```

上述解决方案的时间复杂度为O(n) ，空间复杂度为O(1)。

### 方法二

循环数组，如果当前元素为0，我们可以将0放于数组的下一个有效的位置，而不是对0进行计数。

#### C++实现

```c++
#include <iostream>

void sort (int arr[] , int n) {
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

int main () {
    int arr[] = {1 , 0 , 1 , 0 , 1 , 0 , 0 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The original array is : ";
    printArray(arr , n);

    sort(arr , n);

    std::cout << "The rearranged array is : ";
    printArray(arr , n);
}
```

上述解决方案的时间复杂度为O(n) ，空间复杂度为O(1)。

## 方法三

我们也可以使用快速排序在线性时间内解决这个问题。方法是使用1作为中点元素进行一次分区，最后数组被排序。

### 使用c++解决

```c++
#include <iostream>

void swap (int arr[] , int i , int j) {
    arr[i] = (arr[j] ^= arr[i] ^= arr[j]) ^ arr[i];
}

void sort (int arr[] , int n) {
    int privot = 1;
    int j = 0;

    for (int i = 0; i < n; i ++) {
        if (arr[i] < privot) {
            swap(arr, i, j);
            j++;
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
    int arr[] = {1 , 0 , 1 , 0 , 1 , 0 , 0 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    std::cout << "The original array is : ";
    printArray(arr , n);

    sort(arr , n);

    std::cout << "The rearranged array is : ";
    printArray(arr , n);
}
```

上述解决方案的时间复杂度为O(n) ，空间复杂度为O(1)