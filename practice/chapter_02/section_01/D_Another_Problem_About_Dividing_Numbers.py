import math
import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def pre_calc():
    primes = [1 for i in range(50000)]

    for i in range(4,50000,2):
        primes[i]=0
    for i in range(3,int(math.sqrt(50000))+1,2):  
        if(primes[i]==1):  
            for j in range(i*i,50000,2*i):  
                primes[j]=0

    primes = [i for i,v in enumerate(primes) if v==1 and i!=0 and i!=1]
    return primes

primes = pre_calc()

def find_factor(n):
    d = defaultdict(int)
    for p in primes:
        if p*p > n:
            break
        while n%p==0:
            d[p]+=1
            n//=p

    if n>1:    
        d[n] += 1
    return d

def solve():
    a,b,c = list(map(int, input().split()))

    if a==1 and b==1:
        print("NO")
        return

    d1 = find_factor(a)
    d2 = find_factor(b)

    n1, n2 = 0,0
    max_step = 0
    for n in d1:
        if d1[n] > d2[n]:
            n1 = 1
        max_step += d1[n]
    for n in d2:
        max_step += d2[n]
        if d2[n] > d1[n]:
            n2 = 1
    
    min_step = n1 + n2
    if a==b:
        min_step = 2

    if c < min_step or c > max_step:
        print("NO")
        return
    
    print("YES")


if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1