use std::collections::VecDeque;
impl Solution {
    pub fn find_ladders(begin_word: String, end_word: String, word_list: Vec<String>) -> Vec<Vec<String>> {
        let mut words = word_list;
        let end = match words.iter().position(|w| w == &end_word) {
            Some(i) => i, None => return vec![]
        };
        let start = match words.iter().position(|w| w == &begin_word) {
            Some(i) => i, None => {
                words.push(begin_word);
                words.len()-1
            }
        };
        let n = words.len();
        let mut edges = vec![vec![];
        n];
        for i in 0..n {
            for j in i+1..n {
                if words[i].bytes().zip(words[j].bytes()).filter(|(a,b)| a != b).count() == 1 {
                    edges[i].push(j);
                    edges[j].push(i);
                }
            }
        }
        let mut distance = vec![usize::MAX;
        n];
        let mut parents = vec![vec![];
        n];
        let mut queue = VecDeque::new();
        distance[start] = 0;
        queue.push_back(start);
        while let Some(u) = queue.pop_front() {
            if distance[u] >= distance[end] {
                continue;
            }
            for &v in &edges[u] {
                if distance[v] == usize::MAX {
                    distance[v] = distance[u]+1;
                    queue.push_back(v);
                }
                if distance[v] == distance[u]+1 {
                    parents[v].push(u);
                }
            }
        }
        fn collect(v: usize, start: usize, parents: &Vec<Vec<usize>>, words: &Vec<String>, path: &mut Vec<usize>, result: &mut Vec<Vec<String>>) {
            path.push(v);
            if v == start {
                result.push(path.iter().rev().map(|&i| words[i].clone()).collect());
            }
            else {
                for &p in &parents[v] {
                    collect(p, start, parents, words, path, result);
                }
            }
            path.pop();
        }
        let mut result = vec![];
        if distance[end] != usize::MAX {
            collect(end, start, &parents, &words, &mut vec![], &mut result);
        }
        result
    }
}
