# 找出数组中所有和为0的子数组

`Tips:` 本文中的子数组为连续子数组

给定一个整数数组，打印出该数组中所有的和为0的子数组。
**例如：**
给定数组： [3, 4, -7, 3, 1, 3, 1, -4, -2, -2]
输出：
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

## 实现方案一(循环实现)

该方案是考虑所有的子数组，计算总和。如果子数组总和等于0，则打印出来。原始解的时间复杂度为$O{(n^3)}$，因为有${n^2}$个子数组，需要花费$O{(n)}$时间来查找其元素的总和。该方法可以通过在固定的时间内计算子数组的和来优化运行在$O{(n^2)}$时间。

### C++实现

```C++
#include <iostream>
#include <map>

void PrintOrderMap (std::map<int , int>& m) {
    std::cout << "[ ";

    for (auto it = m.begin(); it != m.end(); ++it ) {
        std::cout << it->second << " ";
    }

    std::cout << "]" << std::endl;
}

void getZeroSumSubarray (int A[] , int n) {
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

int main () {
    int A[] = {0 , 3, 4, -7, 3, 1, 3, 1, -4, -2, -2};
    int n = sizeof(A) / sizeof(A[0]);

    getZeroSumSubarray(A , n);
}
```

### Javascript实现

```javascript
function printMap (map) {
    let str = ""
    map.forEach((element) => {
        str += (element + " ")
    });
    console.log("[ " + str + "]")
}
function getZeroSumSubarray1 (arr) {
    for (let i = 0; i < arr.length; i++) {
        let map = new Map() ,
            sum = 0
        map.set(i , arr[i])

        for (let j = i; j < arr.length; j++) {
            map.set(j , arr[j]);
            sum += arr[j]

            if (sum === 0) {
                printMap(map)
            }
        }
    }
}
const arr = [0 , 3, 4, -7, 3, 1, 3, 1, -4, -2, -2]
getZeroSumSubarray1(arr)
```

## 实现方案二（使用multimap打印所有的子数组）

使用multimap打印给定的数组中所有和为0的子数组。方法是创建一个空的multimap存储符合条件的子数组的最后一个索引。

### C++实现二

```C++
#include <iostream>
#include <unordered_map>

void getZeroSumSubarray1 (int A[] , int n) {
    std::unordered_multimap<int, int> map;

    map.insert(std::pair<int , int>(0 , -1));

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += A[i];
        if (map.find(sum) != map.end()) {
            auto it = map.find(sum);

            while (it != map.end() && it->first == sum) {
                // 打印数组
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

    getZeroSumSubarray1(A , n);
}
```

### Javascript实现二

```Javascript
function getZeroSumSubarray2 (arr) {
    let map = new Multimap() ,
        sum = 0 ;
    // 为了防止数组索引为0时sum=0，map插入成员（0 ， -1）
    map.set(0 , -1)

    // 遍历数组
    for (let i = 0; i < arr.length; i++) {
        sum += arr[i]
        // 如果map中存在sum，那么至少有一个子数组的和为0
        if (map.has(sum)) {
            let it = map.get(sum) , 
                num = 0
            while(num < it.length) {
                let str = ''
                for (let k = it[num] + 1; k <= i; k++) {
                    str += arr[k] + ' '
                }
                console.log('[ ' + str + ']')
                num ++
            }
        }
        map.set(sum , i);
    }
}
```
