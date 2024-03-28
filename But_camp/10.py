import matplotlib.pyplot as plt
import numpy as np

print("arange:", np.arange(-5, 15, 2)) #итерировать

print("random:", np.random.random((2, 2))) #рандомный массив размером x*y

print("ones: ", np.ones((2, 2))) #создать массив 2 на 2 из единичек

print("ones: ", np.ones(10)) #создать массив из 10 единичек

print('full: ', np.full(10, 42.0))

print("linespace: ", np.linspace(0, 2, 6))

a = np.linspace(0, 100, 10)
print("min", np.min(a))

x = np.linspace(-100,100, 5)
y = np.abs(x)

plt.plot(x, y)
plt.show()

