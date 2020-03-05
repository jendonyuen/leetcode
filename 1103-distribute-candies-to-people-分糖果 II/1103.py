class Solution:
    def distributeCandies(self, candies: int, num_people: int) -> List[int]:

        # 糖可以发k次
        k = 0.5 + math.sqrt(0.25 + 2 * candies)
        k = int(k) - 1

        # 糖可以发j轮(从0开始)
        j = k // num_people
        # print("j:", j, "k:", k)

        # 最后一个小朋友得到的糖果lastCandies
        lastCandies = int(candies - k * (k + 1) / 2)
        # print("lastCandies:", lastCandies)

        # 最后一个小朋友索引(从0开始)
        lastIndex = k % num_people
        # print("lastIndex:", lastIndex)

        rtn = []
        for i in range(1, num_people + 1):
            if i <= lastIndex:
                rtn.append(int((j+1) * i + num_people * (j+1) * j / 2))
            else:
                # 有的小朋友没有进入最后一轮
                rtn.append(int(j * i + j * num_people * (j-1) / 2))
        print(rtn)
        rtn[lastIndex] += lastCandies
        return rtn