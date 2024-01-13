import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():
    n = int(input())
    # a = list(map(int, input().split()))

    if n ==1 or n==2:
        print(-1)
        return
    
    if n%2:
        print(((n*n-1)//2), ((n*n+1)//2))
    else:
        print((n*n//4-1), (n*n//4+1))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1