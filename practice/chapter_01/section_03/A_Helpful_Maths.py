import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    a = input().strip().split("+")

    a = list(map(int, a))

    a.sort()

    for i in range(len(a)):
        print(a[i], end ="")
        if i !=len(a)-1:
            print("+", end="")

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1