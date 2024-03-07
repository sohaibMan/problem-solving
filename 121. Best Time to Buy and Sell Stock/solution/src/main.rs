use std::cmp::max;

fn main() {
    println!("{}", max_profit(vec![7, 1, 5, 3, 6, 4]));
    println!("{}", max_profit(vec![7, 6, 4, 3, 1]));
}

pub fn max_profit(mut prices: Vec<i32>) -> i32 {
    // o(n^2) solution
    let mut max_profit = 0;
    // for i in 0..prices.len() {
    //     for j in i + 1..prices.len() {
    //         let margin = prices[j] - prices[i];
    //         max_profit = max(max_profit, margin);
    //     }
    // }

    // nlog(n) solution


    for i in 0..prices.len() {}


    max_profit
}