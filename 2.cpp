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
/************************* ��Ŀ���� *************************
* ���������ǿյ�����,��ʾ�����Ǹ�������������ÿλ���ֶ��ǰ�������ķ�ʽ�洢�ģ�
* ����ÿ���ڵ�ֻ�ܴ洢һλ����.���㽫���������,������ͬ��ʽ����һ����ʾ�͵�����
* ����Լ����������0֮�⣬����������������0��ͷ��
* 
* ���룺l1 = [2,4,3], l2 = [5,6,4]
* �����[7,0,8]
* ���ͣ�342 + 465 = 807.
* 
* ���룺l1 = [0], l2 = [0]
* �����[0]
* 
* ���룺l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
* �����[8,9,9,9,0,0,0,1]
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
		bool carry = false;	// ��λ
		ListNode* l3 = new ListNode();
		ListNode* Ret = l3;	// ��¼��������ͷ���
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

	void ShowList(ListNode* L)	// ��ʾ����������ֵ
	{
		while (L != NULL)
		{
			cout << L->val << " ";
			L = L->next;
		}
		cout << endl;
	}

	void DeleteList(ListNode* L)	// �����ڴ�
	{
		if (!L)
		{
			return;
		}

		ListNode* p = L->next;	// �ȱ�����һ�����
		delete L;
		L = p;
		while (L != NULL)
		{
			p = L->next;	// �ȱ���
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
	// ���룺l1 = [2, 4, 3], l2 = [5, 6, 4]
	// �����[7, 0, 8]
	test("243", "564");

	// ���룺l1 = [0], l2 = [0]
	// �����[0]
	test("0", "0");

	// ���룺l1 = [9, 9, 9, 9, 9, 9, 9], l2 = [9, 9, 9, 9]
	// �����[8, 9, 9, 9, 0, 0, 0, 1]
	test("9999999", "9999");

	test("1", "9999");

	test("99", "9");

	return 0;
}
#endif