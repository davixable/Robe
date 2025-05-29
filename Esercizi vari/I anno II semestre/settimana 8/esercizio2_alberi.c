#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
 int value;
 struct Node* left;
 struct Node* right;
}Albero;

Albero* make_tree(int* arr, int n);
Albero* free_tree(Albero* root);
int search_target(Albero* root, int target);
void print_tree_preorder(Albero* root);
void print_tree_inorder(Albero* root);
void print_tree_postorder(Albero* root);

Albero* make_tree(int* arr, int size) {
 if (size == 0) {
  return NULL;
 }
 int mid = size / 2;
 Albero *root = malloc(sizeof(Albero));
 root->value = arr[mid];
 root->left = make_tree(arr, mid);
 root->right = make_tree(arr + mid + 1, size - mid - 1);
 return root;
}

void print_tree_preorder(Albero* root) {
 if (root == NULL) {
  return;
 }
 printf("%d -> ", root->value);
 print_tree_preorder(root->left);
 print_tree_preorder(root->right);
 
}

void print_tree_inorder(Albero* root) {
 if (root == NULL) {
  return;
 }
 print_tree_inorder(root->left);
 printf("%d -> ", root->value);
 print_tree_inorder(root->right);
 
}

void print_tree_postorder(Albero* root) {
 if (root == NULL) {
  return;
 }
 print_tree_postorder(root->left);
 print_tree_postorder(root->right);
 printf("%d -> ", root->value);
 
}

int search_target(Albero* root, int target) {
 if (!root) {
  return 0;
 }
 if (root->value == target) {
  return 1;
 }
 else {
  if (root->value < target) {
   return search_target(root->right, target);
  }
  else {
   return search_target(root->left, target);
  }
 }
}

Albero* free_tree(Albero* root) {
 if (!root) {
  return NULL;
 }
 free_tree(root->left);
 free_tree(root->right);
 free(root);
 return root;
}

int main() {
 int arr[] = { 5,8,10,15,20,21,22,23,55,100,910 };
 int target;
 int n = sizeof(arr) / sizeof(arr[0]);
 Albero* root = NULL;
 root = make_tree(arr,n);
 printf("\nStampa in preordine:\n");
 print_tree_preorder(root);
 printf("\nStampa in ordine:\n");
 print_tree_inorder(root);
 printf("\nStampa in postordine:\n");
 print_tree_postorder(root);
 printf("\nQuale numero vuoi cercare?\n");
 scanf("%d", &target);
 int found=search_target(root,target);
 if (found) {
  printf("Il numero e' presente nell'albero.\n");
 }
 else {
  printf("Il numero NON e' presente nell'albero.\n");
 }
 root = free_tree(root);
 return 0;
}