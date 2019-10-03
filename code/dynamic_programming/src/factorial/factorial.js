function factorialize(number) {
  if (number == 0) {
    return 1;
  } else {
    return number * factorialize(number - 1);
  }
}

factorialize(5);
/*replace the value of 5 with whatever value you
 *want to find the factorial of
 */
