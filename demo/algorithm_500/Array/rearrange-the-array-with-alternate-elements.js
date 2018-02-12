function printArray (arr) {
    let str = ""
    for (let i = 0; i < arr.length; i++) {
        str += arr[i] + " "
    }
    console.log("[ " + str + "]")
}

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
console.log("The original array is :")
printArray(arr)

reArrangeArray(arr)

console.log("The rearranged array is :")
printArray(arr)