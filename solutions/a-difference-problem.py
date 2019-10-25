from sys import stdin

for line in stdin:
    str = line.split(' ')
    a = int(str[0])
    b = int(str[1])
    print(abs(a - b))
