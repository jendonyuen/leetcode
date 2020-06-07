class BrowserHistory:
    history = []
    cur = 0

    def __init__(self, homepage: str):
        self.history = [homepage]
        self.cur = 0
        
    def visit(self, url: str) -> None:
        if self.cur != len(self.history) - 1:
            self.history = self.history[:self.cur+1]
        self.history.append(url)
        self.cur += 1


    def back(self, steps: int) -> str:
        # print("back", steps, self.cur, self.history)
        self.cur -= steps
        if self.cur < 0:
            self.cur = 0
        # print("return", self.history[self.cur])
        return self.history[self.cur]

    def forward(self, steps: int) -> str:
        self.cur += steps
        if self.cur >= len(self.history):
            self.cur  = len(self.history) - 1
        return self.history[self.cur]


# Your BrowserHistory object will be instantiated and called as such:
# obj = BrowserHistory(homepage)
# obj.visit(url)
# param_2 = obj.back(steps)
# param_3 = obj.forward(steps)