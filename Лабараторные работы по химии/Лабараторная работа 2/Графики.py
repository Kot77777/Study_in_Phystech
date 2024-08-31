import numpy as np
import matplotlib.pyplot as plt
from matplotlib.ticker import AutoMinorLocator

T_28 = np.array([128.89, 66.81, 39.10, 27.21, 22.79])
T_38 = np.array([57.89, 32.14, 20.39, 15.57, 11.10])
C = np.array([0.01, 0.02, 0.03, 0.04, 0.05])
v_28 = 1/T_28
v_38 = 1/T_38

sr_C = sum(C)/5
sr_v_28 = sum(v_28)/5
sr_v_28_kv = sum(v_28**2)/5
sr_kv_v_28 = sr_v_28**2
sr_Cv_28 = sum(C*v_28)/5
sr_C_kv = sum(C**2)/5
sr_kv_C = sr_C**2
k1 = (sr_Cv_28 - sr_v_28*sr_C)/(sr_C_kv - sr_kv_C)
sigma_angle_1 = (1/(5**0.5))*(((sr_v_28_kv - sr_kv_v_28)/(sr_C_kv - sr_kv_C) - k1**2)**0.5)
print(k1, sigma_angle_1)

sr_C = sum(C)/5
sr_v_38 = sum(v_38)/5
sr_v_38_kv = sum(v_38**2)/5
sr_kv_v_38 = sr_v_38**2
sr_Cv_38 = sum(C*v_38)/5
sr_C_kv = sum(C**2)/5
sr_kv_C = sr_C**2
k2 = (sr_Cv_38 - sr_v_38*sr_C)/(sr_C_kv - sr_kv_C)
sigma_angle_2 = (1/(5**0.5))*(((sr_v_38_kv - sr_kv_v_38)/(sr_C_kv - sr_kv_C) - k2**2)**0.5)
print(k2, sigma_angle_2)

fig, ax = plt.subplots()

t = np.polyfit(C, v_28,  1)
f = np.poly1d(t)

ax.scatter(C, v_28, c="g", zorder = 1,)
ax.plot(C, f(C),
         linestyle='-', alpha = 1, label = 'T = 28℃',
         color = "g", ms=3, zorder = 0)

t1 = np.polyfit(C, v_38,  1)
f1 = np.poly1d(t1)
print(f1)

ax.scatter(C, v_38, c="orange", zorder = 1)
ax.plot(C, f1(C),
         linestyle='-', alpha = 1,
         color = "orange", ms=3, zorder = 0, label ='T = 38℃')

plt.minorticks_on()
plt.xlim([0, 0.06])
plt.ylim([0, 0.10])
listOf_Yticks = np.arange(0, 0.1, 0.01)
plt.yticks(listOf_Yticks)

listOf_Xticks = np.arange(0, 0.06, 0.01)
plt.xticks(listOf_Xticks)
plt.grid(which='major')
plt.grid(which='minor', alpha=0.5)
ax.xaxis.set_minor_locator(AutoMinorLocator(4))
ax.yaxis.set_minor_locator(AutoMinorLocator(2))
plt.xlabel('Концентрация реагентов, моль*л^(-1)', fontsize=10, fontweight='bold')
plt.ylabel('Скорость реакции, с^(-1)', fontsize=10, fontweight='bold')
plt.legend()
plt.savefig("График зависимости скорости реакции от концентрации реагентов", dpi=600)


plt.show()