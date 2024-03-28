import RPi.GPIO as gpio
import time
from matplotlib import pyplot as plt

gpio.setmode(gpio.BCM)
leds = [2, 3, 4, 17, 27, 22, 10, 9]
dac = [8, 11, 7, 1, 0, 5, 12, 6]
bits = 8
levels = 2 ** bits
maxvoltage = 3.3
comp = 14
troyka = 13
gpio.setup(troyka, gpio.OUT)
gpio.setup(comp, gpio.IN)
gpio.setup(dac, gpio.OUT)
gpio.setup(leds, gpio.OUT)


def decimal2binary(a): 
    return [int(elem) for elem in bin(a)[2:].zfill(8)]


def adc():
    value_res = 0
    temp_value = 0
    for i in range(8):
        temp_value = value_res + 2 ** (8 - i - 1)
        signal = decimal2binary(temp_value)
        gpio.output(dac, signal)
        time.sleep(0.005)
        compval = gpio.input(comp)
        if compval == 0:
            value_res = value_res + 2 ** (8 - i - 1)
    return value_res


try:
    time_start = time.time()
    count = 0
    data = []
    data1 = []
    all_time = []
    voltage = 0
    gpio.output(troyka, 1)
    print('Зарядка конденсатора')
    while voltage <= 206:
        voltage = adc()
        print('Напряжение(В): ', voltage / 256 * 3.3)
        data.append(voltage / 256 * 3.3)
        data1.append(voltage)
        count += 1
        gpio.output(leds, decimal2binary(voltage))
        all_time.append(time.time() - time_start)
    gpio.output(troyka, 0)
    print('РАЗРЯДКА конденсатора')

    while voltage >= 195:
        voltage = adc()
        print('Напряжение(В): ', voltage / 256 * 3.3)
        data.append(voltage / 256 * 3.3)
        data1.append(voltage)
        count += 1
        gpio.output(leds, decimal2binary(voltage))
        all_time.append(time.time() - time_start)

    time_end = time.time()
    time_total = time_end - time_start
    print('Графики')

    plt.plot(all_time, data)
    plt.xlabel('Секунды')
    plt.ylabel('Напряжение')
    print('Запись в файл')
    data1_str = [str(item) for item in data1]
    with open('data.txt', 'w') as f:
        f.write("\n".join(data1_str))
    with open('settings.txt', 'w') as f:
        f.write('Частота дискретизации ' + str(count / time_total) + 'Гц' + "\n")
        f.write('Шаг квантования = 0.0129 В')

    print('Частота дискретизации (Гц):', count / time_total)
    print('Общая продолжительность эксперемента(С):', time_total)
    print('Шаг квантования АЦП (В): ', maxvoltage / 256)
    print('Завершение программы')
    print(data1)

finally:
    gpio.output(leds, 0)
    gpio.output(dac, 0)
    gpio.cleanup()
    plt.show()
