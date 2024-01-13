import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():
    a,b,c,d = list(map(int, input().split()))

    print(max(abs(a-c), abs(1-c)) + max(abs(b-d), abs(1-d)))

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1