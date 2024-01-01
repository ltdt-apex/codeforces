import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict

def solve():

    a,b,c,d,e = list(map(int, input().split()))

    if ((b+c)*a < (d-e) or (b-c)*a > (d+e)):
        print("No")
    else:
        print("Yes")



if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1