#include <bits/stdc++.h>
#define speedBoost ios::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct Node{

  int key;
  Node *left;
  Node *right;
  Node(int item){
    key = item;
    left = NULL;
    right = NULL;
  }
};

Node *insert(Node *node, int key){

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

Node *search(Node *root, int key){

  if(root == NULL || root->key == key)
    return root;

  if(root->key < key)
    return search(root->right, key);

  return search(root->left, key);
}

Node *getPredecessor(Node *curr){
  curr = curr->left;
  while(curr != NULL && curr->right != NULL)
    curr = curr->right;
  return curr;
}

Node *getSuccessor(Node *curr){
  curr = curr->right;
  while(curr != NULL && curr->left != NULL)
    curr = curr->left;
  return curr;
}

Node *deleteNode(Node *root, int key){

  if(root == NULL)
    return root;

  if(root->key > key)
    root->left = deleteNode(root->left, key);

  else if(root->key < key)
    root->right = deleteNode(root->right, key);

  else{

    // Root has 0 children
    if(root->left == NULL){
      Node *temp = root->right;
      delete root;
      return temp;
    }

    // Root has left child
    if(root->right == NULL){
      Node *temp = root->left;
      delete root;
      return temp;
    }

    // Both children present;
    //Node *succ = getSuccessor(root);
    Node *pred = getPredecessor(root);
    root->key = pred->key;
    root->left = deleteNode(root->left, pred->key);
    //root->right = deleteNode(root->right, succ->key);
  }
  return root;
}

void getPreOrder(Node *root, bool &first){
  if(root != NULL){
    if(first){
      cout << root->key;
      first = false;
    }
    else
      cout << " " << root->key;
    getPreOrder(root->left, first);
    getPreOrder(root->right, first);
  }
}

void getInfixOrder(Node *root, bool &first){
  if(root != NULL){
    getInfixOrder(root->left, first);
    if(first){
      cout << root->key;
      first = false;
    }
    else
      cout << " " << root->key;
    getInfixOrder(root->right, first);
  }
}

void getPostOrder(Node *root, bool &first){
  if(root != NULL){
    getPostOrder(root->left, first);
    getPostOrder(root->right, first);
    if(first){
      cout << root->key;
      first = false;
    }
    else
      cout << " " << root->key;
  }
}

int main(){

  speedBoost;
  string op; int value;

  bool control;
  Node *root = NULL;
  while(cin >> op){

    control = true;

    if(op == "I"){
      cin >> value;
      root = insert(root, value);
    }

    else if(op == "P"){
      cin >> value;

      if(search(root, value) != NULL)
        cout << value << " existe\n";
      else
        cout << value << " nao existe\n";
    }

    else if (op == "R"){
      cin >> value;
      root = deleteNode(root, value);
    }

    else if(op == "PREFIXA"){
      getPreOrder(root, control);
      cout << "\n";
    }

    else if(op == "INFIXA"){
      getInfixOrder(root, control);
      cout << "\n";
    }

    else if(op == "POSFIXA"){
      getPostOrder(root, control);
      cout << "\n";
    }
  }

  return 0;
}
