using System;
using System.Linq;
using System.Collections.Generic;

namespace RandomIsland
{
	class Program
	{
		static void Main(string[] args)
		{
			var IslandMap = new Dictionary<string, int>()
			{
				{"屋久島", 6},
				{"軍艦島", 6},
				{"種子島", 6},
				{"佐渡島", 6},
				{"小豆島", 6}
			};
			var islandMap = new Dictionary<string, int>(IslandMap);

			while(true)
			{
				Console.WriteLine("エンターキーを押してください\nリセット:reset");
				string str = Console.ReadLine();

				if(islandMap.Count == 0)
				{
					Console.WriteLine("お前の席ねぇから！\n");
					break;
				}else if(str != "reset"){
					Random rand = new Random();
					string key = islandMap.ElementAt(rand.Next(0, islandMap.Count)).Key;

					islandMap[key] -= 1;
					Console.WriteLine(key +"に座りましょう 空き"+ islandMap[key] +"\n");
					if(islandMap[key] == 0)
					{
						islandMap.Remove(key);
					}
				}else{
					islandMap = new Dictionary<string, int>(IslandMap);
					Console.WriteLine("\nリセットしました\n");
				}
			}
		}
	}
}

