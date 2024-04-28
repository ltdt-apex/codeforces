from typing import List

class Solution:
    def findMedianSortedArrays(self, a1: List[int], a2: List[int]) -> float:
        if len(a1) > len(a2):
            a1,a2 = a2,a1

        n = len(a1)
        m = len(a2)

        i = -1
        l = n
        while l:
            while i+l < n and a1[i+l] <= a2[(n+m)//2-i-l-1]:
                i+=l
            l//=2

        j = (n+m)//2 - (i+1) - 1

        # print(a1, a2, i, j)

        if i == -1:
            mi = a2[j]
        elif j == -1:
            mi = a1[i]
        else:
            mi = max(a1[i],a2[j])
        if i == n-1:
            ma = a2[j+1]
        elif j == m-1:
            ma = a1[i+1]
        else:
            ma = min(a2[j+1],a1[i+1])

        # print(mi, ma)

        if (n+m)%2:
            return ma
        else:
            return (mi+ma)/2