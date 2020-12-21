#include<iostream>
#include<vector>

//[1,8,6,2,5,4,8,3,7]

int maxArea(std::vector<int> vec)
{
     int i=0,j=vec.size()-1;
     int area = 0;
     int h_min,width;
     while(i<j)
     {
         h_min=std::min(vec[i],vec[j]);
         width = j-i;
         int temp= h_min*width;
         area=std::max(area,temp);
         vec[j]>vec[i]? ++i:--j;
     }
     return area;
}
int main()
{
    std::vector<int> levels ={1,8,6,2,5,4,8,3,7};
    std::cout<<maxArea(levels)<<std::endl;
}