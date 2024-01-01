import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    a = input()
    a = a[0].upper() + a[1:]
    print(a)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1