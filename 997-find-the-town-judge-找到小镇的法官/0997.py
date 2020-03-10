class Solution:
    def findJudge(self, N: int, trust: List[List[int]]) -> int:
        if len(trust) == 0: 
            if N == 1: return 1
            else: return -1
        people = {}
        for t in trust:
            if t[1] in people:
                people[t[1]]["left"].append(t[0])
            else:
                people[t[1]] = {"left":[t[0]], "right":[]}
            if t[0] in people:
                people[t[0]]["right"].append(t[1])
            else:
                people[t[0]] = {"left":[], "right":[t[1]]}
        
        for index, person in people.items():
            if len(person["right"]) == 0 and len(person["left"]) == N - 1:
                return index
        
        return -1
            