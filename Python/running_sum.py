from typing import List

print([1,4,6,8,12])
def running_sum(nums: List[int])->List[int]:
    i = 1
    for i in range(1,len(nums)):
        nums[i] = nums[i] + nums[i-1]

    return nums

if __name__ == '__main__':
    lists = [1,4,6,8,12]
    new_list = running_sum(lists)
    print(new_list)

