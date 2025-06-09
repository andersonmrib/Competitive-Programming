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

void getPreOrder(Node *root, bool &first){
  if(root != NULL){
    if(first){
      cout << (char)(root->key + '0');
      first = false;
    }
    else
      cout << " " << (char)(root->key + '0');
    getPreOrder(root->left, first);
    getPreOrder(root->right, first);
  }
}

void getInfixOrder(Node *root, bool &first){
  if(root != NULL){
    getInfixOrder(root->left, first);
    if(first){
      cout << (char)(root->key + '0');
      first = false;
    }
    else
      cout << " " << (char)(root->key + '0');
    getInfixOrder(root->right, first);
  }
}

void getPostOrder(Node *root, bool &first){
  if(root != NULL){
    getPostOrder(root->left, first);
    getPostOrder(root->right, first);
    if(first){
      cout << (char)(root->key + '0');
      first = false;
    }
    else
      cout << " " << (char)(root->key + '0');
  }
}

int main(){

  speedBoost;
  string op; char obj;

  bool create = true, control;
  Node *root = NULL;
  while(cin >> op){

    control = true;

    if(op == "I"){
      cin >> obj;
      int value = obj - '0';

      if(create){
        root = new Node(value);
        create = false;
      }
      else root = insert(root, value);
    }

    else if(op == "P"){
      cin >> obj;
      int value = obj - '0';

      if(search(root, value) != NULL)
        cout << obj << " existe\n";
      else
        cout << obj << " nao existe\n";
    }

    else if(op == "PREFIXA"){
      getPreOrder(root, control);
      cout << "\n";
    }

    else if(op == "INFIXA"){
      getInfixOrder(root, control);
      cout << "\n";
    }

    else{
      getPostOrder(root, control);
      cout << "\n";
    }
  }

  return 0;
}
