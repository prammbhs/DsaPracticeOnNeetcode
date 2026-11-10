class Solution:
    def rob(self, nums: List[int]) -> int:
        n = len(nums)
        dp = [0] * n
        for i in range(0,n):
            dp[i] = nums[i]
            if i-2 >= 0:
                dp[i] += dp[i-2]
            if i>0:
                dp[i] = max(dp[i-1],dp[i])
        return dp[-1]

        