def splitArray(nums, m):
    n = len(nums)
    dp = [[float("inf") for _ in range(m+1)] for _ in range(n+1)]
    dp[0][0] = 0

    prefix_sum = [0]
    for num in nums:
        prefix_sum.append(prefix_sum[-1] + num)

    for i in range(1, n+1):
        for j in range(1, min(i, m)+1):
            for k in range(i):
                dp[i][j] = min(dp[i][j], max(dp[k][j-1], prefix_sum[i] - prefix_sum[k]))

    return dp[n][m]
