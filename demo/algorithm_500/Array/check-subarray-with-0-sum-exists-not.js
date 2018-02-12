/*
 *  Created by July on 8/2/18.
 *  Copyright © 2018年 July.
 * 
 */

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
