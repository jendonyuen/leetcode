class MinStack:

    def __init__(self):
        self.stack = []
        self.minStack = [float('inf')]
        

    def push(self, x: int) -> None:
        self.stack.append(x)
        if x < self.minStack[-1]:
            self.minStack.append(x)
        else:
            self.minStack.append(self.minStack[-1])
        
    def pop(self) -> None:
        self.stack.pop()
        self.minStack.pop()
        

    def top(self) -> int:
        return self.stack[-1]
        

    def getMin(self) -> int:
        return self.minStack[-1]
        


# Your MinStack object will be instantiated and called as such:
# obj = MinStack()
# obj.push(x)
# obj.pop()
# param_3 = obj.top()
# param_4 = obj.getMin()