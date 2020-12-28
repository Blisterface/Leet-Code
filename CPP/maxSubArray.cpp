#include<iostream>
#include<vector>

//brute force for finding the maximum subArray
//{-2,1,-3,4,-1,2,1,-5,4}
int subArray(std::vector<int> vec)
{
    int maxSum = INT_MIN;
    for(int i = 0;i<vec.size();i++)
    {
        int temp =0;
        for(int j=i;j<vec.size();j++)
        {
            temp+=vec[j];
            if(temp>vec[j])
                maxSum = std::max(maxSum,temp);
        }
    }
    return maxSum;
}

int subArray2(std::vector<int> vec)
{
    if(vec.size()==0)
        return 0;
    int maxSum = vec[0];
    int currentSum = vec[0];
    for(int i=1;i<vec.size();i++)
    {
        currentSum = std::max(currentSum+vec[i],vec[i]);
        maxSum = std::max(currentSum,maxSum);
    }
    return maxSum;
}
int main()
{
    std::vector<int> data = {-2,1,-3,4,-1,2,1,-5,4};

    std::cout<<subArray(data)<<std::endl;

    std::cout<<subArray2(data)<<std::endl;

    return 0;
}