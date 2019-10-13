class Test 
{ 
    // method to find factorial of given number
    
    static int factorial(int n) 
    { 
        if (n == 0) 
          return 1; 
          
        return n*factorial(n-1); 
    } 