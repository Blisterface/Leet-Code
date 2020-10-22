#include<iostream>
#include<vector>
#include<algorithm>
#include<cstdlib>
/*
Given an integer array, find three numbers whose product is the maximum 
and output the maximum product.
*/
using namespace std;
int solution(vector<int>& nums)
{
    int p1,p2;
    int j = nums.size()-3;
    sort(nums.begin(),nums.end());
 
    p1 = nums[j]*nums[j+1]*nums[j+2];
    p2 = nums[0]*nums[1]*nums[j+2];

    return max(p1,p2);
}
int solution2(vector<int>& nums)
{
    int max1=0,max2=0,max3=0,min1=1,min2 = 1;
    for(auto x:nums)
    {
        if (max3<x)
        {
            max1 = max2;
            max2 = max3;
            max3=x;   
        }
        else if (max2<x)
        {
            max1 = max2;
            max2=x;
        }
        else if (max1<x)
        {
            max1=x;
        }
        if(x<min2)
        {
            min1=min2;
            min2 = x;
        }
        else if (x<min1)
            min1 = x;     
    }
    return max(max3*max2*max1,max3*min1*min2);
}

int main()
{
    vector<int> vals = {-4,-3,-2,-1,60};
    cout<<"The max product is: "<<solution2(vals)<<endl;
}