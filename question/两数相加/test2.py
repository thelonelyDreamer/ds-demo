class Solution:
    def solve(self, s, t):
        # write code here
        full = 0  # 保存进位
        l1, l2 = len(s), len(t)
        length_max = max(l1, l2)
        result = ""
        for i in range(length_max):
            if i < l1:
                x1 = int(s[l1 - i - 1])
            else:
                x1 = 0
            if i < l2:
                x2 = int(t[l2 - i - 1])
            else:
                x2 = 0
            tem = x1 + x2 + full
            if tem >= 10:  # 判断进位
                full = 1
                result += str(tem - 10)
            else:
                full = 0
                result += str(tem)
        if full == 1:  # 判断首位是否进位
            result += "1"
        return result[::-1]