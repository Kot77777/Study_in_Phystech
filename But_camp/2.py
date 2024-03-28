def is_prostoe(n):
    kol = 0
    for i in range(1, int((n)**0.5)+1):
        if n % i == 0:
            kol+=1
    if kol == 1:
        return True
    else: return False
a, b = int(input()), int(input())
d = max(a, b)
l = min(a, b)
while l != 0:
    f = l
    l = d%l
    d = f
print('НОД:', d)
print('НОК:', (a*b)//d)
i = int(input())
sp = []
t = total = 0
while i != -1:
  sp.append(i)
  i = int(input())
for i in range(len(sp)):
    if t <= sp[i]:
        t = sp[i]
    total += sp[i]
print('Максимум: ', t)
print('Среднее арифм', total/len(sp))
n = int(input('Введте n: '))
k = 0
i = 2
while k !=n :
    if is_prostoe(i) == True:
        k+=1
        print(i, end=' ')
    i+=1
print(end='\n')
for i in range(len(sp)-1, -1, -1):
    print(sp[i], end = ' ')
