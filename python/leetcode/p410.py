def splitArray(nums, m):
    def split_cnts(nums, max_sum):
        sum = 0
        cnt = 1
        for num in nums:
            if sum + num > max_sum:
                sum = num
                cnt += 1
            else:
                sum += num
        return cnt

    min_sum, max_sum = max(nums), sum(nums)
    left, right = min_sum ,max_sum
    min_max = max_sum
    while left <= right:
        mid = left + (right - left) // 2
        cnt = split_cnts(nums, mid)
        if cnt <= m:
            min_max = mid
            right = mid - 1
        else:
            left = mid + 1

    return min_max

if __name__ == "__main__":
    print(splitArray([7, 2, 5, 10, 8], 2))
    print(splitArray([1, 2, 3, 4, 5], 2))
    print(splitArray([1, 4, 4], 3))


