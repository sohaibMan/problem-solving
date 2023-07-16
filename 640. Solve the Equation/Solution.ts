function solveEquation(equation: string): string {
    let x = 0;// unknown
    let y = 0;// constant
    let sign = 1;
    for (let i = 0; i < equation.length; i++) {
        if (equation[i] === "=") sign = -1;
        if (equation[i] === "x" && i > 1 && equation[i - 1] != "x") x += sign * +equation[i - 1];
    }
    return ""
}

let equation = "x+5-3+x=6+x-2"
console.log(solveEquation(equation))
equation = "x=x"
console.log(solveEquation(equation))
equation = "2x=x"
console.log(solveEquation(equation))