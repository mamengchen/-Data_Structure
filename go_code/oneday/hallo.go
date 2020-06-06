package main

import "fmt"

var age = 10
var b = 12

var (
	ssh = 12345
	zh  = true
	str = "mmc"
)

const pi = 3.1415926
const (
	statusOk = 200
	notFound = 404
)

const (
	n1 = 100
	n2
	n3 = 200
	n4
)

const (
	a1 = iota
	a2
	a3
)

func main() {
	// fmt.Println("hallo world")
	// fmt.Println(age)
	// fmt.Println(b)
	// fmt.Println(ssh)
	// fmt.Println(pi)
	// fmt.Println(n1, n2, n3, n4)
	// fmt.Println(a1, a2, a3)

	var v1 = 101
	fmt.Printf("%d\n", v1)
	fmt.Printf("%b\n", v1)
	fmt.Printf("%o\n", v1)
	fmt.Printf("%x\n", v1)

	v2 := 077
	fmt.Printf("%d\n", v2)
	v3 := 0x1234
	fmt.Printf("%d\n", v3)
}
