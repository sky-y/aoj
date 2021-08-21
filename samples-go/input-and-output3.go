// bufio の Scanner を使う (2) スペース区切りで読み込む
// 例：最初の整数 N に対して，それに続く N 個の整数の和を求めるプログラム
//
// Go 言語で標準入力から読み込む競技プログラミングのアレ --- 改訂第二版 - Qiita
// https://qiita.com/tnoda_/items/b503a72eac82862d30c6

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

func main() {
	// 空白文字を区切り文字としてトークンを切り出す設定
	sc.Split(bufio.ScanWords)

	n := nextInt()
	x := 0
	for i := 0; i < n; i++ {
		x += nextInt()
	}
	fmt.Println(x)
}
