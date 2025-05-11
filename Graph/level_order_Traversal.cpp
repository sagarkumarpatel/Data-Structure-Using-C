#include<iostream>
#include<queue>
using namespace std;

class Node{
public:
int data;
Node* left;
Node* right;

Node(int val){
    data=val;
    left=right=NULL;
}
};

Node* insert(Node* root, int value) {
    if (root == NULL)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}

void levelOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    queue<Node*>q;
    q.push(root);
    while(!q.empty()){
        Node* curr=q.front();
        q.pop();
        cout<<curr->data<<" ";
        if(curr->left!=NULL){
            q.push(curr->left);
        }
        if(curr->right!=NULL){
            q.push(curr->right);
        }
    }
    cout<<endl;
}

int main(){
    Node* root = NULL;
    vector<int> values = {1,2,3,4,5};

    // Insert each value into the BST
    for (int val : values) {
        root = insert(root, val);
    }
    levelOrderTraversal(root);
    return 0;
}



