n = int(input())

s = 0
while n != 0:
    n-=1
    s += int(input()) % 128

print(s % 128)