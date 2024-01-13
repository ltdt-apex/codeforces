import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():
    # n = int(input())
    a,b = list(map(int, input().split()))

    print((a-1)*9+b)



if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1