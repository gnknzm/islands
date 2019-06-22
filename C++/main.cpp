#include <iostream>
#include <unordered_map>
#include <random>
#include <cstring>

using namespace std;

int main(){
	unordered_map<string, int> Island = {
		{"軍艦島", 6},
		{"小豆島", 6},
		{"種子島", 6},
		{"佐渡島", 6},
		{"屋久島", 6},
	};

	auto island = unordered_map<string, int>(Island);
	random_device rand;

	string fmem = "\nエンターキーを押してください\n reset でリセット\n";
	string smem = "に座りましょう 空き";

	for (;;){
		if (island.size() == 0) {
			printf("\n座席がゼロになったためリセットしました\n");
			island = unordered_map<string, int>(Island);
			continue;
		}
		auto item = island.begin();
		char rst[64];

		cout << fmem << endl;

		if (strcmp(fgets(rst, 64, stdin), "reset\n") != 0){
			advance(item, rand() % island.size());
			item->second -= 1;

			cout << item->first << smem << item->second << endl;
			if (item->second == 0) {
				island.erase(item->first);
			}
		}else{
			printf("\nリセットしました\n");
			island = unordered_map<string, int>(Island);
		}
	}

	return 0;
}

