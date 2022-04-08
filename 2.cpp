#include <iostream>
#include <string>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// https://leetcode-cn.com/problems/add-two-numbers/
/************************* 题目描述 *************************
* 给你两个非空的链表,表示两个非负的整数。它们每位数字都是按照逆序的方式存储的，
* 并且每个节点只能存储一位数字.请你将两个数相加,并以相同形式返回一个表示和的链表。
* 你可以假设除了数字0之外，这两个数都不会以0开头。
* 
* 输入：l1 = [2,4,3], l2 = [5,6,4]
* 输出：[7,0,8]
* 解释：342 + 465 = 807.
* 
* 输入：l1 = [0], l2 = [0]
* 输出：[0]
* 
* 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
* 输出：[8,9,9,9,0,0,0,1]
*************************************************************/
class Solution2 
{

public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) 
	{
		if (l1 == NULL || l2 == NULL)
		{
			if (l2 == NULL)
			{
				return l1;
			}
			if (l1 == NULL)
			{
				return l2;
			}
		}
		bool carry = false;	// 进位
		ListNode* l3 = new ListNode();
		ListNode* Ret = l3;	// 记录返回链表头结点
		while (l1 != NULL || l2 != NULL)
		{
			if (carry)
			{
				l3->val++;
			}

			if (l1)
			{
				l3->val += l1->val;
				l1 = l1->next;
			}

			if (l2)
			{
				l3->val += l2->val;
				l2 = l2->next;
			}

			if (l3->val >= 10)
			{
				carry = true;
				l3->val -= 10;
			}
			else
			{
				carry = false;
			}

			if (l1 != NULL || l2 != NULL)
			{
				l3->next = new ListNode();
				l3 = l3->next;
			}
		}
		
		if (carry)
		{
			l3->next = new ListNode(carry);
		}

		return Ret;
    }

	void ShowList(ListNode* L)	// 显示链表中所有值
	{
		while (L != NULL)
		{
			cout << L->val << " ";
			L = L->next;
		}
		cout << endl;
	}

	void DeleteList(ListNode* L)	// 清理内存
	{
		if (!L)
		{
			return;
		}

		ListNode* p = L->next;	// 先保存下一个结点
		delete L;
		L = p;
		while (L != NULL)
		{
			p = L->next;	// 先保存
			delete L;
			L = p;
		}
	}

	ListNode* InitList(string strNum)
	{
		if (strNum.empty())
		{
			return NULL;
		}
		ListNode* tmp = new ListNode();
		ListNode* Ret = tmp;

		for (int i = 0; i < strNum.length(); i++)
		{
			tmp->val = atoi(strNum.substr(i, 1).c_str());
			if (i + 1 < strNum.length())
			{
				tmp->next = new ListNode();
			}
			tmp = tmp->next;
		}
		return Ret;
	}
};

void test(string str1, string str2)
{
	ListNode* l1;
	ListNode* l2;
	ListNode* l3;
	Solution2 obj;

	cout << "--------------------- str1:" << str1 << " str2:" << str2 << " ---------------------" << endl;

	l1 = obj.InitList(str1);
	l2 = obj.InitList(str2);
	l3 = obj.addTwoNumbers(l1, l2);

	obj.ShowList(l1);
	obj.ShowList(l2);
	obj.ShowList(l3);

	obj.DeleteList(l1);
	obj.DeleteList(l2);
	obj.DeleteList(l3);

	cout << "---------------------------------------------------------------\n" << endl;
}
#if 0
int main()
{
	// 输入：l1 = [2, 4, 3], l2 = [5, 6, 4]
	// 输出：[7, 0, 8]
	test("243", "564");

	// 输入：l1 = [0], l2 = [0]
	// 输出：[0]
	test("0", "0");

	// 输入：l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
	// 输出：[8, 9, 9, 9, 0, 0, 0, 1]
	test("9999999", "9999");

	test("1", "9999");

	test("99", "9");

	return 0;
}
#endif