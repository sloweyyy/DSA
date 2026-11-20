def find_duplicates(nums)
    result = []
    nums.each do |value|
        index = value.abs - 1
        if nums[index] < 0
            result << index + 1
        else
            nums[index] = -nums[index]
        end
    end
    result
end
