#include <math.h>

int searchInsert(int* nums, int numsSize, int target){
return binarySearch(nums,target,0,numsSize-1);
}

int  binarySearch(int *nums,int target,int s,int e){
    if(e==s)return nums[e]==target ? e : nums[e]<target ? e+1:e;
    if(s>e)return s;
    int centre=floor((s+e)/2);
    if(nums[centre]==target)return centre;
    if(nums[centre]<target)return binarySearch(nums,target,centre+1,e);
    else return binarySearch(nums,target,s,centre-1);


}