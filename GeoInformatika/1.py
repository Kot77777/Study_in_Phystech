import numpy as np
import pandas as pd
from sklearn.datasets import load_boston
def gauss_markov_decision(X, y):
    # Ваш код
    X_t = np.transpose(X)
    X_t_X = np.linalg.inv(X_t * X)
    return (X_t_X) * X_t * y

    pass
# Проверка

data_url = "http://lib.stat.cmu.edu/datasets/boston"
raw_df = pd.read_csv(data_url, sep="\s+", skiprows=22, header=None)
X = np.hstack([raw_df.values[::2, :], raw_df.values[1::2, :2]])
y = np.array(raw_df.values[1::2, 2])

true_gauss_markov_decision = np.array([-9.28965170e-02, 4.87149552e-02, -4.05997958e-03, 2.85399882e+00,
                                       -2.86843637e+00, 5.92814778e+00, -7.26933458e-03, -9.68514157e-01,
                                       1.71151128e-01, -9.39621540e-03, -3.92190926e-01, 1.49056102e-02,
                                       -4.16304471e-01])

assert np.allclose(gauss_markov_decision(X, y), true_gauss_markov_decision), "Что-то не так"
print('Всё ОК!')