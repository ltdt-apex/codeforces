import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()
    for i in range(1,n):
        if a[i] > a[i-1] + 1:
            print("NO")
            return
        
    print("YES")

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1