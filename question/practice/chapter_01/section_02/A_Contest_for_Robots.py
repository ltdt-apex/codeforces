import math
import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a1 = list(map(int, input().split()))
    a2 = list(map(int, input().split()))

    t1 = 0
    t2 = 0

    for i in range(n):
        if a1[i] == 1 and a2[i] != 1:
            t1 += 1
        if a1[i] != 1 and a2[i] == 1:
            t2 += 1
    
    if t1 == 0:
        print(-1)
        return

    print(t2//t1 + 1)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1