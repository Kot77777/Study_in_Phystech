a = 67
b = 3
result = a*b + a**b
print(f'3. {result}')
print(f'5. {result:10.4f}')
print(f'6. {result:10.5e}')
print(f'6. {result:10.4E}')

file = open('text.txt', 'r') #но можно полный путь папки через \\
print(file.read())

with open('text.txt', 'r', encoding='utf8') as f: #более красиво
    print(f.read())

print(1, '\n', 3)

with open('text.txt', 'r', encoding='utf8') as f: #более красиво
    for line in f:                      #считать по строчкам
        print(line, end='')

