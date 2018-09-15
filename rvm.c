#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int info;
    struct node * left;
    struct node * right;
}arvore;

arvore * createTree(int info){
    arvore *root;
    root = malloc(sizeof(arvore));
    root->info = info;
    root->left = NULL;
    root->right = NULL;
    return(root);
}





arvore * adicionar(arvore * tree, int n){
    if (tree == 0){
        return(createTree(n));
    }else{
        if (n < tree->info){
            tree->left = adicionar(tree->left,n);
        }else{
            tree -> right = adicionar(tree->right,n);
        }
    }
    return(tree);
}

void prefixo(arvore * n){
    if (n!= NULL){
        printf(" %d",n->info);
        prefixo(n->left);
        prefixo(n->right);
    }
}
void infixo (arvore * n){
    if (n!=NULL){
        infixo(n->left);
        printf(" %d",n->info);
        infixo(n->right);
    }
}
void posfixo (arvore * n){
    if (n!=NULL){
        posfixo(n->left);
        posfixo(n->right);
        printf(" %d",n->info);
    }
}

int main(){
    int C,N,temp,i,j;
    scanf("%d",&C);
    arvore * test = NULL;
    for(i=1;i<=C;i++){
        scanf("%d",&N);
        test = NULL;
        for(j=0;j<N;j++){
            scanf("%d",&temp);
            test = adicionar(test,temp);
        }
        printf("Case %d:\nPre.:",i);
        prefixo(test);
        printf("\nIn..:");
        infixo(test);
        printf("\nPost:");
        posfixo(test);
        printf("\n\n");
    }
}
