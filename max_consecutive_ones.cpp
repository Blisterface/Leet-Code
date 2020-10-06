#include<iostream>
#include <vector>
using namespace std;

int max_cons_ones(vector<int>& v)
{
    int j=0,res=0;
    for(int i =0;i<v.size();i++)
    {
        int temp = 0;
        while(j<v.size())
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
        res = max(res,temp);
    }
    return res;
}

int main()
{
    vector<int> vec{1,1,0,1,1,1};
    cout<<max_cons_ones(vec)<<endl;
    return 0;
}