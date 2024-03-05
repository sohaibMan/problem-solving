fn main() {
    let matrix: Vec<Vec<i32>> = vec![
        vec![1, 1, 0, 0, 0], //2
        vec![1, 1, 1, 1, 0], //4
        vec![1, 0, 0, 0, 0], //1
        vec![1, 1, 0, 0, 0], //2
        vec![1, 1, 1, 1, 1], //5
    ];
    // row 1 is weaker than row 2 and 4 5

    let result = k_weakest_rows(matrix, 3);


    println!("{:?}", result);
}



    pub fn k_weakest_rows(mat: Vec<Vec<i32>>, k: i32) -> Vec<i32> {
        // count the number of soldiers for each rows in a declarative manner  o(n*2)
        let counts: Vec<usize> = mat.iter().map(|row| row.iter().filter(|&&x| x == 1).count()).collect();
        let mut counts_with_index: Vec<(usize, usize)> = counts.iter().enumerate().map(|(i, &count)| (i, count)).collect();
        counts_with_index.sort_by(|a, b| a.1.cmp(&b.1));



      counts_with_index.iter().take(k as usize).map(|&(i, _)| i as i32).collect()
    }
