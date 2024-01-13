import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math

i = 1

def solve():
    global i
    a,b,c = list(map(int, input().split()))

    n = math.gcd(a,b)
    if c%n==0:
        print(f"Case {i}: Yes")
    else:
        print(f"Case {i}: No")
    
    i+=1

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1