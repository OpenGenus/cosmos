/**
Part of Cosmos by OpenGenus Foundation 
This method will convert a number into a roman numeral
@param {Number} num - number to convert
@return {String} - roman numeral of the number
*/

function convertToRoman(num) {
    const arr1 = [1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]
    const arr2 = ['M', 'CM', 'D', 'CD', 'C', 'XC', 'L', 'XL', 'X', 'IX', 'V', 'IV', 'I']
    let roman = ''
    for (let i = 0; i < arr1.length; i++) {
      if (num / arr1[i] >= 1) {
        num = num - arr1[i]
        roman = roman + arr2[i]
        i--
      }
    }
    return roman
  }