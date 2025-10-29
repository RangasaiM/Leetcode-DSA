class Solution:
    def maxSubArray(self, arr: List[int]) -> int:
        maxSum=arr[0]
        sumi=arr[0]
        for i in range(1,len(arr)):
            sumi=max(sumi,0)+arr[i]
            if(sumi<0):
                sumi=arr[i]
            maxSum=max(sumi,maxSum)
        return maxSum