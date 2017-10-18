#include <stdio.h> /*for puts*/
#include <stdlib.h> /*for malloc*/
#include <assert.h> /*for assert*/
#include <string.h>
#include "bst.h"

Treenode *bstAlloc(char *s){
  Treenode *lp = (Treenode *)malloc(sizeof(Treenode));
  lp->str =strdup(s);
  lp->left=NULL; lp->right=NULL;
  return lp;
}

Treenode* insert(Treenode *lp, char *s){
  int com;
  char *scopy;
  
  if(lp == NULL){
    lp = bstAlloc(s);
    // lp->str = strdup(s);
    // lp->left = lp->right = NULL;
  }else{
    com = strcmp(s, lp->str); 
    if(com < 0){
      lp->left = insert(lp->left, s);
    }
    if(com > 0){
      lp->right = insert(lp->right, s);
    }
  }

  return lp;
}

void treeprint(Treenode *r){
  if(r != NULL){
    treeprint(r->left);
    printf(" %s\n", r->str);
    treeprint(r->right);
  }
}
Treenode* replacement(Treenode *p){
  Treenode *t = p;

  while(t->left!=NULL){
    t = t->left;
  }

  return t;
}

Treenode* delete(Treenode *lp, char *s){
  int com;
  com = strcmp(s, lp->str);
  if(lp == NULL){
    return lp;
  }
  if(com<0){
    lp->left = delete(lp->left, s);
  }
  else if(com>0){
    lp->right = delete(lp->right, s);
  }else{
    if(lp->left == NULL){
      Treenode *t = lp->right;
      free(lp);
      return t;
    }
    else if(lp->right == NULL){
      Treenode *t = lp->left;
      free(lp);
      return t;
    }
    
    Treenode *t = replacement(lp->right);
    lp->str = t->str;
    lp->right = delete(lp->right, t->str);
  }
  return lp;
}










		      
