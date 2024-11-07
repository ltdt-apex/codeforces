from sortedcontainers import SortedList

class Solution:
    def findXSum(self, v: List[int], k: int, x: int) -> List[int]:
        n = len(v)

        s = SortedList()
        d = defaultdict(int)
        l = 0
        t = 0
        a = []

        for r in range(len(v)):
            # print(r)
            # print(s)
            # print(t)

            b = v[r]
            size = d[b]
            d[b]+=1

            i = s.bisect_left((-size,-b))
            if i<len(s) and s[i] == ((-size,-b)):
                s.discard((-size,-b))

                if(i<=x-1):
                    t-=size*b

            s.add((-(size+1),-b))
            j = s.bisect_left((-size-1,-b))
            if(j<=x-1):
                t+=(size+1)*b

            if(j<=x-1 and not i<=x-1):
                t-=-s[x][0]*-s[x][1]


            # print(s)
            # print(t)

            if r>k-1:
                b = v[l]
                size = d[b]
                d[b]-=1

                i = s.bisect_left((-size,-b))
                if i<len(s) and  s[i] == ((-size,-b)):
                    s.discard((-size,-b))

                    if(i<=x-1):
                        t-=size*b

                s.add((-(size-1),-b))
                j = s.bisect_left((-size+1,-b))
                if(j<=x-1):
                    t+=(size-1)*b

                if(not j<=x-1 and i<=x-1):
                    t+=-s[x-1][0]*-s[x-1][1]

                l+=1

            # print(s)
            # print(t)

            if r>=k-1:
                a.append(t)

        return a