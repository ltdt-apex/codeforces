import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    a = input().strip()
    ans = []

    for n in a:
        n = int(n)
        ans.append(min(n, 9-n))
    
    if ans[0]==0:
        ans[0] = 9
    print("".join(map(str,ans)))

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1