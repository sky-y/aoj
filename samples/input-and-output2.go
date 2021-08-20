// bufio の Scanner を使う (1) 一行づつ読み込む
//
// Go 言語で標準入力から読み込む競技プログラミングのアレ --- 改訂第二版 - Qiita
// https://qiita.com/tnoda_/items/b503a72eac82862d30c6

package main

import (
	"bufio"
	"fmt"
	"os"
)

var sc = bufio.NewScanner(os.Stdin)

func nextLine() string {
	sc.Scan()
	return sc.Text()
}

func main() {
	s, t := nextLine(), nextLine()
	fmt.Println(s)
	fmt.Println(t)
}
