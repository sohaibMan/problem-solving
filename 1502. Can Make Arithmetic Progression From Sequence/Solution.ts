function canMakeArithmeticProgression(arr: number[]): boolean {
    arr.sort((a,b)=>a-b)
    if(arr.length<=1)return true;
    const e=arr[1]-arr[0];
    // console.log(arr)
    for(let i=0;i<arr.length-1;i++){
        if(arr[i+1]-arr[i] !=e )return false;
    }

return true;
};
