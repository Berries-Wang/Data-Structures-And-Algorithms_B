//
// Created by wei on 9/19/18.
//

#ifndef  DSA2_BST_H
#define  DSA2_BST_H

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

#define  VALUETYPE int
#define  NULLVALUE 0

#define  MALLOC(TYPE) ((TYPE *)malloc(sizeof(TYPE) * 1))
#define  FREE(node) (free(node))

#define  PRINTF(node) (printf("%-4d",node->value))

typedef struct Node Node;
typedef struct Node *pNode;
typedef struct BST *BST;

//二叉搜索树节点
struct Node {
    //值
    VALUETYPE value;
    //左孩子
    Node *left;
    //右孩子
    Node *right;

};

struct BST {
    //二叉搜索树根节点
    pNode root;
    //节点总数
    int size;
};

//获取树中节点总数
int size(BST);

//树是否为空
bool isEmpty(BST);

//插入元素
void add(BST, VALUETYPE);

/**
 * 递归的宏观语义：向以node为根的二叉搜索树中添加元素。
 *         返回插入了新节点的二叉搜索树的根
 *
 * 递归：将原问题，转换为更小的同一问题
 */
static pNode addNode(BST, pNode, VALUETYPE);

/**
 * 看二叉搜索树中是否包含指定元素
 * @return
 */
bool contains(BST, VALUETYPE);

/**
 * 看以node为根节点的二叉搜索树是否包含指定元素
 * @return
 */
static bool contains_static(pNode, VALUETYPE);

//元素大小比较。
static int compareTo(VALUETYPE, VALUETYPE);

//前序遍历二叉搜索树
void preOrder(BST);

//前序遍历 以node为根节点的二叉搜索树
static void preOrder_static(pNode);

//中序遍历二叉搜索树
void inOrder(BST);

//中序遍历以node为根节点的二叉搜索树
static void inOrder_static(pNode);

//后序遍历二叉搜索树
void postOrder(BST);

//后序遍历以node为根节点的二叉搜索树
static void postOrder_static(pNode);

//层序遍历
void levelOrder(BST);

//寻找搜索二叉树中最小值
pNode minimum(BST);

//宏观语义:寻找以nodeeric根节点的 二叉搜索树中最小的元素
static pNode minimum_static(pNode);

//寻找二叉搜索树中最大值
pNode maximum(BST);

//宏观语义:寻找以nodeeric根节点的 二叉搜索树中最小的元素
static pNode maximum_static(pNode);

//删除最小值
VALUETYPE removeMin(BST);

//删除以node为根节点的二叉搜索树中最小的节点。返回删除了最小节点之后的最小二叉搜索树
static pNode removeMin_static(pNode);

//删除最小值
VALUETYPE removeMax(BST);

//删除以node为根节点的二叉搜索树中最小的节点。返回删除了最小节点之后的最小二叉搜索树
static pNode removeMax_static(pNode);

//删除任意节点
void removeNode(BST, VALUETYPE);

/**
 * 宏观语义：删除以node为根节点的二叉搜索树中值为val的节点，
 * 返回删除了节点的树的根
 */
static pNode removeNode_static(BST, pNode, VALUETYPE);


#endif  //DSA2_BST_H

