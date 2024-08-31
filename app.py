import numpy as np
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

def foo(x, a, b):
    return (b**2 * (1 - x**2/(a**2)))**0.5

#noise = np.random.rand(20) - 0.5
#y = foo(x, 3, 2, 1) + noise


popt, pcov = curve_fit(foo, x, y)
plt.scatter(x, y)
plt.plot(x, foo(x, *popt), c='red')


plt.show()