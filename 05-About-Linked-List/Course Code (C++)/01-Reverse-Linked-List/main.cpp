#include <iostream>

using namespace std;

class Solution {
public:
    ListNode* reverseList(ListNode* head) {

        if( head == NULL )
            return NULL;

        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* nxt = cur->next;
        while( true ){
            cur->next = pre;
            pre = cur;
            cur = nxt;
            if( cur == NULL )
                break;
            else
                nxt = cur->next;
        }

        return pre;
    }
};

int main() {

    return 0;
}