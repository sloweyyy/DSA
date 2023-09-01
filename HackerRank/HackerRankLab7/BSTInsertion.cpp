#include <bits/stdc++.h>

using namespace std;

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

class Solution {
    public:
  	
  	void preOrder(Node *root) {
		
      	if( root == NULL )
          	return;
      
      	std::cout << root->data << " ";
      	
      	preOrder(root->left);
      	preOrder(root->right);
    }

/*
Node is defined as 

class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/

    Node * insert(Node * root, int data) {
        Node* newNode = new Node(data);
        if (root == NULL) {
            root = newNode;
            return root;
        }
        Node* current = root;
        while (true) {
            if (data < current->data) {
                if (current->left == NULL) {
                    current->left = newNode;
                    return root;
                }
                else {
                    current = current->left;
                }
            }
            else {
                if (current->right == NULL) {
                    current->right = newNode;
                    return root;
                }
                else {
                    current = current->right;
                }
            }
        }


        
        return root;
    }

};

int main() {
  
    Solution myTree;
    Node* root = NULL;
    
    int t;
    int data;

    std::cin >> t;

    while(t-- > 0) {
        std::cin >> data;
        root = myTree.insert(root, data);
    }
  	
    myTree.preOrder(root);
  
    return 0;
}
