import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    # a = list(map(int, input().split()))

    a = [[0 for i in range(n)] for j in range(n)]

    k = 1
    flip = False
    for j in range(n):
        for i in range(n):
            if flip:
                a[n-1-i][j] = k
            else:
                a[i][j] = k
            k+=1
        flip = not flip

    for i in range(n):
        for j in range(n):
            print(a[i][j], end=" ")
        print()

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1