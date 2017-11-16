#include <iostream>
#include <cassert>

using namespace std;

///Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// LinkedList Test Helper Functions
ListNode* createLinkedList(int arr[], int n){

    if(n == 0)
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for(int i = 1 ; i < n ; i ++){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

void printLinkedList(ListNode* head){

    if(head == NULL){
        cout<<"NULL"<<endl;
        return;
    }

    ListNode* curNode = head;
    while(curNode != NULL){
        cout << curNode->val;
        if(curNode->next != NULL)
            cout << " -> ";
        curNode = curNode->next;
    }

    cout << endl;

    return;
}

void deleteLinkedList(ListNode* head){

    ListNode* curNode = head;
    while(curNode != NULL){
        ListNode* delNode = curNode;
        curNode = curNode->next;
        delete delNode;
    }

    return;
}

// 19. Remove Nth Node From End of List
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/description/
//
// 先记录链表总长度
// 需要对链表进行两次遍历
// 时间复杂度: O(n)
// 空间复杂度: O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummyHead = new ListNode(0);
        dummyHead->next = head;

        int length = 0;
        for(ListNode* cur = dummyHead->next ; cur != NULL ; cur = cur->next)
            length ++;

        int k = length - n;
        assert(k >= 0);
        ListNode* cur = dummyHead;
        for(int i = 0 ; i < k ; i ++)
            cur = cur->next;

        ListNode* delNode = cur->next;
        cur->next = delNode->next;
        delete delNode;

        ListNode* retNode = dummyHead->next;
        delete dummyHead;
        return retNode;
    }
};

int main() {

    int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    head = Solution().removeNthFromEnd(head, 2);
    printLinkedList(head);

    deleteLinkedList(head);

    return 0;
}