// fmt.Scan で軽快に読み込む
package main

import "fmt"

func main() {
	var a, b int
	fmt.Scan(&a)
	fmt.Scan(&b)
	fmt.Println(a)
	fmt.Println(b)
}
