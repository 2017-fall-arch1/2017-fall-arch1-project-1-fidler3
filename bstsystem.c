#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "bst.h"

int gets_n(char *s, int limit){
  char *p =s;
  char c;
  if(fgets(s, limit, stdin)){
    while((c=*p) && c != '\n'){
      p++;
    }
    if(c=='\n'){
      *p=0;
    }
  }
  return (p-s);
}

void writer(FILE *fp, Treenode *root){
  Treenode *t = root;
  if(t == NULL)
    return; 
  writer(fp, t->left);
  fprintf(fp,"%s \n", t->str);
  writer(fp, t->right);
 
}

int main(){
  Treenode *root = NULL;
  char buf[100];
  FILE *pf = fopen("names.txt","r+");

  while(fgets(buf, 100, pf)){
    strtok(buf, "\n");
    root = insert(root, buf);
  }

  printf("List contents prior to reading inputs:   \n");

  treeprint(root);
  
  printf("Add new names to the tree \n");
  
  while(gets_n(buf, 100)){
     root = insert(root, buf);
  }
  
  printf("Updated list: \n");
  treeprint(root);

  printf("Delete names: \n");
  while(gets_n(buf, 100)){
    root = delete(root, buf);
  }
  
  // writer(pf, root);
  // printf("New file created \n");

  treeprint(root);
  
  //  char word[MAXWORD];

  // root = NULL;
  // while(getword(word, MAXWORD) != EOF)
  // if(isalpha(word[0]))
  //  root = insert(root, word);

  // print(root);
  // return 0;
  //print(root);*/
  /*
  char *s = "bob";
  char *t = "will";
  char *u = "aaron";
  
  root = insert(root, s);
  root = insert(root, t);
  root = insert(root, u);
  treeprint(root);

  root = delete(root, s);
  treeprint(root); */
  fclose(pf);
  return 1;
}
