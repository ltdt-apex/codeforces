import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n, b = list(map(int, input().split()))
    a = list(map(int, input().split()))

    a.sort()
    if b==0:
        if a[0] == 1:
            print(-1)
            return
        else:
            print(a[0]-1)
            return

    ans = a[b-1]
        
    if b != n and a[b] == a[b-1]:
        print(-1)
        return
    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1