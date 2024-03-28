import matplotlib.pyplot as plt

x = []
y = []
line = []
with open('test.txt', 'r', encoding='utf8') as f: #более красиво
    for line in f:             #считать по строчкам
        s = line.rstrip().split(sep=' ')
        #xi = float(line.split(' ')[0])
        #yi = float(line.split(' ')[1])
        y.append(float(s[0]))
        x.append(float(s[1]))
f.close()

plt.plot(y, x)
plt.show()