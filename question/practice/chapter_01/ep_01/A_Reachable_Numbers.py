import sys
sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())
    ans = set()

    while n!=0:
        if n in ans:
            break
        ans.add(n)
        n+=1
        while n%10==0:
            n//=10

    print(len(ans))


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1