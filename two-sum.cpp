#include <iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result;
        for(int i = 0;i < int(nums.size()); i++)
        {
	  for( int j=1; j < int(nums.size()); j++)
            {
                if(nums[i]+nums[j]==target)
                {
		  if(i==j)
		    continue;
                   result.push_back(i);
                   result.push_back(j);
                   return result;
                }
            }
        }
        return result;
    }
};

int main()
{
  Solution vec;
  vector<int> vectors = {3,5,4,9,6,12,45};
  for(auto x:vec.twoSum(vectors,18))
    cout<<x<<" ";
  cout<<endl;
  return 0;
}
