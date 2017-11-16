#include <iostream>
#include <cassert>

using namespace std;


/// Definition for singly-linked list.
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

    ListNode* curNode = head;
    while(curNode != NULL){
        cout << curNode->val << " -> ";
        curNode = curNode->next;
    }

    cout << "NULL" << endl;

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

ListNode* findNode(ListNode* head, int x){

    ListNode* curNode = head;
    while(curNode != NULL){
        if(curNode->val == x)
            return curNode;
        curNode = curNode->next;
    }
    return NULL;
}

// 237. Delete Node in a Linked List
// https://leetcode.com/problems/delete-node-in-a-linked-list/description/
// 时间复杂度: O(1)
// 空间复杂度: O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {

        // 注意: 这个方法对尾节点不适用。题目中要求了给定的node不是尾节点
        // 在assert中, 我们使用node->next != NULL确保了node不是尾节点
        assert(node != NULL && node->next != NULL);

        node->val = node->next->val;
        ListNode* delNode = node->next;
        node->next = delNode->next;

        delete delNode;

        return;
    }
};

int main() {

    int arr[] = {1, 2, 3, 4};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    // 找到值为2的节点, 并调用我们的算法删除
    ListNode* node2 = findNode(head, 2);
    Solution().deleteNode(node2);
    printLinkedList(head);

    deleteLinkedList(head);

    return 0;
}