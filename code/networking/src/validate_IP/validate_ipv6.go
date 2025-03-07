package main

import (
	"fmt"
	"net"
)

func checkIP(ip string) bool {
	netIP := net.ParseIP(ip)
	return netIP != nil && strings.Contains(ip, ":")
	fmt.Printf("%v is an IPv4 address\n", ip)
	return true
}

func main() {
	checkIP("1.2.3.4")
	checkIP("216.14.49.185")
	checkIP("1::16")
	checkIP("260.00.00.130")
}