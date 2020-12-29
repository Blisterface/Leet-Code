#include<iostream>
#include<vector>

template<typename T>
int search(std::vector<T> data,T key)
{
    int start = 0, end = data.size()-1;

    while(start<=end)
    {
        int mid = start + (end-start)/2;
        if (data[mid]==key)
            return mid;
        
        else if(data[mid] <= data[end])
        {
            if(key <= data[end] && key > data[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        else
        {
            if(key<data[mid]&&key>=data[start])
                end = mid-1;
            else
                start = mid+1;
        }

    }
    return -1;
}

int main()
{
    std::vector<int> vec {4,5,6,7,0,1,2};
    int target = 5;
    std::cout<<search(vec,target)<<"\n";
    return 0;
}