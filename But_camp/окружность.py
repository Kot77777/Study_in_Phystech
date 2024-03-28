import numpy as np
import matplotlib.pyplot as plt
#plt.gca().set_aspect('equal')

k = np.linspace(-100, 100, 100000)
x = (2*k**2 - k)/((k-1)**2)
y = (k**3)/((k-1)**2)

fig, ax = plt.subplots()
ax.scatter(x,y)

#plt.plot(x, y)
plt.show()
