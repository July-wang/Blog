/*
 *  Created by July on 8/2/18.
 *  Copyright © 2018年 July. 
 * 
 */

function findPair1 (arr , sum) {
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

function findPair2 (arr , sum) {
    let sortAry = arr.sort((a, b) => a - b) , 
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
function printMap (map) {
    map.forEach((element , key , map) => {
        console.log(key + ": " + element)
    });
}
function findPair3 (arr , sum) {
    let myMap = new Map() , 
        flag = false

    for (let i = 0; i < arr.length; i++) {
        if (myMap.has(sum - arr[i])) {
            flag = true
            console.log(`Pair found at index ${myMap.get(sum - arr[i])} and ${i}`)
        } 
        myMap.set(arr[i] , i)
    }
    printMap(myMap)
    if (!flag) {
        console.log('Pair not found')
    }
}

const arr = [8 , 7 , 2 , 5 , 3 , 1]
const sum = 10

findPair1(arr , sum)
findPair2(arr , sum)
findPair3(arr , sum)