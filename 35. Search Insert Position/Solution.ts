// 35. Search Insert Position
function searchInsert(nums: number[], target: number): number {
    return binarySearch(nums,target,0,nums.length-1);
}
function  binarySearch(nums:number[],target:number,s:number,e:number){
    if(e===s)return nums[e]===target ? e : nums[e]<target ? e+1:e;
    if(s>e)return s;
    let centre=Math.floor((s+e)/2)
    if(nums[centre]===target)return centre;
    if(nums[centre]<target)return binarySearch(nums,target,centre+1,e);
    else return binarySearch(nums,target,s,centre-1);


}