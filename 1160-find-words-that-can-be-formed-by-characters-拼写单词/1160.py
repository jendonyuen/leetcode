class Solution:
    def countCharacters(self, words: List[str], chars: str) -> int:
        letterTable = {}
        for c in chars:
            if c in letterTable.keys():
                letterTable[c] += 1
            else:
                letterTable[c] = 1

        rtnLen = 0
        for word in words:
            temp = letterTable.copy()
            isFormed = True
            for c in word:
                if c in temp.keys():
                    if temp[c] == 0:
                        isFormed = False
                        break
                    temp[c] -= 1
                else:
                    isFormed = False
                    break
            if isFormed:
                rtnLen += len(word)
        
        return rtnLen
