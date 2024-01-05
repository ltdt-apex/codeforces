import sys
# sys.setrecursionlimit(10**5+5)
input = sys.stdin.readline
from collections import defaultdict
import math

def is_prime(n):
    if n < 2:
        return False
    
    i = 2
    while i*i <= n:
        if n%i == 0:
            return False
        i+=1
        
    return True

def solve():
    n = int(input())
    if n == 3 or n == 5:
        print(1)
        print(n)
        return
    
    for i in range(1,300):
        num = n-i
        if is_prime(num):
            if i == 2:
                print(2)
                print(num, i)
                return
            for j in range(300):
                for k in range(300):
                    if is_prime(j) and is_prime(k) and j+k+num == n:
                        print(3)
                        print(num, j, k)
                        return


if __name__ == "__main__":
    test = 1
    # test = int(input())
    while(test):
        solve()
        test-=1