#include "header.h"
#include <iostream>

void Tree::create() {
  Queue q = Queue();
  int x;
  tnode *p, *t;

  cout << "Enter the value of root node: ";
  cin >> root->data;

  q.enqueue(root);
  while (!q.isEmpty()) {
    p = q.dequeue();
    cout << "Enter the value for left child of " << p->data
         << ", if left child doesn't exist, input '-1': ";
    cin >> x;
    if (x != -1) {
      t = new tnode;
      t->data = x;
      t->left = t->right = nullptr;
      p->left = t;

      q.enqueue(t);
    }

    cout << "Enter the value for right child of " << p->data
         << ", if right child doesn't exist, input '-1': ";
    cin >> x;
    if (x != -1) {
      t = new tnode;
      t->data = x;
      t->left = t->right = nullptr;
      p->right = t;

      q.enqueue(t);
    }
  }
}

void Tree::preorder(tnode *p) {
  if (p) {
    cout << p->data << ", ";
    preorder(p->left);
    preorder(p->right);
  }
}

void Tree::inorder(tnode *p) {
  if (p) {
    inorder(p->left);
    cout << p->data << ", ";
    inorder(p->right);
  }
}

void Tree::postorder(tnode *p) {
  if (p) {
    postorder(p->left);
    postorder(p->right);
    cout << p->data << ", ";
  }
}

void Tree::iterpreorder() {
  Stack st;
  tnode *t = root;
  while (t || !st.isEmpty()) {
    if (t) {
      cout << t->data << ", ";
      st.push(t);
      t = t->left;
    } else {
      t = st.pop();
      t = t->right;
    }
  }
  cout << endl;
}

void Tree::iterinorder() {
  Stack st;
  tnode *t = root;
  while (t || !st.isEmpty()) {
    if (t) {
      st.push(t);
      t = t->left;
    } else {
      t = st.pop();
      cout << t->data << ", ";
      t = t->right;
    }
  }
  cout << endl;
}

void Tree::levelorder() {
  Queue q;
  q.enqueue(get_root());
  cout << get_root()->data;
  while (!q.isEmpty()) {
    tnode *temp = q.dequeue();
    if (temp->left) {
      cout << temp->left->data;
      q.enqueue(temp->left);
    }
    if (temp->right) {
      cout << temp->right->data;
      q.enqueue(temp->right);
    }
  }
}

int Tree::count_nodes(tnode *p) {
  int x, y;
  if (p) {
    x = count_nodes(p->left);
    y = count_nodes(p->right);
    return x + y + 1;
  }
  return 0;
}

int Tree::height(tnode *p) {
  int x, y;
  if (p) {
    x = height(p->left);
    y = height(p->right);
    if (x > y)
      return x + 1;
    else
      return y + 1;
  }
  return 0;
}

int Tree::count_leaf_nodes(tnode *p) {
  int x, y;
  if (p) {
    x = count_leaf_nodes(p->left);
    y = count_leaf_nodes(p->right);
    // count only those nodes that don't have any child
    if (!(p->left || p->right))
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}

int Tree::count_degree_two_nodes(tnode *p) {
  int x, y;
  if (p) {
    x = count_degree_two_nodes(p->left);
    y = count_degree_two_nodes(p->right);
    // count only those nodes that have both the childs
    if (p->left && p->right)
      return x + y + 1;
    else
      return x + y;
  }
  return 0;
}
