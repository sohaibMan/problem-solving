function solveEquation(equation) {
    var x = 0; // unknown
    var y = 0; // constant
    var sign = 1;
    for (var i = 0; i < equation.length; i++) {
        if (equation[i] === "=")
            sign = -1;
        if (equation[i] === "x" && i > 1 && equation[i - 1] != "x")
            x += sign * +equation[i - 1];
    }
    return "";
}
var equation = "x+5-3+x=6+x-2";
console.log(solveEquation(equation));
equation = "x=x";
console.log(solveEquation(equation));
equation = "2x=x";
console.log(solveEquation(equation));
