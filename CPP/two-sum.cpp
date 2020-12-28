#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;
/*
Given an array of integers nums and an integer target, return indices of
the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you 
may not use the same element twice.

*/
class Solution_one {
public:
    vector<int> twoSum(vector<int>& nums, int target)
    {
        vector<int> result(2);
        bool found =false;
        int size = nums.size();
        for(int i = 0;i < size-1; i++)
        {
          int j = i+1;
	          while(j<size)
            {
                if(nums[i]+nums[j]==target && i!=j)
                {
                  result[0] = i;
                  result[1] = j;
                  found = true;
                }
                j++;
            }
            if(found)
              break;
        }
        return result;
    }
};
class Solution_two{
public:
      vector<int> twoSum(vector<int>&nums, int target)
      {
        int i = 0,j=nums.size()-1;
        vector<int> result(2);
        vector<pair<int,int>> pairs;
        for(int v = 0;v< int(nums.size());v++)
        {
          pair<int,int> temp(nums[v],v);
          pairs.push_back(temp);
        }
	      sort(pairs.begin(),pairs.end());
        while(i<j)
        {
          if((pairs[i].first +  pairs[j].first)==target)
          {
            result[0]=pairs[i].second;
            result[1]=pairs[j].second;
            break;
          }
          else if((pairs[i].first+pairs[j].first)>target)
            j--;
          else
            i++;
        }
       return result;
      }
};
int main()
{
  Solution_two vec;
  vector<int> vectors = {3,2,4};
  for(auto x:vec.twoSum(vectors,6))
    cout<<x<<" ";
  cout<<endl;
  return 0;
}
