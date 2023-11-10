package main

import (
	"fmt"
	"net"
)

func checkIP(ip string) bool {
	netIP := net.ParseIP(ip)
	if netIP.To4() == nil {
		fmt.Printf("%v is not an IPv4 address\n", ip)
		return false
	}
	fmt.Printf("%v is an IPv4 address\n", ip)
	return true
}

func main() {
	checkIP("1.2.3.4")
	checkIP("216.14.49.185")
	checkIP("1::16")
	checkIP("260.00.00.130")
}
