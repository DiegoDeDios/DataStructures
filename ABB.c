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
    printf("*****Recorrido en orden de profundidad******\n");
    preOrderTraversal(root);
    printf("******Recorrido en postorden********\n");
    postOrderTraversal(root);

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
        inOrderTraversal((*root).left);
        inOrderTraversal((*root).right);
    }
}
void postOrderTraversal(struct Node* root){
    if(root!=NULL){
        inOrderTraversal((*root).left);
        inOrderTraversal((*root).right);
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
