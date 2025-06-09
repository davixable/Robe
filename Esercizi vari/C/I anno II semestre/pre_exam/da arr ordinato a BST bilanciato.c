/*
dato un array ordinato, restituire un BST bilanciato
*/
typedef struct TreeNode {
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* make_balanced_BST(int* arr, int N) {
	if (N == 0) {
		return NULL;
	}
	int mid = N / 2;
	TreeNode* root = malloc(sizeof(Node));
	root->value = arr[mid];
	root->left = make_balanced_BST(arr, mid);
	root->right = make_balanced_BST(arr + mid+1, N - mid - 1);
	return root;
}