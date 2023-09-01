#include <bits/stdc++.h>

using namespace std;

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}


SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    SinglyLinkedListNode* head = NULL;
    SinglyLinkedListNode* tail = NULL;
    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            if (head == NULL) {
                head = head1;
                tail = head1;
            } else {
                tail->next = head1;
                tail = head1;
            }
            head1 = head1->next;
        } else {
            if (head == NULL) {
                head = head2;
                tail = head2;
            } else {
                tail->next = head2;
                tail = head2;
            }
            head2 = head2->next;
        }
    }
    if (head1 != NULL) {
        if (head == NULL) {
            head = head1;
            tail = head1;
        } else {
            tail->next = head1;
            tail = head1;
        }
    }
    if (head2 != NULL) {
        if (head == NULL) {
            head = head2;
            tail = head2;
        } else {
            tail->next = head2;
            tail = head2;
        }
    }
    return head;
}
SinglyLinkedListNode* mergeList(SinglyLinkedListNode* head_list1,SinglyLinkedListNode* head_list2){
    SinglyLinkedListNode* head = NULL;
    SinglyLinkedListNode* tail = NULL;
    while(head_list1 != NULL && head_list2 != NULL){
        if(head_list1->data < head_list2->data){
            if(head == NULL){
                head = head_list1;
                tail = head_list1;
            }
            else{
                tail->next = head_list1;
                tail = head_list1;
            }
            head_list1 = head_list1->next;
        }
        else{
            if(head == NULL){
                head = head_list2;
                tail = head_list2;
            }
            else{
                tail->next = head_list2;
                tail = head_list2;
            }
            head_list2 = head_list2->next;
        }
    }
    if(head_list1 != NULL){
        if(head == NULL){
            head = head_list1;
            tail = head_list1;
        }
        else{
            tail->next = head_list1;
            tail = head_list1;
        }
    }
    if(head_list2 != NULL){
        if(head == NULL){
            head = head_list2;
            tail = head_list2;
        }
        else{
            tail->next = head_list2;
            tail = head_list2;
        }
    }
    return head;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    int tests;
    cin >> tests;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        cin >> llist1_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            cin >> llist1_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }
      
      	SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        cin >> llist2_count;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            cin >> llist2_item;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}
