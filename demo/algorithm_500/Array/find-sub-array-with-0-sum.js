var Multimap = require('multimap');

function printMap (map) {
    let str = ""
    map.forEach((element) => {
        str += (element + " ")
    });
    console.log("[ " + str + "]")
}


function printMap (multimap) {
    console.log('-----Multi_map-------')
    let str = ""
    multimap.forEach((key , element , map) => {
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

const arr = [ 3, 4, -7, 3, 1, 3, 1, -4, -2, -2]

getZeroSumSubarray1(arr)
getZeroSumSubarray2(arr)
