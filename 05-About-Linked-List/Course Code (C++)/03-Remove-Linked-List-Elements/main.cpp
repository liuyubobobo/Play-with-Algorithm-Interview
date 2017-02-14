#include <iostream>

using namespace std;

///Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

/// LinkedList Test Helper Functions
ListNode* createLinkedList(int arr[], int n){

    if( n == 0 )
        return NULL;

    ListNode* head = new ListNode(arr[0]);
    ListNode* curNode = head;
    for( int i = 1 ; i < n ; i ++ ){
        curNode->next = new ListNode(arr[i]);
        curNode = curNode->next;
    }

    return head;
}

void printLinkedList(ListNode* head){

    if( head == NULL ){
        cout<<"NULL"<<endl;
        return;
    }

    ListNode* curNode = head;
    while( curNode != NULL ){
        cout<<curNode->val;
        if( curNode->next != NULL )
            cout<<" -> ";
        curNode = curNode->next;
    }

    cout<<endl;

    return;
}

// 不使用虚拟头结点
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {

        while( head != NULL && head->val == val ){

            ListNode* node = head;
            head = head->next;
            delete node;
        }

        if( head == NULL )
            return head;

        ListNode* p = head;
        while( p->next != NULL ){

            if( p->next->val == val ){
                ListNode* delNode = p->next;
                p->next = delNode->next;
                delete delNode;
            }
            else
                p = p->next;
        }

        return head;
    }
};

int main() {

    int arr[] = {1, 2, 6, 3, 4, 5, 6};
    int n = sizeof(arr)/sizeof(int);

    ListNode* head = createLinkedList(arr, n);
    printLinkedList(head);

    Solution().removeElements( head, 6);
    printLinkedList(head);

    return 0;
}