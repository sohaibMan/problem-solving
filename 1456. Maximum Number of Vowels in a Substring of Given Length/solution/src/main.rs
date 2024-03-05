use std::cmp::max;

fn main() {
    println!("{}", max_vowels(String::from("abciiidef"), 3));
    println!("{}", max_vowels(String::from("aeiou"), 2));
    println!("{}", max_vowels(String::from("leetcode"), 3));
}

pub fn max_vowels(s: String, k: i32) -> i32 {
    let vowels = ['a', 'e', 'i', 'o', 'u'];
    let mut count_vowels = s.chars().take(k as usize)
        .filter(|&c| vowels.contains(&c))
        .count() as i32;
    let mut max_vowels = count_vowels;

    for i in 0..(s.len() as i32) - k {
        if vowels.contains(&s.chars().nth(i as usize).unwrap()) { count_vowels -= 1 };
        if vowels.contains(&s.chars().nth((i + k) as usize).unwrap()) { count_vowels += 1 };

        max_vowels = max(max_vowels, count_vowels)
    }

    max_vowels
}


