import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n,m,a,b = list(map(int, input().split()))

    ans = 0
    if n%m:
        ans += min(a * (n%m), b)
    
    ans+=min(n//m*b, a*(n//m)*m)

    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1