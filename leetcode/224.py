class Solution:
    def calculate(self, s: str) -> int:
        lenS = len(s)
        notNumber = ['+', '-', ' ', '(', ')']
        
        def determineSign(num, stack):
            if not stack or stack.pop() == '+':
                return num
            else:
                return -num
                
        def getNumber(now):
            num = 0
            while now < lenS and s[now] not in notNumber:
                num *= 10
                num += int(s[now])
                now += 1
            return [num, now - 1]
        
        def calInsideParenthesis(now):
            sumInsideParenthesis = 0
            stack = []
            while now < lenS and s[now] != ')':
                if s[now] == '(':
                    parenthesisSum, now = calInsideParenthesis(now + 1)
                    sumInsideParenthesis += determineSign(parenthesisSum, stack)
                elif s[now] == '+' or s[now] == '-':
                    stack.append(s[now])
                elif s[now] != ' ':
                    tempSum, now = getNumber(now)
                    sumInsideParenthesis += determineSign(tempSum, stack)
                now += 1
            return [sumInsideParenthesis, now]
        
        return calInsideParenthesis(0)[0]
