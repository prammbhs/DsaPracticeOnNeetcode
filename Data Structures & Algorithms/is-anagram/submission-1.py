class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        s1={}
        for ch in s:
            if ch in s1:
                s1[ch] +=1
            else:
                s1[ch] = 1
        s2 = {}
        for ch in t:
            if ch in s2:
                s2[ch] += 1
            else:
                s2[ch] = 1
        return s1==s2

        