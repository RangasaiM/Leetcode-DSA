class Solution:
    def removeDuplicates(self, arr: List[int]) -> int:
        i=0
        for j in range(1,len(arr)):
            if(arr[j]!=arr[j-1]):
                arr[i+1]=arr[j]
                i+=1
        return i+1