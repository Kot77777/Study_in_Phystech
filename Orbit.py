import numpy as np

def balilistics_right_part(t, y, y_body):
    position = y[3:6]
    velocity = y[0:3]
    #velocity_i = np.array([y_body[i][3:6] for i in range(len(y_body))])
    #mu = 6.67e-11*np.array([3.302e23, 4.8685e24, 5.9736e24,
                            # 6.419e23, 1.8986e27, 5.6846e26,
                            # 8.6832e25, 1.0243e26, 1.31e22,
                            # 1.9885e30])
    mu = np.array([3.30223, 4.868524, 5.973624,
                              6.41923, 1.898627, 5.684626,
                              8.683225, 1.024326, 1.3122,
                              1.988530])
    distance_i = np.array([np.linalg.norm(y_body[i] - position) for i in range(len(y_body))])
    result = np.zeros(6)
    result[0:3] = velocity
    k = 0
    for j in range(3):
        for i in range(len(y_body)):
            k += mu[i]*(y_body[i][j] - position[j])/(distance_i[i]**3)
        result[3 + j] = k
        k = 0
    #result[3:6] = [mu[i]*sum(y_body[i][j] - position[j])/(distance_i[i]**3) for i in range(len(y_body)) for j in range(3)]
    return result

def calc_step(t, y, y_body, delta_t, func):
    k_1 = func(t, y, y_body)
    k_2 = func(t + delta_t / 2, y + delta_t / 2 * k_1, y_body)
    k_3 = func(t + delta_t / 2, y + delta_t / 2 * k_2, y_body)
    k_4 = func(t + delta_t, y + delta_t * k_3, y_body)
    return y + (delta_t / 6) * (k_1 + 2 * (k_2 + k_3) + k_4)
def solve_ballistics(y_0, current_y_body, delta_t, final_time, func):
    current_y = y_0
    current_t = 0
    solutions = [current_y]
    times = [current_t]
    while times[-1] < final_time:
        current_y = calc_step(current_t, current_y, current_y_body, delta_t, func)
        solutions.append(current_y)
        current_t += delta_t
        times.append(current_t)
    return solutions, times

y_0 = np.array([0, 11, 0, 11, 11, 0])
current_y_body_0 = np.array([[1,  1, 0],[2, 2, 0], [3, 3, 0],
                            [4, 4, 0], [5, 5, 0], [-1, -1, 0], [-2, -2, 0],
                            [-3, -3, 0], [-4, -4, 0], [0, 0, 0]])
delta_t = 1
final_time = 1000
solutions, times = solve_ballistics(y_0, current_y_body_0, delta_t, final_time, balilistics_right_part)

solutions = np.array(solutions)
print(solutions[:, 3])
x_coords = solutions[:, 3]
y_coords = solutions[:, 4]
z_coords = solutions[:, 5]

import  matplotlib as plt

import numpy as np
import matplotlib.pyplot as plt

fig, ax = plt.subplots()

plt.plot(x_coords, y_coords)
plt.show()