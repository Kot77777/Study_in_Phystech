import numpy as np
def matrix_mult(a, b):
    assert len(a) == len(b[0]), "Матрицы имеют недопустимые размеры"
    # Ваш код
    d = [[0, 0, 0], [0, 0, 0], [0, 0, 0]]
    for i in range(3):
        for j in range(3):
            for c in range(3):
                d[i][j] += (a[i][c]*b[c][j])
    return d
    pass
# Проверка
a = [
    [1, 2, 3],
    [4, 5, 6],
    [7, 8, 9],
]
b = [
    [5, 1, 2],
    [2, 3, 1],
    [1, 7, 2]
]
assert (matrix_mult(a, b) == np.array(a) @ np.array(b)).all(), "Что-то не так"
print('Всё ОК!')