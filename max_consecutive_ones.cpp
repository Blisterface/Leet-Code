#include<iostream>
#include <vector>
using namespace std;

int max_cons_ones(vector<int>& v)
{
    int j=0,res=0,i=0,size=v.size();
    while(i<size)
    {
        int temp = 0;
        while(j<size)
        {
            if(v[j]==1)
            {
                temp+=v[j];
                j++;
            }
            else
            {
                j++;
                break;
            }
        }
        i=j;
        res = max(res,temp);
    }
    return res;
}

int sol_two(vector<int> nums)
{
    int res=0,size=nums.size(),temp=0;
    for(int i=0;i<size;i++)
    {
        if(nums[i]!=1){
            temp = 0;
            continue;
        }
        else
        {
            temp+=nums[i];
            res=max(res,temp);
        }
        
    }
    return res;
}
int main()
{
    vector<int> vec{1,1,0,1,1,1};
    cout<<sol_two(vec)<<endl;
    return 0;
}