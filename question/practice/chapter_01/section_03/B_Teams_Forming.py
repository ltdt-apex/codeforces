import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()

    ans = 0

    for i in range(0,n,2):
        ans += a[i+1] - a[i]
    
    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1