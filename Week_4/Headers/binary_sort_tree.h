//
// Created by eke_l on 2021/4/21.
//

#ifndef BINARYSORTTREE_BINARY_SORT_TREE_H
#define BINARYSORTTREE_BINARY_SORT_TREE_H

#define true 1
#define false 0
#define succeed 1
#define failed 0
//#define Status int

typedef int ElemType;

typedef struct Node{
    ElemType value;
    struct Node *left, *right;
}Node, *NodePtr;

typedef struct BinarySortTree{
    NodePtr root;
} BinarySortTree, *BinarySortTreePtr;

typedef struct Queue{
	Node *data[100];
	int front,rear;
}Queue; 

typedef struct Stack{
	Node *data[100];
	int base,top;
}Stack;

/**
 * BST initialize
 * @param BinarySortTreePtr BST
 * @return is complete
 */
int BST_init(BinarySortTreePtr T);

/**
 * BST insert
 * @param BinarySortTreePtr BST
 * @param ElemType value to insert
 * @return is successful
 */
int BST_insert(NodePtr *T, ElemType e);

/**
 * BST delete
 * @param BinarySortTreePtr BST
 * @param ElemType the value for Node which will be deleted
 * @return is successful
 */
int BST_delete(NodePtr *T, ElemType e);

/**
 * BST search
 * @param BinarySortTreePtr BST
 * @param ElemType the value to search
 * @return is exist
 */
int BST_search(NodePtr T, ElemType e);

/**
 * BST preorder traversal without recursion ∑«µ›πÈ«∞–Ú 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
int BST_preorderI(NodePtr T, void (*visit)(NodePtr));

/**
 * BST preorder traversal with recursion µ›πÈ«∞–Ú 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
int BST_preorderR(NodePtr T, void (*visit)(NodePtr));

/**
 * BST inorder traversal without recursion ∑«µ›πÈ÷––Ú 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
int BST_inorderI(NodePtr T, void (*visit)(NodePtr));

/**
 * BST inorder traversal with recursion µ›πÈ÷––Ú 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
int BST_inorderR(NodePtr T, void (*visit)(NodePtr));

/**
 * BST preorder traversal without recursion ∑«µ›πÈ∫Û–Ú 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
int BST_postorderI(NodePtr T, void (*visit)(NodePtr));

/**
 * BST postorder traversal with recursion µ›πÈ∫Û–Ú 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
int BST_postorderR(NodePtr T, void (*visit)(NodePtr));

/**
 * BST level order traversal ≤„¥Œ±È¿˙ 
 * @param BinarySortTreePtr BST
 * @param (*visit) callback
 * @return is successful
 */
int BST_levelOrder(NodePtr T, void (*visit)(NodePtr));
void output(NodePtr T);
#endif //BINARYSORTTREE_BINARY_SORT_TREE_H
