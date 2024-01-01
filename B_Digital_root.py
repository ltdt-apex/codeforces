import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():
    a,b = list(map(int, input().split()))

    ans = 0
    for i in range(1,6):
        n1 = a//5 + a%5<=i
        n2 = b//5 + b%5<=5-i
        ans += n1 * n2
    print(ans)

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1