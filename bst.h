#ifndef bst_included
#define bst_included

/*item for the BST*/
typedef struct Tnode{
  struct Tnode *left, *right;
  char *str;
}Treenode;

/*create a new list*/
//Treenode *BSTalloc();
//}

/*free memory associated with list*/
//void bstFree(Treenode *lp);

/* insert a name */
Treenode* insert(Treenode *lp, char *s);

/*delete a name*/
Treenode* delete(Treenode *lp, char *s);

/*print all names*/
void treeprint(Treenode *lp);

#endif
