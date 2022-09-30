class Solution:
    def solve(self , s: str, t: str) -> str:
        # write code here
        if s=='':
            return t
        elif t=='':
            return s
        else:
            s=int(s)
            t=int(t)
        return str(s+t)