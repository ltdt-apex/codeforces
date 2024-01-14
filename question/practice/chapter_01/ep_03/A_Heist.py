import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    print(max(a) - min(a) + 1 - n)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1