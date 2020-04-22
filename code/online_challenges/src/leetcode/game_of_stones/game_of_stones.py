class Solution:
    def __init__(self):
        self.memo = [[-1 for _ in range(501)] for _ in range(501)]
    def stone(self,piles,start,end,turn):
        if start==end:
            return piles[start]
        if self.memo[start][end]!=-1:
            return self.memo[start][end]
        x = -self.stone(piles,start+1,end,not turn) + piles[start] + sum(piles[start+1:end+1])
        y = -self.stone(piles,start,end-1,not turn) + piles[end] + sum(piles[start:end])
        self.memo[start][end] = max(x,y)
        return max(x,y)
        
    def stoneGame(self, piles: List[int]) -> bool:
        a = self.stone(piles,0,len(piles)-1,True)
        
        return a> sum(piles)-a