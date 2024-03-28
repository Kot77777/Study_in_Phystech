import matplotlib.pyplot as plt
from math import *
x = []
y = []
n = float(input())
count = 0
i = -n
while count!=1000:
    i += 0.1
    x.append(cos(i))
    y.append(sin(i) + 0.8*abs(cos(i)))
    i += 0.1
    count += 1

# plt.plot(x, y, label = 'linear',
#          marker='o', linestyle='-',
#          color = 'white', linewidth=1)

plt.scatter(x, y)
plt.show()