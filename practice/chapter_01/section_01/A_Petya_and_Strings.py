import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    a1 = input().lower()
    a2 = input().lower()

    if a1 < a2:
        print(-1)
    else:
        print(int(a1!=a2))


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1