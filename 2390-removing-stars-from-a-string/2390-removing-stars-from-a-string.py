class Solution:
    def removeStars(self, s: str) -> str:
        ans=[]
        for ch in s: 
            if (ch == '*') :
                ans.pop()
            else :
                ans.append(ch)
        return "".join(ans)    