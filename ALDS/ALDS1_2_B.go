// ALDS1_2_B: Selection Sort
package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

// スライスの要素を順番に出力
func trace(a []int, n int) {
	for i := 0; i < n; i++ {
		if i > 0 {
			fmt.Print(" ")
		}

		fmt.Printf("%d", a[i])
	}
	fmt.Printf("\n")
}

//

func selectionSort(a []int, n int) {
	count := 0

	for i := 0; i < n; i++ {
		minj := i

		for j := i; j < n; j++ {
			if a[j] < a[minj] {
				minj = j
			}
		}

		if i != minj {
			// swap
			tmp := a[i]
			a[i] = a[minj]
			a[minj] = tmp

			count++
		}

	}

	trace(a, n)
	fmt.Printf("%d\n", count)
}

func main() {
	// 空白文字を区切り文字としてトークンを切り出す設定
	sc.Split(bufio.ScanWords)

	n := nextInt()

	// スライス
	a := make([]int, n)

	for i := 0; i < n; i++ {
		a[i] = nextInt()
	}

	selectionSort(a, n)
}
