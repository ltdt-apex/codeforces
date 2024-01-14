import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    a,b,c = list(map(int, input().split()))

    print(min(a,b)*2 + c * 2 + int(a!=b))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1