#include "header.h"

Tree::Tree(int* arr, int n){
  root = nullptr;
  for(int i = 0; i<n; i++){
    root = rInsert(root, arr[i]);
  }
}

int Tree::height(tnode* p){
  int x,y;
  if(p){
    x = height(p->left);
    y = height(p->right);
    if(x>y)
      return x+1;
    else
      return y+1;
  }
  else
    return 0;
}

tnode* Tree::search(int key){
  tnode *t = root;
  while(t){
    if(t->data==key)
      return t;
    else if(t->data > key)
      t = t->left;
    else if(t->data < key)
      t = t->right;
  }
  return nullptr;
}

tnode* Tree::rSearch(tnode *p, int key){
  if(p){
    if(p->data==key)
      return p;
    else if(p->data>key)
      p = rSearch(p->left, key);
    else if(p->data<key)
      p = rSearch(p->right, key);
  }
  return p;
}

void Tree::insert(int value){

  tnode* p = root;

  while(p){
    if(p->data == value){
      cout<<"The value already exists in the BST."<<endl;
      return;
    }
    else if(p->data>value){
      if(p->left){
        p = p->left;
        continue;
      }
      else{
        tnode* t = new tnode;
        t->data = value;
        t->left=t->right=0;
        p->left = t;
        return;
      }
    }

    else if(p->data<value){
      if(p->right){
        p = p->right;
        continue;
      }
      else{
        tnode* t = new tnode;
        t->data = value;
        t->left=t->right=0;
        p->right = t;
        return;
      }
    }
  }
}

tnode* Tree::rInsert(tnode* p, int value){
  if(!p){
    tnode *t = new tnode;
    t->data = value;
    t->left=t->right=nullptr;
    return t;
  }
  if(p->data>value)
    p->left = rInsert(p->left, value);
  else if(p->data<value)
    p->right = rInsert(p->right, value);
  return p;
}

void Tree::inorder(tnode *p){
  if(p){
    inorder(p->left);
    cout<<p->data<<", ";
    inorder(p->right);
  }
}

tnode* Tree::inorderPredecessor(tnode *p){
  if(p)
    p = p->left;
  else
    return nullptr;
  while(p->right)
    p = p->right;
  return p;
}

tnode* Tree::inorderSuccessor(tnode *p){
  if(p)
    p = p->right;
  else
    return nullptr;
  while(p->left)
    p = p->left;
  return p;
}

tnode* Tree::deleteNode(tnode* p, int key){
  tnode* q;
  if(!p)
    return nullptr;
  if(!p->left && !p->right){
    if(p==root)
      root = nullptr;
    else
      free(p);
    return nullptr;
  }
  if(p->data > key)
    p->left = deleteNode(p->left, key);
  else if(p->data < key)
    p->right = deleteNode(p->right, key);
  else{
    if(height(p->left)>height(p->right)){
      q = inorderPredecessor(p);
      p->data = q->data;
      p->left = deleteNode(p->left,q->data);
    }
    else{
      q = inorderSuccessor(p);
      p->data = q->data;
      p->right = deleteNode(p->right,q->data);
    }
  }
  return p;
}

void Tree::createFromPre(int *arr, int n){
  tnode* t = new tnode;
  t->data = arr[0];
  t->left = t->right = nullptr;
  root = t;
  Stack st;
  int i = 1;
  tnode* p = root;
  while(i<n){
    if(arr[i]<p->data){
      t = new tnode;
      t->data = arr[i];
      t->left = t->right = nullptr;
      st.push(p);
      p->left = t;
      p = t;
      i++;
    }
    else{
      if(!st.isEmpty() && st.get_top()->data<arr[i]){
        p = st.pop();
      }
      else{
        t = new tnode;
        t->data = arr[i];
        t->left = t->right = nullptr;
        p->right = t;
        p = t;
        i++;
      }
    }
  }
}

void Tree::createFromPost(int *arr, int n){
  int i = n-1;
  Stack st;
  tnode* t = new tnode;
  t->data = arr[i--];
  t->left = t->right = nullptr;
  root = t;
  tnode* p = root;
  while(i>-1){
    if(arr[i]>p->data){
      t = new tnode;
      t->data = arr[i--];
      t->left = t->right = nullptr;
      p->right = t;
      st.push(p);
      p = t;
    }
    else{
      if(!st.isEmpty() && st.get_top()->data>arr[i]){
        p = st.pop();
      }
      else{
        t = new tnode;
        t->data = arr[i--];
        t->left = t->right = nullptr;
        p->left = t;
        p = t;
      }
    }
  }
}





