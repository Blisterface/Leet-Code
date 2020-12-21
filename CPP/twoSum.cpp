#include<vector>
#include<iostream>
#include<unordered_map>
#include<algorithm>

std::vector<int> solution1(std::vector<int> vec,int target)
{
    std::vector<int> result;
    for(auto it = vec.begin();it!=vec.end();it++)
    {
        auto it2 =std::find(it+1,vec.end(),target-(*it));
        if(it2!=vec.end())
        {
            result.push_back(it-vec.begin());
            result.push_back(it2-vec.begin());
            break;
        }
    }
    return result;
}

std::vector<int> solution2(std::vector<int> vec,int target)
{
    std::unordered_map<int,int> data;

    for(int i = 0;i<vec.size();i++)
    {
        int complement = target-vec[i];
        auto it = data.find(complement);
        if(it!=data.end())
            return {it->second,i};
        data[vec[i]]=i;
    }
    
    return {};
}


int main()
{
    std::vector<int> data = {4,6,2,8,9,5,7};
    int tar = 15;
    std::vector<int> result = solution2(data,tar);

    for(auto r :result)
        std::cout<<r<<"\t";
    std::cout<<std::endl;
}