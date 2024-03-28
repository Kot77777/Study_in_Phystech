import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from scipy.optimize import curve_fit

x = []
y = []

p = np.loadtxt('TwoZonds.txt')
for i in range(len(p)):
    y.append(p[i][2])
    x.append(p[i][1])
x1 = np.array(x[:10])
y1 = np.array(y[:10])
x2 = np.array(x[80:90])
y2 = np.array(y[80:90])
x3 = np.array(x[-10:-1])
y3 = np.array(y[-10:-1])

coefs = np.polyfit(x, y, 30)#создаем примерные коэффициенты
p = np.poly1d(coefs)#создает функцию по этим коэффициентам

fig, ax = plt.subplots()

#ax.scatter(x, y)#создает точки
ax.plot(x, p(x), c='red')

def foo(x, k, b):
    return k*x + b
popt1, pcov1 = curve_fit(foo, x1, y1)
popt2, pcov2 = curve_fit(foo, x2, y2)
popt3, pcov3 = curve_fit(foo, x3, y3)
#ax.scatter(x1, y1)
#ax.plot(x1, foo(x1, *popt), c='green')

x1pr = np.array(x[:70])
y1pr = x1pr*popt1[0] + popt1[1]
x2pr = np.array(x[60:100])
y2pr = x2pr*popt2[0] + popt2[1]
x3pr = np.array(x[-80:-1])
y3pr = x3pr*popt3[0] + popt3[1]

ax.plot(x1pr, y1pr, c='green', label=f'k={popt1[0]}, b={popt1[1]}')
ax.plot(x2pr, y2pr, c='brown', label=f'k={popt2[0]}, b={popt2[1]}')
ax.plot(x3pr, y3pr, c='black', label=f'k={popt3[0]}, b={popt3[1]}')

ax.legend()
plt.show()