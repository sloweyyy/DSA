impl Solution {
    pub fn h_index(citations: Vec<i32>) -> i32 {
        let n = citations.len();
        let mut counts = vec![0usize;
        n + 1];
        for citation in citations {
            counts[(citation as usize).min(n)] += 1;
        }
        let mut papers = 0;
        for h in (0..=n).rev() {
            papers += counts[h];
            if papers >= h {
                return h as i32;
            }
        }
        0
    }
}
