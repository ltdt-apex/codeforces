import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math

def find_primes(n):
    # half = int(math.sqrt(n)) + 1
    half = n
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

primes = find_primes(1000)

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
    a, b = list(map(int, input().split()))

    ans = 0
    for j in range(1, len(primes)):
        if 1 + primes[j] + primes[j-1] > a:
            break
        if 1 + primes[j] + primes[j-1] in primes:
            ans+=1
    print("YES" if ans >= b else "NO")
    

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1