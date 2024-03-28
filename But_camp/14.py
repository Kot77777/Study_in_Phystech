import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt


#k = []
p = np.loadtxt('x_y.txt')

xi2 = np.array(p[0])
yi2 = np.array(p[1])

# with open('x_y.txt', 'r', encoding='utf8') as f: #более красиво
#     for line in f:                      #считать по строчкам
#         k.append(line)
# x = k[0].split(" ")
# y = k[1].split(" ")
# for i in range(len(x)):
#     x[i] = float(x[i])
# for i in range(len(y)):
#     y[i] = float(y[i])
# xi = np.array(x)
# yi = np.array(y)

plt.plot(xi2, yi2)

coefs = np.polyfit(xi2, yi2, 3)#создаем примерные коэффициенты

p = np.poly1d(coefs)#создает функцию по этим коэффициентам
fig2, ax2 = plt.subplots()

ax2.scatter(xi2, yi2)#создает точки
ax2.plot(xi2, p(xi2), c='red')#создает кривую

def foo(x, a, b, c, d):
    return a*x**3 + b*x**2 + c*x + d

popt, pcov = curve_fit(foo, xi2, yi2)
plt.scatter(xi2, yi2)
plt.plot(xi2, foo(xi2, *popt), c='red')

plt.show()