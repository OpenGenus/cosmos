function check(a, b) {
  let sum = 0;
  for (let i = 1; i < a; i++) {
    if (a % i == 0) {
      sum += i;
    }
  }
  if (sum == b) {
    return true;
  }
}

function ami_check(a, b) {
  if (check(a, b)) {
    if (check(b, a)) {
      console.log("Numbers are Amicable");
    } else {
      console.log("Numbers are not Amicable");
    }
  } else {
    console.log("Numbers are not Amicable");
  }
}

ami_check(17296, 18416);
