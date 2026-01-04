impl Solution {
    pub fn sum_four_divisors(nums: Vec<i32>) -> i32 {
        let mut total_sum = 0;
        for &num in &nums {
            let mut divisors = Vec::new();
            let sqrt = (num as f64).sqrt() as i32;

            // Find all divisors up to sqrt(num)
            for i in 1..=sqrt {
                if num % i == 0 {
                    divisors.push(i);
                    if i != num / i {
                        divisors.push(num / i);
                    }
                }
            }

            // If exactly 4 divisors, sum them
            if divisors.len() == 4 {
                total_sum += divisors.iter().sum::<i32>();
            }
        }
        total_sum
    }
}