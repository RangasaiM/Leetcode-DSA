class Solution:
    def minWindow(self, s: str, target: str) -> str:
        freq=dict()
        cnt=0
        minLen=len(s)
        n=len(s)
        i=0
        j=0
        ans=""
        for ele in target:
            if ele not in freq:
                freq[ele]=1
            else:
                freq[ele]+=1
        while(j<n):
            if cnt<len(target) and i<n:
                if s[i] not in freq:
                    freq[s[i]]=-1
                else:
                    if freq[s[i]]>0:
                        cnt+=1
                    freq[s[i]]-=1
                i+=1
            elif cnt==len(target):
                if(minLen>=i-j):
                    ans=s[j:i]
                    minLen=i-j
                if(freq[s[j]]>=0):
                    cnt-=1
                freq[s[j]]+=1
                j+=1
            else:
                break
        return ans