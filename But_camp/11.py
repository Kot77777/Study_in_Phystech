import numpy as np
import matplotlib.pyplot as plt
x = np.linspace(-100, 100, 5)

def f(x):
    if x < 1:
        return -20
    if x>=1:
        return x ** 2

vec_f = np.vectorize(f)
y = vec_f(x)

#plt.plot(x, y)
#plt.show()

a = np.eye(5)
print(a)

z = np.linspace(0, 20, 300)
m = np.sin(z)

np.save('z.npy', z)
np.save('m.npy', m)

m[(m < 0) + (m > 0.8)] -= 2

plt.plot(z, m)
plt.show()

a = np.load('z.npy')
b = np.load('y.npy')

plt.plot(a, b)
plt.show()