def trap_rain_water(heights):
        left = 0
        right = len(heights) - 1
        ans = 0
        while left < right:
            if heights[left] >= heights[right]:
                ans += max(0, heights[right] - heights[right - 1])
                heights[right - 1] = max(heights[right], heights[right - 1])
                right -= 1
            else:
                ans += max(0, heights[left] - heights[left + 1])
                heights[left + 1] = max(heights[left], heights[left + 1])
                left += 1
        return ans
     
heights = [1, 2, 1, 3, 1, 2, 1, 4, 1, 0, 0, 2, 1, 4]
print(trap_rain_water(heights))
