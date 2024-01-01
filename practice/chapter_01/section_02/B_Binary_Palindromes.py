import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline

def solve():
    n = int(input())

    cs = [0,0]
    odd = 0

    for i in range(n):
        a = input().strip()
        for j in range(len(a)):
            cs[int(a[j])] +=1
        if len(a)%2:
            odd += 1

    c = sum([c%2 for c in cs])

    if c==2 and odd < 2:
        print(n-1)
    else:
        print(n)

if __name__ == "__main__":
    test = 1
    test = int(input())
    while(test):
        solve()
        test-=1