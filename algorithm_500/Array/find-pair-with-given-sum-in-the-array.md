# 在数组中查找和为给定sum的两个数

给定一个未排序的整数数组，找到和为给定整数的两个数。

**例如：**
给定数组：arr = [8 , 7 , 2 , 5 , 3 , 1] , sum = 10
输出：
> Pair found at index 0 and 2: [8,2]
> Pair found at index 1 and 4: [7,3]

如果没有找到相对应的两个数。
输出：
> Pair not found

## 方法一

***

循环数组中的每一对，计算他们的和是否为给定的整数。

### 方法一 C++实现

```C++
#include <iostream>

void findPair (int arr[] , int n , int sum) {
    bool flag = false;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == sum) {
                flag = true;
                std::cout << "Pair found at index " << i <<" and " << j;
                std::cout << ": [" << arr[i] << "," << arr[j] << "]" << std::endl;;
            }
        }
    }
    if (!flag) {
        std::cout << "Pair not found" << std::endl;
    }
}

int main () {
    int arr[] = { 8 , 7 , 2 , 5 , 3 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    findPair( arr, n, sum);
}
```

### 方法一 Javascript实现

```Javascript
function findPair (arr , sum) {
    let flag = false
    for (let i = 0; i < arr.length; i++) {
        for (let j = i + 1; j < arr.length; j++) {
            if (arr[i] + arr[j] === sum) {
                flag = true
                console.log(`Pair found at index ${i} and ${j}: [ ${arr[i]} , ${arr[j]} ]`)
            }
        }
    }
    if (!flag) {
        console.log('Pair not found')
    }
}
```

上述方案的时间复杂度为$O({n^2})$ , 程序使用的辅助空间为$O(1)$ 。

## 方法二 使用排序

***

按照升序给数组进行排序，并通过两个索引（低和高）来降低搜索空间，这两个索引最初指向数组的两个端点。然后循环到低小于索引的位置，减少搜索空间。在循环的每一次迭代中。我们将指数低和高的元素的总数和期望的和和低的总和进行比较，如果总和小于所需的总数，那么我们的递减率高等于和大于期望的总和。最后，如果数组中找到对，则返回。

### 方法二 C++实现

```C++
#include <iostream>
#include <algorithm>

//打印查看排序后的数组
void printArray (int arr[] , int n) {
    std::cout << "The array is :[ ";
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] ;
        if (i != n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << " ] " << std::endl;
}

void findPair (int arr[] , int n , int sum) {
    bool flag = false;
    std::sort(arr , arr + n);
    printArray(arr , n);

    int low = 0;
    int hight = n -1;

    while (low < hight) {
        if (arr[low] + arr[hight] == sum) {
            flag = true;
            std::cout << "Pair found at index " << low <<" and " << hight;
            std::cout << ": [" << arr[low] << "," << arr[hight] << "]" << std::endl;
        }
        (arr[low] + arr[hight] < sum) ? low ++ : hight --;
    }
    if (!flag) {
        std::cout << "Pair not found" << std::endl ;
    }
}

int main () {
    int arr[] = { 8 , 7 , 2 , 5 , 3 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;
    findPair( arr, n, sum);
}
```

### 方法二 Javascript实现

```Javascript
function findPair (arr , sum) {
    let sortAry = arr.sort((a , b) => a - b) ,
        low = 0 ,
        hight = sortAry.length - 1 ,
        flag = true
    // 打印数组
    console.log(sortAry)

    while (low < hight) {
        if (arr[low] + arr[hight] === sum) {
            flag = true
            console.log(`Pair found at index ${low} and ${hight}: [ ${arr[low]} , ${arr[hight]} ]`)
        }
        (arr[low] + arr[hight] < sum) ? low ++ : hight --;
    }
    if (!flag) {
        console.log('Pair not found')
    }
}
```

上述方案的时间复杂度为$O({n \log n})$, 程序使用的辅助空间为${O(1)}$。

## 方法三 使用散列法

***

使用map可以在线性时间内轻松解决这个问题。将数据arr[i]的每个元素插入到map中。检查map是否存在(arr[i] , sum - arr[i])。如果存在，打印下来

### 方法三 C++实现

```c++
#include <iostream>
#include <unordered_map>
//打印map成员
void PrintUnOrderedMap (std::unordered_map<int , int>& m) {
    std::cout << "map contains:" << std::endl;

    for ( auto it = m.begin(); it != m.end(); ++it )
        std::cout << " " << it->first << ":" << it->second << std::endl;
}

void findPair (int arr[] , int n , int sum) {
    bool flag = false;

    std::unordered_map<int , int> map;

    for (int i = 0; i < n; i++) {
        // end成员返回指向容器尾元素的下一个位置的迭代器，也就是说end指示的是一个不存在的元素
        if (map.find(sum - arr[i]) != map.end()) {
            flag = true;
            std::cout << "Pair found at index " << map[sum - arr[i]] << " and " << i <<std::endl;
        }
        map[arr[i]] = i;
    }
    // 打印所有map成员
    PrintUnOrderedMap(map);

    if (!flag) {
        std::cout << "Pair not found" << std::endl;
    }
}

int main () {
    int arr[] = { 8 , 7 , 2 , 5 , 3 , 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 10;

    findPair( arr, n, sum);
}
```

### 方法三 Javascript实现

```Javascript
function printMap (map) {
    map.forEach((element , key) => {
        console.log(key + ": " + element)
    });
}
function findPair (arr , sum) {
    let myMap = new Map() ,
        flag = false

    for (let i = 0; i < arr.length; i++) {
        if (myMap.has(sum - arr[i])) {
            flag = true
            console.log(`Pair found at index ${ myMap.get(sum - arr[i]) } and ${i}`)
        }
        myMap.set(arr[i] , i)
    }
    printMap(myMap)
    if (!flag) {
        console.log('Pair not found')
    }
}
```

上述方案的时间复杂度为$O({n})$, 程序使用的辅助空间为$O({n})$。