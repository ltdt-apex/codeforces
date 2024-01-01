import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():
    a,b = list(map(int, input().split()))
    
    if a%2 != b%2 or b*b > a:
        print("NO")
    else:
        print("YES")
    
if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1