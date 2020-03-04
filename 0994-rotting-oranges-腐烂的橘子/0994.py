class Solution:
    def orangesRotting(self, grid: List[List[int]]) -> int:
        badOrgs = []

        h = len(grid)
        if h == 0: return 0
        w = len(grid[0])
        if w == 0: return 0

        lastGoodOrgsNumber = 0
        # 将所有坏橘子放入list
        for y in range(h):
            for x in range(w):
                if grid[y][x] == 1:
                    lastGoodOrgsNumber += 1
                if grid[y][x] == 2:
                    badOrgs.append((y, x))
                    

        # 没有好橘子
        if lastGoodOrgsNumber == 0:
                return 0

        time = 0
        while lastGoodOrgsNumber > 0:
            # print("len:", len(goodOrgs), lastGoodOrgsNumber)

            goBadNumber = 0
            newBadOrgs = []
            # 腐烂周围的橘子
            for y, x in badOrgs:
                # print(y, x)
                delGoodOrgs = []
                if y > 0:
                    if grid[y-1][x] == 1:
                        grid[y-1][x] = 2
                        newBadOrgs.append((y-1,x))
                        goBadNumber += 1
                if y < h - 1:
                    if grid[y+1][x] == 1:
                        grid[y+1][x] = 2
                        newBadOrgs.append((y+1,x))
                        goBadNumber += 1
                if x > 0:
                    if grid[y][x-1] == 1:
                        grid[y][x-1] = 2
                        newBadOrgs.append((y,x-1))
                        goBadNumber += 1
                if x < w - 1:
                    if grid[y][x+1] == 1:
                        grid[y][x+1] = 2
                        newBadOrgs.append((y,x+1))
                        goBadNumber += 1
            if goBadNumber == 0:
                # 无法腐烂完所有橘子
                return -1

            badOrgs = newBadOrgs
            time += 1
            lastGoodOrgsNumber -= goBadNumber
                
        return time