import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    a,b = list(map(int, input().split()))

    for i in range(b):
        if a%10:
            a-=1
        else:
            a//=10
    print(a)


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1