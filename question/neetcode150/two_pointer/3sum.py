from typing import List

class Solution:
    def threeSum(self, a: List[int]) -> List[List[int]]:
        a.sort()
        print(a)
        n = len(a)

        ans = []

        for i in range(n):
            n1 = a[i]
            if n1 > 0:
                break

            if i>0 and n1 == a[i-1]:
                continue

            l = i+1
            r = n-1

            while l < r:
                n2 = a[l]
                n3 = a[r]
                if n1+n2+n3 == 0:
                    ans.append([n1,n2,n3])
                    l+=1
                    r-=1
                    while r >=0 and a[r] == n3:
                        r-=1
                elif n1+n2+n3 > 0:
                    r-=1
                else:
                    l+=1

        return ans