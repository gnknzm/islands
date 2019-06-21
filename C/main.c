#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

char Island[][256] = {
	"小豆島",
	"屋久島",
	"種子島",
	"軍艦島",
	"佐渡島",
};
int Island_limit[] = {6, 6, 6, 6, 6};

char rst[64];
int islandNum;
int rnd;

int main(void) {
	islandNum = sizeof(Island_limit)/sizeof(int);
	int island_limit[islandNum];
	for (int i = 0; i < islandNum; i++) {
		island_limit[i] = Island_limit[i];
	}
	for (;;) {
		srand(time(NULL));
		rnd = rand() % 5;

		printf("エンターキーを押してください\n reset でリセット\n\n");

		if (strcmp(fgets(rst, 64, stdin), "reset\n") != 0) {
			system("clear");
			if (island_limit[rnd] == 0) {
				printf("\n\n\n%s は満員です", Island[rnd]);
				continue;
			}
			island_limit[rnd] -= 1;
			printf("\n\n\n%s に座りましょう 空席: %d\n\n", Island[rnd], island_limit[rnd]);
		} else {
			for (int i = 0; i < islandNum; i++) {
				island_limit[i] = Island_limit[i];
			}
			system("clear");
			printf("\n\n\nリセットしました\n\n");
		}
	}

	return 0;
}

