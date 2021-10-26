/* Part of Cosmos by OpenGenus Foundation */

function iterativeAverage(arr) {
    let sum = 0
    arr.forEach((eachnum, index) => {
        sum += eachnum
        console.log(`Average of ${index + 1} numbers is ${sum/(index + 1)}`)
    })
}

iterativeAverage([1, 9, 20, 13, 45])