import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    a = list(map(int, input().split()))
    if 1 in a:
        print("hard")
    else:
        print("easy")

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1