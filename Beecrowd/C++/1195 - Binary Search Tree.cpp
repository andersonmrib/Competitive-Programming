#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct Node{
  int key;
  Node *right;
  Node *left;
  Node(int item){
    key = item;
    left = NULL;
    right = NULL;
  }
};

Node* insert(Node *node, int key){

  if(node == NULL)
    return new Node(key);

  if(node->key == key)
    return node;

  if(node->key < key)
    node->right = insert(node->right, key);

  else
    node->left = insert(node->left, key);
  return node;
}

void preorder(Node* root){
  if(root != NULL){
    cout << " " << root->key;
    preorder(root->left);
    preorder(root->right);
  }
}

void inorder(Node* root){
  if(root != NULL){
    inorder(root->left);
    cout << " " << root->key;
    inorder(root->right);
  }
}

void postorder(Node* root){
  if(root != NULL){
    postorder(root->left);
    postorder(root->right);
    cout << " " << root->key;
  }
}

int main(){

  speedBoost;
  int c; cin >> c;
  int numCases = 0;
  while(c--){

    int n; cin >> n;
    vector<int> vec(n);
    for(int i=0; i<n; i++)
      cin >> vec[i];

    Node* root = new Node(vec[0]);
    for(int i=1; i<n; i++)
      root = insert(root, vec[i]);

    cout << "Case " << ++numCases << ":\n";
    cout << "Pre.:"; preorder(root);
    cout << "\nIn..:"; inorder(root);
    cout << "\nPost:"; postorder(root);
    cout << "\n\n";

  }

  return 0;
}
