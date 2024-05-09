#include <iostream>
#include <list>
using namespace std;

// 實現簡短鏈表
// https://blog.csdn.net/qq_33919450/article/details/126392241
// https://stackoverflow.com/questions/19713256/adding-data-in-linked-list-using-for-loop

struct ListNode {
    // 存在建構子 ListNode()，預設定 val 為 0。 next 為空指針
    // 存在建構子 ListNode(int x)，傳入參數 x 指定為 val。 next 為空指針
    // 存在建構子 ListNode(int x, ListNode *next)，傳入參數 x 指定為 val。傳入參數指標變數 next 指定為 next。
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {

        ListNode *temp = head;
        while(temp && temp->next){
            // temp val 1 (0xa) next 1 (0xb) => 1=1 => temp val 1 (0xa) next 2 (0xc) => continue
            // temp val 1 (0xa) next 2 (0xc) => 1!=2 => temp val 2 (0xc) next 3 (0xd)
            if(temp->val == temp->next->val)
            {
                temp->next=temp->next->next;
                continue;
            }
            temp=temp->next;
        }
        // 因為 temp=temp->next，temp 地址已改成最後一個元素所在位置
        // 所以 return temp 的時候會只剩最後一個元素的地址，這樣不對
        // 但 head 還是第一個元素的地址，所以可以 return head，返回完整的鏈

        ListNode *tempcout = head;

        while (tempcout->next!=nullptr)
        {
            cout<<tempcout->val<<endl;
            cout<<tempcout->next<<endl;
            cout<<"===================="<<endl;
            tempcout=tempcout->next;
        }
        cout<<tempcout->val<<endl;
        cout<<tempcout->next<<endl;
        cout<<"===================="<<endl;

        return head;
        
    }
};


int main(){

    //如果有變數 MyStruct s，對其中成員的取用為點運算子 s.
    //如果採用指標方法存取MyStruct *ps，相對的存取方式必須使用箭頭運算子 ps->
    //當宣告為一般型態時 MyClass CA，就使用點(.)來存取Class中的成員
    //當宣告為指標型態時 MyClass *CA，就使用箭頭(->)來存取Class中的成員

    // 因為 class Solution 函式傳參是指標變數
    // 因此使用動態空間建構運算子 new 來建立 node，並使用指標變數儲存地址
    ListNode *start=nullptr,*temp,*addNode;
    list<int> valueList = {1,1,2,3,3};
    for (int n: valueList)
    {

        addNode = new ListNode(n);

        if(start==nullptr)
        {
            start = new ListNode(n);
            temp=start;
        }
        else
        { 
            while (temp->next!=nullptr)
            {
               temp=temp->next;
            }
            temp->next=addNode;
            // start temp 1 (0xa) 放頭
            // temp->next nullptr => temp 1 (0xa) temp->next 1 (0xb) 頭有 沒 next 放 next
            // temp->next 1 (0xb) => temp 1 (0xb) temp->next 2 (0xc) 頭有 有 next 則改變 temp 並放入新的 next
        }
    }

    // ListNode *head = new ListNode(1);
    // ListNode *next1 = new ListNode(1);
    // ListNode *next2 = new ListNode(2);
    // ListNode *next2 = new ListNode(3);
    // ListNode *next2 = new ListNode(3);
    // head->next=next1;
    // next1->next=next2;
    // next2->next=nullptr;

    Solution solution;
    solution.deleteDuplicates(start);
    // 因為 temp=temp->next，temp 地址已改成最後一個元素所在位置
    // 但 start 還是第一個元素的地址，所以要傳 start 才能夠是完整的鏈

    delete start;
    delete temp;
    delete addNode;
    // 動態建構記得要釋放


}