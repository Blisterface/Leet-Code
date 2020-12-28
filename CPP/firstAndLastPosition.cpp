#include<vector>
#include<iostream>

std::vector<int> searchRange1(std::vector<int> nums,int target)
{
    if(nums.size()==0)
        return {};
    int first = 0, last = nums.size()-1;
    while(nums[first]!=target && first!=nums.size())
        first++;
    while(nums[last]!=target && last!=-1)
        last--;
    if(last !=-1 && first!=nums.size())
        return{first,last};
    return {-1,-1};
}
//using binary search algorithm

int findFirstIndex(std::vector<int>nums,int target)
{
    int start = 0,end = nums.size()-1;
    int index = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(nums[mid]==target)
        {
            index=mid;
            end=mid-1;
        }
        else if(nums[mid]<target)
            start = mid+1;
        else
            end=mid-1;
    }
    return index;
}

int findLastIndex(std::vector<int>nums,int target)
{
    int start = 0,end = nums.size()-1;
    int index = -1;
    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if(nums[mid]==target)
        {
            index=mid;
            start=mid+1;
        }
        else if(nums[mid]<target)
            start = mid+1;
        else
            end=mid-1;
    }
    return index;
}

std::vector<int> searchRange2(std::vector<int> nums,int target)
{
    if(nums.size()==0)
        return {};
    int first = findFirstIndex(nums,target);
    int last = findLastIndex(nums,target);
    return {first,last};
}
int main()
{
    std::vector<int> vec{5,7,7,8,8,10};
    int target = 6;

    std::vector<int> res1 = searchRange1(vec,target);
    for(auto r1: res1)
        std::cout<<r1<<"\t";
    std::cout<<"\n";

    std::vector<int> res2 = searchRange2(vec,target);
    for(auto r2: res2)
        std::cout<<r2<<"\t";
    std::cout<<"\n";
    return 0; 
}