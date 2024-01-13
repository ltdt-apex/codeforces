import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    a = [list(map(int, input().split())) for _ in range(5)]

    for i in range(5):
        for j in range(5):
            if a[i][j] == 1:
                print(abs(i-2) + abs(j-2))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1