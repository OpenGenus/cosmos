"use strict";
/* Part of Cosmos by OpenGenus Foundation */

/* How many numbers x are there in the range a to b?
* where the digit d occurs exactly k times in x?
*/

var d = 3;
var k = 5;
var val = -1;
var poscount = [];
poscount.length = 25;
var f = [];
f.length = 2;
var dp = [[[]]];
/* dp[pos][count][f] = Number of valid numbers <= b from this state
* pos = current position from left side (zero based)
* count = number of times we have placed the digit d so far
* f = the number we are building has already become smaller than b? [0 = no, 1 = yes]
*/

function check(num) {
  var count = 0;

  for (var i = 0; i < num.length; ++i) {
    if (num.charAt(i) - '0' == d) count++;
  }

  if (count == k) return 1;
  return 0;
}

function solve(num) {
  poscount.fill(val);
  f.fill(val);
  dp = poscount.map(function (e) {
    return poscount.map(function (e) {
      return f.map(function (e) {
        return e;
      });
    });
  });
  var ret = digit_dp(num, 0, 0, 0);
  return ret;
}

function digit_dp(num, pos, count, f) {
  if (count > k) return 0;

  if (pos == num.length) {
    if (count == k) return 1;
    return 0;
  }

  if (dp[pos][count][f] != -1) return dp[pos][count][f];
  var res = 0;
  var limit;

  if (f == 0) {
    /* Digits we placed so far matches with the prefix of b
    * So if we place any digit > num[pos] in the current position, then
    * the number will become greater than b
    */
    limit = num.charAt(pos) - '0';
  } else {
    /* The number has already become smaller than b.
    * We can place any digit now.
    */
    limit = 9;
  }

  for (var dgt = 0; dgt <= limit; ++dgt) {
    // Try to place all the valid digits such that the number does not exceed b
    var fNext = f;
    var countNext = count;
    if (f == 0 && dgt < limit) fNext = 1; // The number is getting smaller at this position

    if (dgt == d) countNext++;
    if (countNext <= k) res += digit_dp(num, pos + 1, countNext, fNext);
  }

  dp[pos][count][f] = res;
  return dp[pos][count][f];
}

var a = "100";
var b = "100000000";
var ans = solve(b) - solve(a) + check(a);
console.log(ans);