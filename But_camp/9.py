import numpy as np

x = [1.0, 2.0, 3.0]
a = np.array(x)
print(a)
a += 1
print(a)

b = np.array([[1, 2, 3], [2, 3, 4], [5, 6, 7]])
b += 1
print(b)

print("Dims", b.ndim)
print("Shape", b.shape)

print(f'{b=}')
print('Slice 1:', b[:, 0])
print('Slice 2: ', b[1, :])
print(b[1:])
print(b[1::-1])
print(b[:-1])