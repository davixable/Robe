typedef struct TreeNode {
	int value;
	struct TreeNode* left;
	struct TreeNode* right;
}TreeNode;

TreeNode* inalbera(TreeNode* root, int *arr, int N) {
	if (N == 0) {
		return root;
	}
	TreeNode* new_node = malloc(sizeof(TreeNode));
	new_node->value = arr[0];
	new_node->left = NULL;
	new_node->right = NULL;

	if (!root) {
		root = new_node;
	}
	else {
		TreeNode* curr = root;
		TreeNode* prec = NULL;
		while (curr) {
			if (new_node->value < curr->value) {
				prec = curr;
				curr = curr->left;
			}
			else {
				prec = curr;
				curr = curr->right;
			}
		}
		if (new_node->value <= prec->value) {
			prec->left = new_node;
		}
		else {
			prec->right = new_node;
		}
	}
	inalbera(root, arr + 1, N - 1);
	return root;
}