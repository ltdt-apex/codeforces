import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    s =set()
    ans, cur = 0, 0
    for num in a:
        if num in s:
            cur -=1
        else:
            cur +=1
            s.add(num)

        ans = max(ans, cur)

    print(ans)
    

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1