class MinStack:

    def __init__(self):
        self.stack = []
        self.min_stack = []

    def push(self, v: int) -> None:
        if not self.min_stack or v <= self.min_stack[-1]:
            self.min_stack.append(v)
        self.stack.append(v)

    def pop(self) -> None:
        v = self.stack.pop()
        if v == self.min_stack[-1]:
            self.min_stack.pop()

    def top(self) -> int:
        return self.stack[-1]

    def getMin(self) -> int:
        return self.min_stack[-1]


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(val)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()