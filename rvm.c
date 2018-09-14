#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int info;
    struct node * left;
    struct node * right;
}arvore;

void adicionar(arvore * tree, int n){
    if (tree->info == 0){
        tree->info = n;
    }else{
        if (n < tree->info){
            if (tree->left!=NULL){
                adicionar(tree->left,n);
            }else{
                tree->left = malloc(sizeof(arvore));
                tree->left->info = n;
                tree->left->left = NULL;
                tree->left->right= NULL;
            }
        }else{
            if (n > tree->info){
            if (tree->right != NULL){
                adicionar(tree->right,n);
            }else{
                tree->right=malloc(sizeof(arvore));
                tree->right->info = n;
                tree->right->left = NULL;
                tree->right->left = NULL;
            }
        }}
    }
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
    arvore * test = malloc(sizeof(arvore));
    for(i=1;i<=C;i++){
        scanf("%d",&N);
        test->info = 0;
        test->left = NULL;
        test->right = NULL;
        for(j=0;j<N;j++){
            scanf("%d",&temp);
            adicionar(test,temp);
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
