/* Part of Cosmos by OpenGenus Foundation */

// finds the average of an array of numbers.
// Using reduce function
function getAverage(numbers){
    var sum = numbers.reduce(function(sum, number) {
        return sum += number;
    }, 0);

    return (sum / numbers.length);
}

nums = [10,20,30,40,50];

console.log(getAverage(nums));
