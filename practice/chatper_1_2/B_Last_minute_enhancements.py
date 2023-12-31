import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    ans = set()
    for x in a:
        if x in ans:
            ans.add(x+1)
        else:
            ans.add(x)
    print(len(ans))


if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1