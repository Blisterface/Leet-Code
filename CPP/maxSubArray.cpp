#include<iostream>
#include<vector>

//brute force for finding the maximum subArray
int subArray(std::vector<int> vec)
{
    int maxSum = INT_MIN;
    for(int i = 0;i<vec.size();i++)
    {
        int temp =0;
        for(int j=i;j<vec.size();j++)
            temp+=vec[j];
        maxSum = std::max(maxSum,temp);
    }
    return maxSum;
}
int main()
{
    std::vector<int> data = {-2,1,-3,4,-1,2,1,-5,4};

    std::cout<<subArray(data)<<std::endl;

    return 0;
}