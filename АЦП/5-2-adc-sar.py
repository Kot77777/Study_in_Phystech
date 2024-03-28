import RPi.GPIO as GPIO
import time
def binary(n):
    return [int(i) for i in bin(n)[2:].zfill(8)]
def adc(troyka):
    value = 0
    for i in range(7, -1, -1):
        value += 2**i
        GPIO.output(dac, binary(value))
        time.sleep(0.0005)
        if GPIO.input(comp) == 1:
            value -= 2**i
    return value
dac = [8, 11, 7, 1, 0, 5, 12, 6]
comp = 14
troyka = 13
GPIO.setmode(GPIO.BCM)
GPIO.setup(dac, GPIO.OUT)
GPIO.setup(troyka, GPIO.OUT, initial=GPIO.HIGH)
GPIO.setup(comp, GPIO.IN)
while True:
    for i in range(256):
        time.sleep(0.005)
        GPIO.output(dac, binary(i))
        napr_dac = (3.3/256)*i
        compvalue = GPIO.input(comp)
        if compvalue == 1:
            print("Напряжение на тройке-модуль способ 1:",binary(i), napr_dac)
            break
    print("Напряжение на тройке-модуль способ 2:", binary(adc(comp)), adc(comp)/256*3.3)  