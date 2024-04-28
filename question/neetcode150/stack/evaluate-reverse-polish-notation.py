from typing import List

class Solution:
    def evalRPN(self, a: List[str]) -> int:
        stack = []
        for n in a:
            if n.lstrip("-").isnumeric():
                stack.append(int(n))
            else:
                n2 = stack.pop()
                n1 = stack.pop()
                if n == "+":
                    n3 = n1+n2
                if n == "-":
                    n3 = n1-n2
                if n == "*":
                    n3 = n1*n2
                if n == "/":
                    if n1 * n2 < 0:
                        n3 = -(abs(n1)//abs(n2))
                    else:
                        n3 = n1//n2

                stack.append(n3)

        return stack[-1]
                