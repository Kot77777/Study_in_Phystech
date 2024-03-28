import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import AutoMinorLocator
import math

T = np.array([26.3, 26.4, 27.5, 29.3, 32.3, 33.8, 34])
T1 = np.array([34, 33.9, 33.65, 33.6, 33.5, 33.4, 33.4, 33.3, 33.3, 33.2, 33.1, 33.1, 33])
T2 = np.array([26.3, 26.3, 26.3, 26.3, 26.3, 26.3, 26.3, 26.3, 26.3, 26.3, 26.3, 26.3])
T3 = np.array([33.7, 33.6, 33.5, 33.4, 33.4, 33.3, 33.3, 33.2, 33.1, 33.1, 33])
T4 = np.array([26.3, 26.3])

dt = np.array([110, 120, 125, 130, 135, 140, 145])
dt1 = np.array([145, 150, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260])
dt2 = np.array([0, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110])
dt3 = np.array([160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260])
dt3_ = np.array([120, 160, 170, 180, 190, 200, 210, 220, 230, 240, 250, 260])
dt4 = np.array([0, 150])

fig, ax = plt.subplots()

plt.gcf().set_size_inches(15, 7.5)

t = np.polyfit(dt1, T1, 4)
f = np.poly1d(t)

t3 = np.polyfit(dt3, T3, 1)
f3 = np.poly1d(t3)

ax.scatter(dt2, T2, c="r", zorder = 1, marker = '*')
ax.plot(dt2, T2, label = 'Теоретический график', alpha = 1,
         color = 'black', ms=5, zorder = 0)

ax.scatter(dt, T, c="r", zorder = 1, marker = '*')
ax.plot(dt, T, label = 'Теоретический график', alpha = 1,
         color = 'black', ms=5, zorder = 0)

ax.scatter(dt1, T1, c="r", zorder = 1, marker = '*')
ax.plot(dt1, T1, label = 'Теоретический график', alpha = 1,
         color = 'black', ms=5, zorder = 0)

ax.plot(dt3_, f3(dt3_), label = 'Теоретический график', alpha = 1,
         color = 'green', ms=5, zorder = 0, markeredgewidth = 1)

ax.plot(dt4, T4, label = 'Теоретический график', alpha = 1,
         color = 'green', ms=5, zorder = 0, markeredgewidth = 1)

plt.arrow(x= 135 , y= 26.3 , dx= 0 , dy= f3(135) - 26.3 , head_width=0.5, head_length=0.3, linewidth=1, color='b', length_includes_head=True)
plt.arrow(x= 135 , y= f3(135) , dx= 0 , dy= -f3(135) + 26.3 , head_width=0.5, head_length=0.3, linewidth=1, color='b', length_includes_head=True)
plt.annotate('\u0394t = 7.518℃', xy = (137, (f3(135) + 26.3)/2))
plt.annotate('\u03C41', xy = (110, 26))
plt.annotate('\u03C42', xy = (160, 33.3))

print(f3(135) - 26.3)

plt.minorticks_on()
plt.xlim([0, 300])
plt.ylim([24, 37])
listOf_Yticks = np.arange(23, 37, 1)
plt.yticks(listOf_Yticks)

listOf_Xticks = np.arange(0, 310, 10)
plt.xticks(listOf_Xticks)
plt.grid(which='major')
plt.grid(which='minor', alpha=0.5)
ax.xaxis.set_minor_locator(AutoMinorLocator(10))
ax.yaxis.set_minor_locator(AutoMinorLocator(10))
plt.xlabel('Время, с', fontsize=10, fontweight='bold')
plt.ylabel('Температура, ℃', fontsize=10, fontweight='bold')
plt.savefig("График зависимости теплопроводности от температуры", dpi=600)

plt.show()