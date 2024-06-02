#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
    ListNode *res = nullptr;
    ListNode *head;

    while (list1 != nullptr || list2 != nullptr)
    {
        if (res == nullptr)
        {
            res = new ListNode(-200);
            head = res;
        }
        else if (res->val != -200)
        {
            res->next = new ListNode(-200);
            res = res->next;
        }

        if (list1 != nullptr && list2 != nullptr)
        {
            if (list1->val < list2->val)
            {
                res->val = list1->val;
                list1 = list1->next;
            }
            else
            {
                res->val = list2->val;
                list2 = list2->next;
            }
        }

        else if (list1 == nullptr && list2 != nullptr)
        {
            res->val = list2->val;
            list2 = list2->next;
        }
        else
        {
            res->val = list1->val;
            list1 = list1->next;
        }
    }

    return head;
}

int main()
{

    return 0;
}