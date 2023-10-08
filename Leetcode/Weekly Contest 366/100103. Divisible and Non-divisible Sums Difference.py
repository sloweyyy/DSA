def subtractSum(n, m):
    num1 = 0  # Sum of numbers not divisible by m
    num2 = 0  # Sum of numbers divisible by m
    
    for i in range(1, n + 1):
        if i % m != 0:
            num1 += i
        else:
            num2 += i
    
    return num1 - num2

# Example usage:
n1 = 10
m1 = 3
print(subtractSum(n1, m1))  # Output: 19

n2 = 5
m2 = 6
print(subtractSum(n2, m2))  # Output: 15

n3 = 5
m3 = 1
print(subtractSum(n3, m3))  # Output: -15
