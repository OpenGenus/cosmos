// Part of cosmos from opengenus foundation

const isLeep = year => ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)


var startYear = 1990
var endYear = 2020

for(i = startYear; i<= endYear; i++) {
    if(isLeep(i)) {
        console.log(i)
    }
}
