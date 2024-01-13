import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math

def plain_factor(n):
    s = set()
 
    i = 2
    while i*i <= n:
        while n%i == 0:
            n//=i
            s.add(i)
        i+=1
    
    if n>1:
        s.add(n)
    return s

def solve():
    n,m = list(map(int, input().split()))
    con = defaultdict(set)
    on = defaultdict(set)

    for i in range(m):
        sym, num = input().strip().split()
        num = int(num)
        if sym == "+":
            if num in on:
                print("Already on")
                continue
            s = plain_factor(num)
            valid = True
            for n in s:
                if con[n]:
                    print("Conflict with", next(iter(con[n])))
                    valid=False
                    break
            if not valid:
                continue
            on[num] = s
            for n in s:
                con[n].add(num)
            print("Success")
        else:
            if num not in on:
                print("Already off")
            else:
                for n in on[num]:
                    con[n].remove(num)
                del on[num]
                print("Success")
                


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1