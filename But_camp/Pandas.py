import numpy as np
import pandas as pd

dict = {"A" : [1.1, 2.2, 3.3, 4.4, 5.5, 6.6],  #создали словарь
        "B": [1, 4, 9, 16, "25", 36],
        "C": [5, 2, 3, np.nan, 1, 4]}

df = pd.DataFrame(dict) #сделали таблицу

df.to_excel("foo.xlsx", index = False)
print(pd.read_excel("foo.xlsx"))

df.to_csv("foo.csv", index = False)
print(pd.read_csv("foo.csv"))

print(pd.read_excel("Laba.xlsx"))

print(df.dtypes) #ипы

print(df.head(2))
print(df.tail(2))

print(df.columns[1])

print(df.to_numpy())#в матрицу превращает

print(df.loc[3:, df.columns[1:]]) #обращение к Data frame

print(df.loc[df['A'] > 4]) #условие на столбец

print(df.iloc[3:, 1:])

print(df.at[3, 'B']) #обращение к ячейке

print(df.iat[1, 2]) #обращение к ячейке

print(df)
df = df.dropna(how='any') #удаляет None и строчку с None
print(df)

print(df.index) #выводит индексы\номер строки

#можно выполн арифм операции df.sum(); df.sort_values(by='C')


