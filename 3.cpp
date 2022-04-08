#include <iostream>
#include <string>
#include <vector>
using namespace std;

// https://leetcode-cn.com/problems/longest-substring-without-repeating-characters/
/************************* 题目描述 *************************
* 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

	示例 1:
	输入: s = "abcabcbb"
	输出: 3
	解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

	示例 2:
	输入: s = "bbbbb"
	输出: 1
	解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

	示例 3:
	输入: s = "pwwkew"
	输出: 3
	解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
 		 请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

	示例 4:
	输入: s = ""
	输出: 0
 
提示：
	0 <= s.length <= 5 * 104
	s 由英文字母、数字、符号和空格组成
*************************************************************/

class Solution3
{
public:
	int lengthOfLongestSubstring(string s) 
	{
		int Ret = 0;
		vector<char> ve;
		for (int i = 0; i < s.length(); i++)
		{
			for (int j = 0; j < ve.size(); j++)
			{
				if (s[i] == ve[j])
				{
					vector<char>::iterator it = ve.begin();
					ve.erase(it, it + j + 1);
				}
			}
			ve.push_back(s[i]);

			if (ve.size() > Ret)
			{
				Ret = ve.size();
			}
		}
		return Ret;
	}
};

int main()
{
	Solution3 obj;
	// 输入: s = "abcabcbb"
	// 输出: 3
	cout << "In:abcabcbb" << " Out:" << obj.lengthOfLongestSubstring("abcabcbb") << endl;

	// 输入: s = "bbbbb"
	// 输出: 1
	cout << "In:bbbbb" << " Out:" << obj.lengthOfLongestSubstring("bbbbb") << endl;

	// 输入: s = "pwwkew"
	// 输出: 3
	cout << "In:pwwkew" << " Out:" << obj.lengthOfLongestSubstring("pwwkew") << endl;

	// 输入: s = ""
	// 输出 : 0
	cout << "In:" << " Out:" << obj.lengthOfLongestSubstring("") << endl;

	return 0;
}