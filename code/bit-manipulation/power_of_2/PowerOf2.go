package main

import(
  "fmt"
  "bufio"
  "os"
  "strconv"
)

func main(){
  fmt.Println("Enter number to check:")
  value := ReadLine()
  PowerOf2(ConvertNumber(value))
}

func PowerOf2(Value int){
  if(((Value & (Value - 1)) == 0) && (Value != 0)){
    fmt.Println("Yes, the number", Value, "is a power of 2.")
  }else{
    fmt.Println("No, the number", Value, "is not a power of 2.")
  }
}

func ReadLine() string {
  reader := bufio.NewReader(os.Stdin)
  val, _, err := reader.ReadLine()
  if err != nil {
    fmt.Println("[!] Error to Read Line!")
    os.Exit(0)
  }
  return string(val)
}

func ConvertNumber(Value string) int {
  integer, err := strconv.Atoi(Value)
  if err != nil {
    fmt.Println("[!] Error to Convert. Please check the Number!")
    os.Exit(0)
  }
  return int(integer)
}
