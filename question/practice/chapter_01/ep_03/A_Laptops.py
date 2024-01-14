import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = []
    for i in range(n):
        a.append(list(map(int, input().split())))

    a.sort()
    for i in range(1,n):
        if a[i-1][1] > a[i][1]:
            print("Happy Alex")
            return

    print("Poor Alex")    


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1