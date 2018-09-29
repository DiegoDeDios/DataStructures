#include <stdio.h>
#include <stdlib.h>
/* 
**********Implementación de un Arbol Binario de Busqueda en C.***********
*Autor: Diego Alonso Martinez de Dios
*Fecha: 28 de Septiembre de 2018
*Nombre del archivo: ABB.c
*Dependencias: Ninguna
*/
struct Node{ //Crea una estructura de tipo Nodo
struct Node* left;
struct Node* right;
char key;
};

void inOrderTraversal(struct Node* root);
void preOrderTraversal(struct Node* root);
void postOrderTraversal(struct Node* root);
struct Node* Insert(struct Node* root, char key);
struct Node* crearNodo(char key);
struct Node* search(struct Node* root,char key);
struct Node* deleteNode(struct Node* root,char key);
struct Node* minimum(struct Node* root);
struct Node* maximum(struct Node* root);
char getKey(struct Node* node);
void deleteTree(struct Node* root);

int main(){
    struct Node* root;
    root = NULL;
    root = Insert(root,'h');
    Insert(root, 'd');
    Insert(root, 'a');
    Insert(root, 'b');
    Insert(root, 'z');
    printf("*****Recorrido en orden simetrico*******\n");
    inOrderTraversal(root);
    printf("Valor de la raiz: ");
    printf("%c\n",getKey(root));
    printf("Valor Minimo: ");
    printf("%c\n",getKey(minimum(root)));
    printf("Valor Maximo: ");
    printf("%c\n",getKey(maximum(root)));
    printf("Borrar el valor d\n");
    deleteNode(root,'d');
    printf("Arbol nuevo\n");
    inOrderTraversal(root);
   return 0; 
}
void inOrderTraversal(struct Node* root){
    if(root!=NULL){
        inOrderTraversal((*root).left);
        printf("Valor del nodo: %c\n",(*root).key);
        inOrderTraversal((*root).right);
    }
}
void preOrderTraversal(struct Node* root){
    if(root!=NULL){
        printf("Valor del nodo: %c\n",(*root).key);
        preOrderTraversal((*root).left);
        preOrderTraversal((*root).right);
    }
}
void postOrderTraversal(struct Node* root){
    if(root!=NULL){
        postOrderTraversal((*root).left);
        postOrderTraversal((*root).right);
        printf("Valor del nodo: %c\n",(*root).key);
    }
}
struct Node* crearNodo(char key){
    struct Node* new = (struct Node*)malloc(sizeof(struct Node)); // Reservo memoria en el Heap para crear un nuevo nodo
    (*new).key=key;
    (*new).left = NULL;
    (*new).right=NULL;
    return new;
}
struct Node* Insert(struct Node* root, char key){
    if(root == NULL){
        return crearNodo(key);
    }
    else if(key < (*root).key) {
        (*root).left = Insert((*root).left,key);
    }
    else if(key > (*root).key){
        (*root).right = Insert((*root).right,key);
    }
    return root;
}
struct Node* search(struct Node* root, char key){
    if((*root).key==key){
        printf("Encontre el valor\n");
        return root;
    }
    else if(key < (*root).key){
        return search((*root).left,key);
    }
    else if(key > (*root).key){
        return search((*root).right,key);
    }
}
struct Node* minimum(struct Node* root){
    struct Node* temp = root;
    while((*temp).left!=NULL){
        temp = (*temp).left;
    }
    return temp;
}
struct Node* maximum(struct Node* root){
    struct Node* temp = root;
    while((*temp).right!=NULL){
        temp = (*temp).right;
    }
    return temp;
}
struct Node* deleteNode(struct Node* root, char key){
    if(root==NULL){
        return NULL;
    }
    if(key > (*root).key){
        (*root).right = deleteNode((*root).right,key);
    }
    else if(key < (*root).key){
        (*root).left = deleteNode((*root).left,key);
    }
    else{
        if((*root).left == NULL){
            struct Node *temp = (*root).right;
            free(root);
            return temp;
        }
        if((*root).right == NULL){
            struct Node *temp = (*root).left;
            free(root);
            return temp;
        }
        else{
            struct Node* temp = minimum((*root).right);
            (*root).key = (*temp).key;
            (*root).right = deleteNode((*root).right,(*temp).key);
        }
    }
    return root;
}
void deleteTree(struct Node* root){
    free(root);
}
char getKey(struct Node* node){
    return (*node).key;
}