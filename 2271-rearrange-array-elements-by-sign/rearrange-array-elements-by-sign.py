class Solution:
    def rearrangeArray(self, arr: List[int]) -> List[int]:
        pos=0
        neg=1
        ans=[0]*len(arr)
        for i in arr:
            if(i>0):
                ans[pos]=i
                pos+=2
            else:
                ans[neg]=i
                neg+=2
        return ans