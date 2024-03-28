import numpy as np
import matplotlib.pyplot as plt
from time import *
from math import *
total = 0
x = np.arange(1, 500)
y = []
y2 = []
dec = [3, 1, 4, 1, 5, 9, 2, 6, 5, 3, 5]
for i in range(1, 500):
    for j in range(0, i):
        total += (1/((4*j + 1)*(4*j + 3)))
    y.append(total)
    total = 0
print(0)
i = 0
tot1=0
t1 = []
y1 = 8*np.array(y)
for j in range(0, 11):
    start = perf_counter()
    while (int(y1[i]*(10**j)) % 10 != dec[j]):
        if i < 498:
            i += 1
        else:
            break
    end = perf_counter()
    tot1 += (end - start)
    t1.append(tot1)

for i in range(2, 501):
    for j in range(1, i):
        total += (((-1)**(j+1))/(j*(j+1)*(2*j + 1)))
    y2.append(total)
    total = 0
t2 = []
tot2=0
i = 0
y3 = 3 + np.array(y2)
for j in range(0, 11):
    start = perf_counter()
    while (int(y3[i]*(10**j)) % 10 != dec[j]):
        if i < 498:
            i += 1
        else:
            break
    end = perf_counter()
    tot2 += (end - start)
    t2.append(tot2)

y5 = []
for i in range(2, 501):
    for j in range(1, i):
        total += (j*(2**j)*(factorial(j))**2)/((factorial(2*j)))
    y5.append(total)
    total = 0
y6 = -3 + np.array(y5)
i = 0
t3=[]
tot3 = 0
for j in range(0, 11):
    start = perf_counter()
    while (int(y6[i]*(10**j)) % 10 != dec[j]):
        if i < 498:
            i += 1
        else:
            break
    end = perf_counter()
    tot3 += (end - start)
    t3.append(tot3)
print(t1)
fig, axs = plt.subplots(nrows= 1 , ncols= 2)
p = [i for i in range(11)]
axs[0].set_ylim(3.13, 3.15)
axs[0].plot(x, y1, label = 'метод 1')
axs[0].plot(x, y3, label = 'метод 2')
axs[0].plot(x, y6, label = 'метод 3')
axs[1].plot(p, t1, label = 'метод 1')
axs[1].plot(p, t2, label = 'метод 2')
axs[1].plot(p, t3, label = 'метод 2')
axs[0].set_xlabel('n')
axs[0].set_ylabel('значения для соответствующего n')
axs[1].set_xlabel('номер десятичного знака')
axs[1].set_ylabel('время получения в с')
axs[0].legend()
axs[1].legend()
#plt.plot(x, y)
plt.show()