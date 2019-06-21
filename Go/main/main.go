package main

import (
	"fmt"
	"math/rand"
	"time"
)

func main() {
	island := map[string]int{
		"小豆島": 6,
		"屋久島": 6,
		"種子島": 6,
		"軍艦島": 6,
		"佐渡島": 6,
	}

	var island_c = copy_map(island)

	fmt.Println("Please push the any key")

	for {
		if (len(island_c) == 0) {
			fmt.Println("お前の席ねぇから!!!!!!")
			island_c = copy_map(island)
		} else {
			var reset string
			fmt.Scanln(&reset)
			if (reset == "reset") {
				fmt.Println("席状態をリセットしました")
				island_c = copy_map(island)
				fmt.Scanln()
			}

			val := choice(island_c)

			fmt.Println(val, "に座りましょう")

			island_c[val] -= 1
			fmt.Println(island_c)
			if (island_c[val] == 0) {
				delete(island_c, val)
			}
		}
	}
}

func copy_map(idic map[string]int) map[string]int {
	dic := make(map[string]int)
	for key, value := range idic {
		dic[key] = value
	}
	return dic
}

func choice(m map[string]int) string {
	l := len(m)
	i := 0

	rand.Seed(time.Now().UnixNano())
	index := rand.Intn(l)

	ans := ""
	for k, _ := range m {
		if index == i {
			ans = k
			break
		} else {
			i++
		}
	}
	return ans
}

