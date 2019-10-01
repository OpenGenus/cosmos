/*Part of cosmos by OpenGenus Foundation*/
export function get2sum(a: number, b: number): number {
    return a + b;
}

/* Tests */
console.log(get2sum(2, 3)); // should return 5
console.log(get2sum(10, 10)); // should return 20
console.log(get2sum(-2, -2)); // should return -4