// Implementation from
// https://github.com/shahidul2k9/problem-solution/blob/master/uva%20online%20judge/12347%20-%20Binary%20Search%20Tree.cpp

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

Node *tmp;
void goDown(Node *cur, int val){
  if(cur->key <= val){
    if(cur->right == NULL){
      cur->right = new Node(val);
      tmp = cur->right;
    }
    else
      goDown(cur->right, val);
  }
  else goDown(cur->left, val);
}

void postOrder(Node *cur){
  if(cur == NULL) return;
  postOrder(cur->left);
  postOrder(cur->right);
  cout << cur->key << "\n";
}

int main(){

  speedBoost;
  Node *root;

  int value; cin >> value;
  root = new Node(value);
  tmp = root;
  while(cin >> value){
    if(value < tmp->key){
      tmp->left = new Node(value);
      tmp = tmp->left;
    }
    else
      goDown(root, value);
  }

  postOrder(root);

  return 0;
}
