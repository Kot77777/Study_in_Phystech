import RPi.GPIO as GPIO
import time
def binary(n):
    return [int(i) for i in bin(n)[2:].zfill(8)]
GPIO.setmode(GPIO.BCM)
dac = [8, 11, 7, 1, 0, 5, 12, 6]
try:
    while True:
        n = int(input())
        k = n/510
        for i in range(256):
            print(i)
            time.sleep(k)
        for i in range(254, -1, -1):
            print(i)
            time.sleep(k)
finally:
    GPIO.output(dac, 0)
    GPIO.cleanup()