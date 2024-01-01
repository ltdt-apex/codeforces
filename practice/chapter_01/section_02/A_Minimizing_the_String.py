import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(input().strip())
    
    for i in range(1, n):
        if a[i-1] > a[i]:
            print("".join(a[:i-1]) + "".join(a[i:]))
            return
    print("".join(a[:n-1]))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1