// Part of Cosmos by OpenGenus Foundation

function count_digits(n)
{
    var numDigits = 0;
    var integers = Math.abs(n);

    while (integers > 0) {
        integers = (integers - integers % 10) / 10;
        numDigits++;
    }
    return numDigits;
}