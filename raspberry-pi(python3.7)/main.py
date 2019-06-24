import RPi.GPIO as GPIO
import random
import sys
import time

#edit dict
islands = {
        "軍艦島" : 6,
        "屋久島" : 6,
        "小豆島" : 6,
        "種子島" : 6,
        "佐渡島" : 6,
        }
#Raspberry Pi Pin
GPIOPIN = 9
change_dict = islands.copy()

def selectIsland ():
    selectIsland = random.choice(list(change_dict.keys()))
    change_dict[selectIsland] -= 1
    if change_dict[selectIsland] is 0:
        del change_dict[selectIsland]
    return selectIsland

def main ():
    GPIO.setmode(GPIO.BCM)
    GPIO.setup(GPIOPIN, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

    try:
        while True:
            if GPIO.input(GPIOPIN) == GPIO.HIGH:
                print(selectIsland())
                if 0 == len(change_dict):
                    print('There is no seat')
                    break
            time.sleep(0.1)

    except KeyboardInterrupt:
        pass

    GPIO.cleanup()
    sys.exit()
if __name__ == "__main__":
    main()
