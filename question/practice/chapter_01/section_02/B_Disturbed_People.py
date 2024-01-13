import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    ans = 0

    for i in range(1,n-1):
        if a[i-1]==1 and a[i] == 0 and a[i+1] == 1:
            a[i+1] = 0
            ans+=1

    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1