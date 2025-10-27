class Solution:
    def removeDuplicates(self, arr: List[int]) -> int:
        i=1
        cnt=1
        for j in range(1,len(arr)):
            if arr[j-1]==arr[j]:
                cnt+=1
            else:
                cnt=1
            if cnt<=2:
                arr[i]=arr[j]
                i+=1
        return i