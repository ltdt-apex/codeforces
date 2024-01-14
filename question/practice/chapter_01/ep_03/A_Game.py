import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
import math

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()
    print(a[math.ceil(n/2)-1])

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1