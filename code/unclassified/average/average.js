/* Part of Cosmos by OpenGenus Foundation */

// finds the average of an array of numbers.
function getAverage(numbers){
    var sum = 0;
    for(i=0;i < numbers.length; i++){
        sum += numbers[i];
    }
    return (sum / numbers.length);
}

nums = [10,20,30,40,50];
console.log(getAverage(nums));