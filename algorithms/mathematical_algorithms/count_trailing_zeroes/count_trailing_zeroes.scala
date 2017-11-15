//Part of Cosmos by OpenGenus Foundation
object Count_trailing_zeroes {
        def trailingZeroes(n : Int) : Int = {
                var result :Int = 0;
                var i :Int = 5;

                while(i<n){
                        result += n/i;
                        i*=5;
                }

                return result;
        }

        def main(args: Array[String]){
                var n :Int = 13;
                //to test
                //print("Enter number:\n")
                //n = (Console.readLine).toInt;
                println("Trailing zeroes in " + n + "! : " + trailingZeroes(n)+'\n');
        }
}
