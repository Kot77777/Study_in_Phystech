import numpy as np
import matplotlib.pyplot as plt

x = np.linspace(-2, 2, 200)
y = x**2

noise = np.random.rand(200) - 0.5
y += noise

fig, ax = plt.subplots()

ax.scatter(x, y)

coefs = np.polyfit(x, y, 2)#создаем примерные коэффициенты

p = np.poly1d(coefs)#создает функцию по этим коэффициентам

fig2, ax2 = plt.subplots()

ax2.scatter(x, y)#создает точки
ax2.plot(x, p(x), c='red')#создает кривую

plt.show()