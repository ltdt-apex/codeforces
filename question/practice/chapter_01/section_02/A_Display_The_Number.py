import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    # a = list(map(int, input().split()))
    if n%2:
        print("7" + "1"*(n//2-1))
    else:
        print("1"*(n//2))

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1