import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = input()
    n = n.count("4") + n.count("7")
    if all(n in ["4", "7"] for n in str(n)):
        print("YES")
    else:
        print("NO")

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1