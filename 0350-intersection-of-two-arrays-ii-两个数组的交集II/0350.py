class Solution:
    def intersect(self, nums1: List[int], nums2: List[int]) -> List[int]:
        list1 = {}
        ans = []
        
        for n1 in nums1:
            if n1 in list1:
                list1[n1] += 1
            else:
                list1[n1] = 1
        
        for n2 in nums2:
            if n2 in list1:
                if list1[n2] > 0:
                    list1[n2] -= 1
                    ans.append(n2)

        return ans