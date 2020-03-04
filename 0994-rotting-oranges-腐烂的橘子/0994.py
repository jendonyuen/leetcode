class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        goodOrgs = {}
        badOrgs = {}

        h = len(grid)
        if h == 0: return
        w = len(grid[0])
        if w == 0: return

        for y in range(h):
            for x in range(w):
                if grid[y][x] == 1:
                    goodOrgs[(y,x)] = None
                elif grid[y][x] == 2:
                    badOrgs[(y,x)] = None

        # 没有好橘子
        if len(goodOrgs) == 0:
                return 0

        time = 0
        lastGoodOrgsNumber = -1
        while len(goodOrgs) > 0:
            # print("len:", len(goodOrgs), lastGoodOrgsNumber)
            if lastGoodOrgsNumber == len(goodOrgs):
                # 无法腐烂完所有橘子
                return -1

            # 初始化本次腐烂过程
            lastGoodOrgsNumber = len(goodOrgs)
            newBadOrgs = {}

            for y, x in badOrgs.keys():
                # print(y, x)
                delGoodOrgs = []
                if y > 0:
                    if (y-1, x) in goodOrgs.keys():
                        delGoodOrgs.append((y-1, x))
                        newBadOrgs[(y-1,x)] = None
                if y < h - 1:
                    if (y+1, x) in goodOrgs.keys():
                        delGoodOrgs.append((y+1, x))
                        newBadOrgs[(y+1,x)] = None
                if x > 0:
                    if (y, x-1) in goodOrgs.keys():
                        delGoodOrgs.append((y, x-1))
                        newBadOrgs[(y,x-1)] = None
                if x < w - 1:
                    if (y, x+1) in goodOrgs.keys():
                        delGoodOrgs.append((y, x+1))
                        newBadOrgs[(y,x+1)] = None
                for (y, x) in delGoodOrgs:
                    goodOrgs.pop((y, x))
            badOrgs = newBadOrgs
            time += 1
                
        return time
                