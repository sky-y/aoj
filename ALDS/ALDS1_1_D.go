// ALDS1_1_D: Maximum Profit
package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
	"strconv"
)

var sc = bufio.NewScanner(os.Stdin)

const MAX = 200000

func nextInt() int {
	sc.Scan()
	i, e := strconv.Atoi(sc.Text())
	if e != nil {
		panic(e)
	}
	return i
}

func min(nums ...int) int {
	if len(nums) == 0 {
		panic("funciton min() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Min(float64(res), float64(nums[i])))
	}
	return res
}

func max(nums ...int) int {
	if len(nums) == 0 {
		panic("funciton max() requires at least one argument.")
	}
	res := nums[0]
	for i := 0; i < len(nums); i++ {
		res = int(math.Max(float64(res), float64(nums[i])))
	}
	return res
}

func main() {
	var R [MAX]int

	// 空白文字を区切り文字としてトークンを切り出す設定
	sc.Split(bufio.ScanWords)

	n := nextInt()
	for i := 0; i < n; i++ {
		R[i] += nextInt()
	}

	maxv := -2000000000 // 十分小さな値を初期値に設定
	minv := R[0]

	for i := 1; i < n; i++ {
		maxv = max(maxv, R[i]-minv)
		minv = min(minv, R[i])
	}

	fmt.Printf("%d\n", maxv)

}
