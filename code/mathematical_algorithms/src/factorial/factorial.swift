object RONALDO
{ 
    // Function to calculate 
    // factorial using Recursive  
    // formula (i.e N! = N * N-1 !) 
    def factorial(n: Int): Int =
    { 
        if (n == 0)  
            return 1
        else
            return n * factorial(n-1) 
    } 
  
    // Driver Code 
    def main(args: Array[String])  
    { 
        println(factorial(5)) 
    } 
} 