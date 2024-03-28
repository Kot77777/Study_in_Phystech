import numpy as np
import matplotlib.pyplot as plt

with open("data.txt", "r") as data:
    tmp = [int(i) for i in data.read().split("\n")]
data_array = np.array(tmp)
num = np.arange(1, 192)
time_array = num*(1/23.731946900172023)
napr_array = data_array*0.0129

plt.plot(time_array, napr_array, alpha = 0.5, marker = "*", label = "V(t)", markevery=10, color = "red")
plt.minorticks_on()


print(time_array[190] - time_array[177])
plt.xlim([0, 9])
plt.ylim([0, 3])
plt.grid(which='major')
plt.grid(which='minor', linestyle=':')
plt.tight_layout()
plt.xlabel('Время, с', fontsize=10, fontweight='bold')
plt.ylabel('Напряжение, В', fontsize=10, fontweight='bold')

plt.legend()
plt.show()