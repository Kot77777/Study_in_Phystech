import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

df = pd.read_excel("Laba.xlsx")

x = np.array(df["y1, мм"])
y = np.array(df["P01’ / P01"])

x1 = np.array(df["P01’, Па"])
y1 = np.array(df["y1, мм"])

coefs = np.polyfit(x, y, 5)#создаем примерные коэффициенты

p = np.poly1d(coefs)#создает функцию по этим коэффициентам

coefs1 = np.polyfit(x1, y1, 12)#создаем примерные коэффициенты

p1 = np.poly1d(coefs1)#создает функцию по этим коэффициентам

fig2, ax2 = plt.subplots(2, sharey=True)


ax2[0].scatter(x, y)#создает точки
ax2[0].plot(x, p(x), c='red')

ax2[1].scatter(x1, y1)
ax2[1].plot(x1, p1(x1), c='red')#создает кривую

plt.show()

