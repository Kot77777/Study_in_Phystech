import RPi.GPIO as GPIO
def binary(n):
    return [int(i) for i in bin(n)[2:].zfill(8)]
dac = [8, 11, 7, 1, 0, 5, 12, 6]
GPIO.setmode(GPIO.BCM)
GPIO.setup(dac, GPIO.OUT)
try:
    while True:
        n = (input())
        if n=="q":
            break
        if "-" in n:
            print("ввод отрицательного значения")
            continue
        if n[0] not in "0123456789":
            print("ввод не числового значения")
            continue
        if "." in n:
            print("ввод не целого числа")
            continue
        if int(n) > 255:
            print("ввод значения превышающего возможности 8-разрядного ЦАП")
            continue
        GPIO.output(dac, binary(int(n)))
        print("Предполагаемое значение напряжения: ", (3.3/256)*int(n), "В", sep="")
finally:
    GPIO.output(dac, 0)
    GPIO.cleanup()