class Solution:
    def differenceOfSums(self, n: int, m: int) -> int:
        num1 = 0  # Sum of numbers not divisible by m
        num2 = 0  # Sum of numbers divisible by m
        
        for i in range(1, n + 1):
            if i % m != 0:
                num1 += i
            else:
                num2 += i
        
        return num1 - num2