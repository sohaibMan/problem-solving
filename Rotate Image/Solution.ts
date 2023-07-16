function rotate(matrix: number[][]): void {
    let array = matrix;
    for (let i = 0; i < matrix[0].length; i++) {
        for (let j = 0; j < matrix[0].length; j++) {
            if (i === j) break;
            let tmp = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = tmp;
        }
    }
    for (let i = 0; i < matrix[0].length; i++) {
        matrix[i].reverse();
    }
};