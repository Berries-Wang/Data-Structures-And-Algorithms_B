//
// Created by wei on 10/8/18.
//

#ifndef DSA2_AVLTREE_H
#define DSA2_AVLTREE_H

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

//申请空间
#define  MALLOC(TYPE, COUNT) ((TYPE*)malloc(sizeof(TYPE)*COUNT))
//释放空间
#define  FREE(ADDR_HEAD) (free(ADDR_HEAD))

//打印键
#define  PRINTFKEY(value) (printf("%s    ",value))

//Max
#define  MAX(VAL1, VAL2) (VAL1 > VAL2 ? VAL1:VAL2)

//键的类型
#define  K  char*
//值的类型
#define  V  int
//无效的值
#define  INVALIDVALUE 0


typedef struct Node *Node;
typedef struct AVLTree *AVLTree;


/**
 * 树的节点
 */
struct Node {

    //键
    K key;
    //值
    V value;
    //左孩子
    Node left;
    //右孩子
    Node right;
    //节点的高度
    int height;

};


/**
 * 平衡二叉树
 */
struct AVLTree {

    //AVLTree的根节点
    Node root;
    //AVLTree的节点个数
    int size;

};

/**
 * 初始化AVLTree (平衡二叉树)
 * @return 
 */
AVLTree initAVLTree(void);

/**
 * 创建节点
 * @param key  键
 * @param value 值
 * @return  指向新创键的节点的指针
 */
static Node createNode_AVLTree_static(K key, V value);

/**
 * 获取节点的高度
 * @param node
 * @return
 */
static int getHeight_AVLTree_static(Node node);

/**
 * huoquu指定节点的平衡因子
 * @param node
 * @return
 */
int getBalanceFactro_AVLTree(Node node);

//获取树中节点总数
int size(AVLTree avlTree);

//树是否为空
bool isEmpty(AVLTree avlTree);

//插入元素
//当键已经存在了， 那么就修改值
void add_AVLTree(AVLTree avlTree, K key, V value);

/**
 * 递归的宏观语义：向以node为根的平衡二叉树中添加元素。
 *         返回插入了新节点的平衡二叉树的根
 *
 * 递归：将原问题，转换为更小的同一问题
 */
static Node add_Node_AVLTree_static(AVLTree avlTree, Node node, K key, V value);

/**
 * 对以根节点为node的二叉搜索树进行右单旋转
 * @param node
 * @return  返回旋转后的AVL树的根
 */
static Node sigleRotateWithRight(Node node);

/**
 * 对以根节点为node的二叉搜索树进行左单旋转
 * @param node
 * @return   返回旋转后的AVL树的根
 */
static Node sigleRotateWithLeft(Node node);

/**
 * 对平衡二叉树进行中序遍历
 * @param avlTree
 */
void inOrder_AVLTree(AVLTree avlTree);

/**
 * 中序遍历辅助函数
 * 对以node为根节点的平衡二叉树进行中序遍历
 * @param node
 */
static void inOrder_AVLTree_static(Node node);

/**
 * 前序遍历
 * @param avlTree
 */
void preOrder__AVLTree(AVLTree avlTree);

/**
 * 前序遍历辅助函数
 * 对以node为根节点的平衡二叉树进行前序遍历
 * @param node
 */
static void preOrder_AVLTree_static(Node node);

/**
 * 后序遍历
 * @param avlTree
 */
void postOrder_AVLTree(AVLTree avlTree);

/**
 * 后序遍历辅助函数
 * 对以node为根节点的平衡二叉树进行后序遍历
 * @param node
 */
static void postOrder_AVLTree_static(Node node);

/**
 * 查看平衡二叉树是否包含键为key的元素
 * @param avlTree
 * @param key
 * @return
 */
bool contains_AVLTree(AVLTree avlTree, K key);

/**
 * 查询以node为根节点的平衡二叉树是否包含键为key的元素
 * @param avlTree
 * @param key
 * @return
 */
static bool contains_AVLTree_static(Node node, K key);

/**
 * 查找平衡二叉树中最小的节点
 * @param avlTree
 * @return
 */
Node minimum_AVLTree(AVLTree avlTree);

/**
 * 从以node为根节点的平衡二叉树中找到最小的节点。
 * @param node
 * @return
 */
static Node minimum_AVLTree_static(Node node);

/**
 * 查找平衡二叉树中最大值
 * @param avlTree
 * @return
 */
Node maximum_AVLTree(AVLTree avlTree);

/**
 * 从以node为根节点的平衡二叉树中找到最大值
 * @param node
 * @return
 */
static Node maximum_AVLTree_static(Node node);

/**
 * 从平衡二叉树获取键为key的节点的值(Value)
 * @param avlTree
 * @param key
 * @return
 */
V get_AVLTree(AVLTree avlTree, K key);

/**
 * 从以node为根节点的平衡二叉树获取键为key的节点的值(Value)
 * @param node
 * @param key
 * @return
 */
static V get_AVLTree_static(Node node, K key);


/**
 * 设置平衡二叉树中键为key的节点的值(Value)
 * @param avlTree
 * @param key
 * @param val
 */
void set_AVLTree(AVLTree avlTree, K key, V val);

/**
 * 设置以node为根节点的平衡二叉树中键为key的节点的值(Value)
 * @param node
 * @param key
 * @param val
 */
static void set_AVLTree_static(Node node, K key, V val);

/**
 * 从平衡二叉树中删除掉键为key的元素
 * @param avlTree
 * @param key
 * @return
 */
void remove_AVLTree(AVLTree avlTree, K key);

/**
 * 从以node为根节点的的平衡二叉树中删除键为key的节点,返回删除完对应节点后的树的根
 * @param node
 * @param key
 * @return
 */
static Node remove_AVLTree_static(AVLTree avlTree, Node node, K key);

//键的比较函数以及辅助函数
static int compare(K k1, K k2);

static int compareTo_Helper(K key1, K key2, int(*compare)(K, K));

static int compareTo(K key1, K key2);

#endif //DSA2_AVLTREE_H
