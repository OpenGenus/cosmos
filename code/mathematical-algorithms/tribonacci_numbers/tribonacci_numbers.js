/* Part of Cosmos by OpenGenus Foundation */

const readline = require('readline');

const ioInterface = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

function tribonacii(number) {
    let a = 0,
        b = 0,
        c = 1,
        d;
    for (let i = 0; i < number - 3; i++) {
        d = a + b + c;
        console.log(`${d} `);
        a = b;
        b = c;
        c = d;
    }
}

ioInterface.question('Enter a number: ', (number) => {
    tribonacii(parseInt(number));
    ioInterface.close();
});
