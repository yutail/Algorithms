typedef struct treeNode {
	int data;
	treeNode *left;
	treeNode *right;
}treeNode;

typedef struct binaryTree {
	treeNode *root;
}binaryTree;

binaryTree *createTree() {
	binaryTree *tree = (binaryTree *)malloc(sizeof(binaryTree));
	tree->root = NULL;
	return tree;
}

treeNode *find(binaryTree *tree, int num) {
	if (tree->root == NULL)
		return NULL;
	treeNode *curr = tree->root;
	while(curr!=NULL && curr->data!=num) {
		if(curr->data < num)
			curr = curr->right;
		else
			curr = curr->left;
	}	
	return curr;
}

treeNode *insert(binaryTree *tree, int num) {
	if (tree->root == NULL) {
		treeNode *curr = newNode(num);
		return curr;
	}
	treeNode *curr = tree->root;
	while (curr->data!=num) {
		if(curr->data > num) {
			if(curr->left == NULL) {
				curr->left = newNode(num)
				break;
			}
			curr = curr->left
		}
		else {
			if(curr->right == NULL) {
				curr->right = newNode(num);
				break;
			}
			curr = curr->right;
		}
	}
	if (curr->data == num)
		printf("Node has already existed!");
	return tree->root;
}

treeNode *newNode(int num) {
	treeNode *curr = malloc(sizeof(treeNode));	
	curr->data = num;
    curr->left = curr->right = NULL;
    return curr;
}

void delete(binaryTree *tree, int num) {
	if (tree->root == NULL) {
        printf("Tree is empty!\n");
        exit(EXIT_FAILURE);
    }
	treeNode *curr = tree->root;
	treeNode *parent, *temp, *prev;
    
	while (curr!=NULL && curr->data!=num) {
		parent = curr;
		if (curr->data > num)
			curr = curr->left;
		else 
			curr = curr->right;	
	}
	
	if (curr == NULL) {    
        printf("No such element.\n");
        return;
    }
		
	else if (curr->left==NULL && curr->right==NULL) {
		if(parent->left == curr)
			parent->left = NULL;
		else
			parent->right = NULL;
		free(curr);
		curr = NULL;
	}
	else if (curr->left == NULL) {
		if(parent->left == curr)
 	       parent->left = curr->right;
        else
           parent->right = curr->right;
        free(curr);
        curr = NULL;
	}
	else if (curr->right == NULL) {
		if(parent->left == curr)
            parent->left = curr->left;
        else
            parent->right = curr->left;
        free(curr);
        curr = NULL;
	}
	else {
		temp = curr->right;
		while (temp->left != NULL) {
			prev = temp;
			temp = temp->left;
		}
		prev->left = temp->right;
		temp->left = curr->left;
		temp->right = curr->right;
		if(parent->left == curr)
			parent->left = temp;
		else
			parent->right = temp;
		free(curr);
		curr = NULL;
	}		
}


int numNodes(treeNode *root) {
	if (root == NULL)
		return 0;
	return 1 + numNodes(root->left) + numNodes(root-right);
}

int numLeaves(treeNode *root) {
	if (root == NULL)
		return 0;
	if (root->left==NULL && root->right==NULL)
		return 1;
	return numLeaves(root->left) + numLeaves(root->right);
}

#define max(a, b) ((a)>(b) ? (a):(b))
int height(treeNode *root) {
	if (root == NULL)
		return 0;
	return 1 + max(height(root->left), height(root->right));
}

void preOrder(treeNode *root) {

	if (root == NULL)
		return;
	
	printf("%d\n", root->data);

	preOrder(root->left);

	preOrder(root->right);
}

void inOrder(treeNode *root) {

	if (root == NULL)
		return;

	inOrder(root->left);

	printf("%d\n", root->data);

	inOrder(root->right);
}

void postOrder(treeNode *root) {

	if (root == NULL)
		return;

	postOrder(root->left);

	postOrder(root->right);

	printf("%d\n", root->data);
}

