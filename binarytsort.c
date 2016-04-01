/************************************************************
 * BINARY-T SORTING ALGORITHM                               *
 * Sort an array by creating a binary tree for the array.   *
 *                                                          *
 * © 2016 by Eddie Dinkz (codemaster.eddie@gmail.com)       *
 ************************************************************/

#include "bintsort.h"

void bintsort(int *a, int sz, int verbose)
{
    TreeNode *root = NULL;
    root = ComposeTree(a, sz, verbose);
    DecomposeTree(a, root);
    // DEBUG _printtree_(root);
    // DEBUG printf("~\n");
}

TreeNode *ComposeTree(int *a, int sz, int vrb)
{
    int i;
    TreeNode *root = NULL;
    for (i = 0; i < sz; i++)
        root = InstallTreeNode(a[i], root, vrb);

    return root;
}


TreeNode *InstallTreeNode(int key, TreeNode *tnode, int vrb)
{
    int cond;

    if (tnode == NULL) {  // 'key' is not in the tree,
        if (vrb) printf("new Key : allocating mem and placing key(%d)\n", key);
        tnode = (TreeNode *) malloc(sizeof (TreeNode)); // allocate memory for the new tree node (new key)
        tnode->key = key; // install the key
        tnode->count = 1; // initialize the count to 1
        tnode->left = tnode->right = NULL; // new key is a leaf of the tree
    } else if ((cond = key - tnode->key) < 0) {
        if (vrb) printf("key(%d) < tnode->key(%d) eval( InstallTreeNode(key, tnode->left); )\n", key, tnode->key);
        tnode->left = InstallTreeNode(key, tnode->left, vrb);
    } else if (cond == 0) {
        if (vrb) printf("key(%d) = tnode->key(%d) eval( tnode->count++; )\n", key, tnode->key);
        tnode->count++;
    } else {
        if (vrb) printf("key(%d) > tnode->key(%d) eval( InstallTreeNode(key, tnode->right); )\n", key, tnode->key);
        tnode->right = InstallTreeNode(key, tnode->right, vrb);
    }

    return tnode;

}

static int index = 0; // only for DecomposeTree()
void DecomposeTree(int *a, TreeNode *tnode)
{
    if (tnode != NULL) {
        DecomposeTree(a, tnode->left);

        int p = 0;
        while (p < tnode->count) {
            p++;
            a[index++] = tnode->key;
        }

        DecomposeTree(a, tnode->right);
    }
}

// debugger function.
void _printtree_(TreeNode *p)
{
    if (p != NULL) {
        _printtree_(p->left);

        printf("%d", p->key);
        if (p->count > 1)
            printf("(%d) ", p->count);
        else
            printf(" ");

        _printtree_(p->right);
    }
}

