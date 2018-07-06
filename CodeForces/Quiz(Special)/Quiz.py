# CodeForces Problem: http://codeforces.com/problemset/problem/337/C
# Made by: Anthony Dugarte through PapasFritas (codeforces.com/profile/PapasFritas)
#
# Note 1: It was a problem of "Maraton de practica ULA 2018" competition.
# Note 2: Python because of numeric limits
#       when input is "300 300 3" answer without module is 7605903601369376408980219232250

from sys import stdin

n, m, k = map(int, stdin.readline().split(' '))
doublesNeeded = int(m - (n - n / k))

score = 0
if doublesNeeded > 0:
    score = 1
    score <<= (doublesNeeded + 1)
    score *= k
    score -= 2 * k

if m > 0 and doublesNeeded >= 0:
    score += m - doublesNeeded * k
elif doublesNeeded < 0:
    score = m

score %= 1000000009
print(score)
