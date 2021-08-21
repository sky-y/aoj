// ALDS1_2_A: Bubble Sort
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

func bubbleSort(a [MAX]int, n int) {
	// 逆の隣接要素が存在する
	var flag bool = true

	// 交換回数
	var count int = 0

	for flag {
		flag = false
		for j := n - 1; j >= 1; j-- {
			if a[j] < a[j-1] {
				// a[j] と a[j-1] を交換
				tmp := a[j]
				a[j] = a[j-1]
				a[j-1] = tmp

				flag = true
				count++
			}
		}
	}

	trace(a, n)
	fmt.Printf("%d\n", count)
}

func main() {
	// 空白文字を区切り文字としてトークンを切り出す設定
	sc.Split(bufio.ScanWords)

	n := nextInt()

	var a [MAX]int

	for i := 0; i < n; i++ {
		a[i] = nextInt()
	}

	bubbleSort(a, n)
}
