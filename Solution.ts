// function fib(n:number):number {
//     if(n===0)return 0;
//     if(n===1)return 1;


//     return fib(n-1)+fib(n-2);

// }


function* fibGenerator(): Generator<number, any, number> {
    yield 0;
    yield 1;
    let XXfib=0;
    let Xfib=1;
    let fib:number;
    while (true) {
    fib=XXfib+Xfib;
    XXfib=Xfib;
    Xfib=fib;
    yield fib;

  }

};

/**
 * const gen = fibGenerator();
 * gen.next().value; // 0
 * gen.next().value; // 1
 */