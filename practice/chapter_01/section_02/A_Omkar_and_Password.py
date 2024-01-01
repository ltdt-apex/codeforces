import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    input()
    a = list(map(int, input().split()))

    m = max(a)
    for n in a:
        if m != n:
            print(1)
            return
    print(len(a))

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1