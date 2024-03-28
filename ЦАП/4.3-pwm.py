import RPi.GPIO as GPIO
GPIO.setmode(GPIO.BCM)
GPIO.setup(17, GPIO.OUT)
GPIO.setup(24, GPIO.OUT)
while True:
    n = int(input())
    m = GPIO.PWM(17, 50)
    p = GPIO.PWM(24, 50)
    m.start(n)
    p.start(n)
    input("press enter")
    m.stop()
    p.stop()
