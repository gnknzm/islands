import random
import sys
#edit dict
islands = {
        "軍艦島" : 6,
        "屋久島" : 6,
        "小豆島" : 6,
        "種子島" : 6,
        "佐渡島" : 6,
        }

change_dict = islands.copy()
def selectIsland ():
    selectIsland = random.choice(list(change_dict.keys()))
    change_dict[selectIsland] -= 1
    if change_dict[selectIsland] is 0:
        del change_dict[selectIsland]
    return selectIsland

def main ():
    while True:
        input('push enter')
        print(selectIsland())
        if 0 == len(change_dict):
            print('There is no seat')
            break
    sys.exit()

if __name__ == "__main__":
    main()
