class RecentCounter:
    
    def __init__(self):
        self.pings = []
        self.p = 0

    def ping(self, t: int) -> int:
        self.pings.append(t)
        while t - self.pings[self.p] > 3000:
            self.p += 1
        return len(self.pings) - self.p


# Your RecentCounter object will be instantiated and called as such:
# obj = RecentCounter()
# param_1 = obj.ping(t)