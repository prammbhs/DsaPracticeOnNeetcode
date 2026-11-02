class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        seen = {}
        for word in strs:
            k = "".join(sorted(word))
            seen.setdefault(k,[]).append(word)
        return list(seen.values())




        