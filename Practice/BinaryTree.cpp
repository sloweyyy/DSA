#include <iostream>
#include <stack>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

Node* createNode(int value) {
    Node* node = new Node;
    node->data = value;
    node->left = NULL;
    node->right = NULL;
    return node;
}

Node* insertNode(Node* root, int value) {
    if (root == NULL) {
        root = createNode(value);
    } else if (value <= root->data) {
        root->left = insertNode(root->left, value);
    } else {
        root->right = insertNode(root->right, value);
    }
    return root;
}

void printInOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printInOrder(root->left);
    cout << root->data << " ";
    printInOrder(root->right);
}

void printPreOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printPostOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}

void preOrder(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int dem2Con(Node* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left != NULL && root->right != NULL) {
        return 1 + dem2Con(root->left) + dem2Con(root->right);
    }
    return dem2Con(root->left) + dem2Con(root->right);
}

int dem2ConStack(Node* root) {
    if (root == NULL) {
        return 0;
    }
    stack<Node*> s;
    s.push(root);
    int count = 0;
    while (!s.empty()) {
        Node* node = s.top();
        s.pop();
        if (node->left != NULL && node->right != NULL) {
            count++;
        }
        if (node->left != NULL) {
            s.push(node->left);
        }
        if (node->right != NULL) {
            s.push(node->right);
        }
    }
    return count;
}

int dem2ConQueue(Node *root) {
    if (root == NULL) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int count = 0;
    while (!q.empty()) {
        Node* node = q.front();
        q.pop();
        if (node->left != NULL && node->right != NULL) {
            count++;
        }
        if (node->left != NULL) {
            q.push(node->left);
        }
        if (node->right != NULL) {
            q.push(node->right);
        }
    }
    return count;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    int leftHeight = height(node->left);
    int rightHeight = height(node->right);
    if (leftHeight > rightHeight) {
        return leftHeight + 1;
    }
    return rightHeight + 1;
}

int heightStack(Node *root) {
    if (root == NULL) {
        return 0;
    }
    stack<Node*> s;
    s.push(root);
    int height = 0;
    while (!s.empty()) {
        int size = s.size();
        while (size > 0) {
            Node* node = s.top();
            s.pop();
            if (node->left != NULL) {
                s.push(node->left);
            }
            if (node->right != NULL) {
                s.push(node->right);
            }
            size--;
        }
        height++;
    }
    return height;
}

int heightQueue(Node *root) {
    if (root == NULL) {
        return 0;
    }
    queue<Node*> q;
    q.push(root);
    int height = 0;
    while (!q.empty()) {
        int size = q.size();
        while (size > 0) {
            Node* node = q.front();
            q.pop();
            if (node->left != NULL) {
                q.push(node->left);
            }
            if (node->right != NULL) {
                q.push(node->right);
            }
            size--;
        }
        height++;
    }
    return height;
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        root = insertNode(root, value);
    }
    printPreOrder(root);
    cout << endl;
    printInOrder(root);
    cout << endl;
    printPostOrder(root);
    cout << endl;
    cout << "So nut co 2 con la: " << endl;
    cout << dem2Con(root) << endl;
    cout << dem2ConStack(root) << endl;
    cout << dem2ConQueue(root) << endl;
    cout << "Chieu cao la: " << endl;
    cout << height(root) << endl;
    cout << heightStack(root) << endl;
    cout << heightQueue(root) << endl;
    return 0;
}
