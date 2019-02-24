// Part of Cosmos by OpenGenus Foundation

export default function countSetBits(n) {
  n = +n;

  if (!(n >= 0 || n < 0)) {
    return 0;
  } else if (n < 0) {
    throw new Error("negtive numbers are not supported");
  }

  let cnt = 0;
  while (n) {
    cnt++;
    n &= n - 1;
  }

  return cnt;
}
