import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))

    a.sort()

    if a[-1] >= a[-2] + a[-3]:
        print("NO")
        return
    
    a[-1], a[-2] = a[-2], a[-1]
    print("YES")
    print(*a)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1