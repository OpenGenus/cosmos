package main

import  "fmt"


func max(x,y int) int {
	if x > y{
		return x
	}

	return y
}

func rod_cutting(prices []int) int {
	n := len(prices)
	max_prices := make([]int,n+1)
	max_prices[0] = 0
	var m int

	for i:=1;i<=n;i++{
		m = 0
		for j:=1;j<=i;j++{
			m = max(prices[j-1]+max_prices[i-j],m)
		}
		max_prices[i] = m
	}


	return max_prices[n]
}


func main(){

	prices := []int{1, 5, 8, 9, 10, 17, 17, 20}

	fmt.Println("Max possible value:",rod_cutting(prices))

}
