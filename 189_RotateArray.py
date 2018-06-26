class Solution:
    def rotate(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        length = len(nums)
        if k > length:
            k = k % length

        n = 0
        while k > 0:
            i = length - k - 1
            target = nums[i + 1]
            while i >= n:
                nums[i + 1] = nums[i]
                i -= 1
            nums[n] = target
            k -= 1
            n += 1


if __name__ == '__main__':
    #nums = [1, 2, 3, 4, 5, 6, 6]
    nums = [1, 2]
    print(nums)
    so = Solution()
    so.rotate(nums, 3)
    print(nums)
