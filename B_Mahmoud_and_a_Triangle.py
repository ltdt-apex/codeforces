import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()

    for i in range(2, n):
        b,c,d = a[i-2:i+1]
        if b+c > d:
            print("YES")
            return
        
    print("NO")

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1