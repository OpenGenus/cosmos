function factorialize(number) {            //function definition
  if (number == 0) {                        //base condition
    return 1;
  } else {
    return number * factorialize(number - 1);        //recursive call to factorialize 
  }
}

factorialize(num);                             
/*replace the value of num with whatever value you
 *want to find the factorial of
 */
