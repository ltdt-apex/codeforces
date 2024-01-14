import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    aa = [n%2 for n in a]

    if 1 in aa and 0 in aa:
        print(*sorted(a))
    else:
        print(*a)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1