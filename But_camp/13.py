import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

x = np.linspace(-2, 2, 20)

def foo(x, a, b, c):
    return a * np.sin(b * x) + c

noise = np.random.rand(20) - 0.5
y = foo(x, 3, 2, 1) + noise

popt, pcov = curve_fit(foo, x, y)
plt.scatter(x, y)
plt.plot(x, foo(x, *popt), c='red')


plt.show()