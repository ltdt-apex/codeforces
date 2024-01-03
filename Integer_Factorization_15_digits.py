import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math

def find_primes(n):
    half = int(math.sqrt(n)) + 1
    primes = [1 for _ in range(half+1)]

    primes[0] = 0
    primes[1] = 0

    for i in range(4, len(primes), 2):
        primes[i] = 0
    for i in range(3, len(primes), 2):
        if not primes[i]:
            continue
        for j in range(i*i, len(primes), i*2):
            primes[j] = 0

    primes = [i for i, is_prime in enumerate(primes) if is_prime]
    return primes

primes = find_primes(1e16)

def factor(n):
    d = defaultdict(int)
    for i in primes:
        if i*i > n:
            continue
        while n%i == 0:
            d[i]+=1
            n//=i
    if n > 1:
        d[n] += 1
    return d

def solve():
    while True:
        n = int(input())
        if n == 0:
            return
        d = factor(n)
        print(" ".join(f"{k}^{v}" for k,v in d.items()))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1