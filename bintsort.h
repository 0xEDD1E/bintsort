//
// Created by 0xEDD1E on 2016-03-30.
//

#ifndef BINARYTSORT_BINTSORT_H
#define BINARYTSORT_BINTSORT_H

#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int key;
    int count;
    struct treenode *left;
    struct treenode *right;
} TreeNode;

void bintsort(int *, int, int);
TreeNode *ComposeTree(int *, int, int);
TreeNode *InstallTreeNode(int, TreeNode *, int);
TreeNode *treealloc();
void DecomposeTree(int *, TreeNode *);
void _printtree_(TreeNode *);

#endif //BINARYTSORT_BINTSORT_H
