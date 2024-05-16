from typing import List

class Solution:
    def exist(self, board: List[List[str]], word: str) -> bool:
        n,m = len(board), len(board[0])
        dirs = [(-1,0),(1,0),(0,-1),(0,1)]

        word = list(word)

        def dfs(i,j,cur,seen):
            if cur == word:
                return True
            if len(cur) > len(word):
                return False
            if i < 0 or i >= n or j < 0 or j >= m or (i,j) in seen:
                return False
            
            result = False
            for di,dj in dirs:
                cur.append(board[i][j])
                seen.add((i,j))
                result |= dfs(i+di,j+dj,cur, seen)
                seen.remove((i,j))
                cur.pop()

            return result

        for i in range(n):
            for j in range(m):
                if dfs(i,j,[],set()):
                    return True
                
        return False