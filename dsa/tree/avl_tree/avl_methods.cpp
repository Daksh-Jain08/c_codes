#include "header.h"

tnode *Tree::insert(tnode *p, int value) {
  if (!p) {
    tnode *t = new tnode;
    t->data = value;
    t->left = t->right = nullptr;
    t->height = 1;
    if (p == root)
      root = t;
    return t;
  }
  if (p->data > value)
    p->left = insert(p->left, value);
  else if (p->data < value)
    p->right = insert(p->right, value);
  p->height = nodeHeight(p);

  if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
    return LLrotation(p);
  if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
    return LRrotation(p);
  if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
    return RRrotation(p);
  if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
    return RLrotation(p);

  return p;
}

int Tree::nodeHeight(tnode *p) {
  int hl, hr;
  hl = p && p->left ? p->left->height : 0;
  hr = p && p->right ? p->right->height : 0;

  return hl > hr ? hl + 1 : hr + 1;
}

int Tree::balanceFactor(tnode *p) {
  int hl, hr;
  hl = p && p->left ? p->left->height : 0;
  hr = p && p->right ? p->right->height : 0;

  return hl - hr;
}

tnode *Tree::LLrotation(tnode *p) {
  tnode *plr = p->left->right, *pl = p->left;
  pl->right = p;
  p->left = plr;
  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);

  if (p == root)
    root = pl;
  return pl;
}

tnode *Tree::RRrotation(tnode *p) {
  tnode *pr = p->right, *prl = p->right->left;
  pr->left = p;
  p->right = prl;
  p->height = nodeHeight(p);
  pr->height = nodeHeight(pr);

  if (p == root)
    root = pr;
  return pr;
}

tnode *Tree::LRrotation(tnode *p) {
  tnode *pl = p->left, *plr = p->left->right;
  p->left = plr->right;
  pl->right = plr->left;
  plr->right = p;
  plr->left = pl;
  p->height = nodeHeight(p);
  pl->height = nodeHeight(pl);
  plr->height = nodeHeight(plr);

  if (p == root)
    root = plr;
  return plr;
}

tnode *Tree::RLrotation(tnode *p) {
  tnode *pr = p->right, *prl = p->right->left;
  p->right = prl->left;
  pr->left = prl->right;
  prl->left = p;
  prl->right = pr;

  prl->height = nodeHeight(prl);
  pr->height = nodeHeight(pr);
  p->height = nodeHeight(p);

  if (p == root)
    root = prl;
  return prl;
}

tnode *Tree::inorderPre(tnode *p) {
  if (p)
    p = p->left;
  else
    return nullptr;
  while (p->right)
    p = p->right;
  return p;
}

tnode *Tree::inorderSuc(tnode *p) {
  if (p)
    p = p->right;
  else
    return nullptr;
  while (p->left)
    p = p->left;
  return p;
}

tnode *Tree::rDelete(tnode *p, int key) {
  if (!p->left && !p->right) {
    if (p == root)
      root = nullptr;
    free(p);
    return nullptr;
  }
  if (p->data > key)
    p->left = rDelete(p->left, key);
  else if (p->data < key)
    p->right = rDelete(p->right, key);
  else {
    if (p->left->height > p->right->height) {
      tnode *q = inorderPre(p);
      p->data = q->data;
      p->left = rDelete(p->left, q->data);
    } else {
      tnode *q = inorderSuc(p);
      p->data = q->data;
      p->right = rDelete(p->right, q->data);
    }
  }
  p->height = nodeHeight(p);

  if (balanceFactor(p) == 2 && balanceFactor(p->left) == 1)
    return LLrotation(p);
  if (balanceFactor(p) == 2 && balanceFactor(p->left) == -1)
    return LRrotation(p);
  if (balanceFactor(p) == 2 && balanceFactor(p->left) == 0)
    return LLrotation(p);
  if (balanceFactor(p) == -2 && balanceFactor(p->right) == -1)
    return RRrotation(p);
  if (balanceFactor(p) == -2 && balanceFactor(p->right) == 1)
    return RLrotation(p);
  if (balanceFactor(p) == -2 && balanceFactor(p->right) == 0)
    return RRrotation(p);
  return p;
}
