import numpy as np
# import warnings
# warnings.simplefilter('ignore')
T1 = 23
I_1 = (10**(-3))*np.array([10.6, 20.0, 30.1, 40.7, 50.7, 60.3]) #мА
U_n1 = np.array([0.22, 0.41, 0.62, 0.84, 1.05, 1.25])#В
R_n1 = U_n1/I_1
Q1 = U_n1*I_1
print("Это массив сопротивлений и мощностей:",R_n1, Q1 )
SR_Y= sum (R_n1)/6
print("Это среднее для у:", SR_Y)
SR_X= sum (Q1)/6
print("Это среднее для х:", SR_X)
SR_X_v_KVAD = SR_X**2
print("Это среднее х в квадрате:", SR_X_v_KVAD)
SR_Y_v_KVAD = SR_Y**2
print("Это среднее у в квадрате:", SR_Y_v_KVAD)
SR_PEREMNOZ = sum(R_n1 * Q1)/6
print("Это среднее от перемножений:", SR_PEREMNOZ)
SR_KVADRATOV_Y = sum(R_n1**2)/6
print("Это среднее квадратов у:", SR_KVADRATOV_Y)
SR_KVADRATOV_X = sum(Q1**2)/6
print("Это среднее квадратов x:", SR_KVADRATOV_X)
B = (SR_PEREMNOZ - SR_X*SR_Y)/(SR_KVADRATOV_X - SR_X_v_KVAD)
A = SR_Y - B * SR_X

POGRECH_B = (1/6**0.5)*((((SR_KVADRATOV_Y - SR_Y_v_KVAD)/(SR_KVADRATOV_X - SR_X_v_KVAD)) - B**2)**0.5)
POGRECH_A = POGRECH_B * ((SR_KVADRATOV_X - SR_X_v_KVAD)**0.5)

print(B, A)
print(POGRECH_B, POGRECH_A)