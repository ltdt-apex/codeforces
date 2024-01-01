import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())

    a = [input() for _ in range(n)]
    
    ans = 0
    for x in a:
        if "-" in x:
            ans-=1
        else:
            ans+=1
    
    print(ans)

if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1