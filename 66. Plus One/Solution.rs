fn main() {
    let digits = vec!(1, 2, 3);
    let s = Solution {
        digits
    };
    println!("{:?}", s.plus_one());
}

struct Solution {
    digits: Vec<i32>,
}

impl Solution {
    pub fn plus_one(&self) -> Vec<i32> {
        let mut sum = 1;
        let length = self.digits.len();
        for (digit, i) in self.digits.iter().enumerate() {
            let base: i32 = 10;
            sum += digit + i * base.pow(length - i - 1);
        }
        let mut digits: Vec<i32> = Vec::new();
        while sum > 9 {
            digits.push(sum % 10);
            sum = sum / 10;
        }
        digits.push(sum);
        digits.reverse();

        return digits;
    }
}