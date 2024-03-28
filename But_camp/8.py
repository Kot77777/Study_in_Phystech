import matplotlib.pyplot as plt

x = []
for i in range(10):
    x.append(2*i / 10)
y1 = [i for i in x]
y2 = [i**2 for i in x]
y3 = [i**3 for i in x]


plt.plot(x, y1, label = 'linear',
         marker='o', linestyle='-',
         color = 'red', linewidth=1)
plt.plot(x, y2, label = 'quadratic',
         marker='v', linestyle='--',
         color = 'blue', linewidth=1)
plt.plot(x, y3, label = 'cubic',
         marker='^', linestyle='-',
         color = 'green', linewidth=1)

plt.legend()
plt.show()
