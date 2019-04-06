#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode *temp, *data, *result = NULL, *prev;
	int len1 = 0, len2 = 0;
	temp = l1;
	while (temp != NULL) {
		temp = temp->next;
		len1++;
	}
	temp = l2;
	while (temp != NULL) {
		temp = temp->next;
		len2++;
	}
	temp = l2;
	result = l2;
	if (len1 >= len2) {
		temp = l1;
		result = l1;
	}
	int extra = 0;
	prev = temp;
	while (l1 != NULL && l2 != NULL) {
		if (l1->val + l2->val + extra > 9) {
			temp->val = (l1->val + l2->val) % 10;;
			extra = 1;
		}
		else {
			temp->val = l1->val + l2->val + extra;
			extra = 0;
		}
		l1 = l1->next;
		l2 = l2->next;
		prev = temp;
		temp = temp->next;
	}
	if (len1 == len2) {
		if (extra) {
			temp = new ListNode(0);
			prev->next = temp;
			temp->val += extra;
			if (temp->val > 9) {
				temp->val %= 10;
				temp->next = new ListNode(1);
			}
		}
	}
	else {
		temp->val += extra;
	}
	

	return result;
}

int main()
{
	ListNode a1(9), a2(9), a3(3);
	ListNode b1(1), b2(6), b3(4);
	a1.next = &a2;
	ListNode *result = addTwoNumbers(&a1, &b1);
	while (result != NULL) {
		cout << result->val << endl;
		result = result->next;
	}
}