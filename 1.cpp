#include <iostream>
#include <vector>
using namespace std;

class LeetCode1
{
public:
	/*
	给定一个整数数组 nums 和一个整数目标值 target，
	请你在该数组中找出和为目标值的那两个整数，
	并返回它们的数组下标。
	你可以假设每种输入只会对应一个答案。
	但是，数组中同一个元素在答案里不能重复出现。
	你可以按任意顺序返回答案。

	示例 1：
	输入：nums = [2, 7, 11, 15], target = 9
	输出：[0, 1]
	解释：因为 nums[0] + nums[1] == 9 ，返回[0, 1] 。

	示例 2：
	输入：nums = [3, 2, 4], target = 6
	输出：[1, 2]

	示例 3：
	输入：nums = [3, 3], target = 6
	输出：[0, 1]
	*/
public:
	vector<int> twoSum(vector<int>& nums, int target)
	{
		vector<int> veRet;
		for (int i = 0; i < nums.size(); i++)
		{
			for (int j = i + 1; j < nums.size(); j++)
			{
				if (target == nums[i] + nums[j])
				{
					veRet.push_back(i);
					veRet.push_back(j);
					return veRet;
				}
			}
		}
	}

	void ShowIntVector(vector<int> veRet)
	{
		cout << "[";
		for (int i = 0; i < veRet.size(); i++)
		{
			cout << veRet[i] << " ";
		}
		cout << "]" << endl;
	}
};

#if 0
int main()
{
	LeetCode1 obj;
	vector<int> veTest1 = { 2, 7, 11, 15 };
	vector<int> veRet = obj.twoSum(veTest1, 9);
	obj.ShowIntVector(veTest1);
	obj.ShowIntVector(veRet);

	vector<int> veTest2 = { 3, 2, 4 };
	veRet = obj.twoSum(veTest2, 6);
	obj.ShowIntVector(veTest2);
	obj.ShowIntVector(veRet);

	vector<int> veTest3 = { 3, 3, 5, 6, 1, 9, 2 };
	veRet = obj.twoSum(veTest3, 10);
	obj.ShowIntVector(veTest3);
	obj.ShowIntVector(veRet);

	return 0;
}
#endif