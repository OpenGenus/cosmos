
const isLeap = year => ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)

let startYear = 1990
let endYear = 2020

for(let i = startYear; i<= endYear; i++) {
    if(isLeap(i)) {
        console.log(i)
    }
}
