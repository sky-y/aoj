package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

const MAX = 100000

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// 配列の要素を順番に出力
func trace(a [MAX]int, n int) {
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}

		fmt.Printf("%d", a[i])
	}
	fmt.Printf("\n")
}

func insertionSort(a [MAX]int, n int) {
	var v int
	var j int
	for i := 1; i < n; i++ {
		v = a[i]
		j = i - 1

		for (j >= 0) && (a[j] > v) {
			a[j+1] = a[j]
			j--
		}
		a[j+1] = v

		trace(a, n)
	}
}

func main() {
	// 空白文字を区切り文字としてトークンを切り出す設定
	sc.Split(bufio.ScanWords)

	n := nextInt()

	var a [MAX]int

	for i := 0; i < n; i++ {
		a[i] = nextInt()
	}

	trace(a, n)
	insertionSort(a, n)
}
