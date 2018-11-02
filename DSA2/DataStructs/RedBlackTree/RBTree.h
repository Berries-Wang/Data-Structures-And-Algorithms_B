//
// Created by wei on 10/9/18.
//

#ifndef DSA2_RBTREE_H
#define DSA2_RBTREE_H


#include <stdbool.h>
#include <stdlib.h>

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

//颜色

typedef enum NodeColor Color;
typedef struct RBNode *Node;
typedef struct RBTree *RBTree;


enum NodeColor {
    RBT_RED = true, RBT_BLACK = false
};

struct RBNode {

    //节点的键
    K key;
    //节点的值
    V value;
    //节点的左孩子
    Node left;
    //节点的右孩子
    Node right;
    //节点的颜色
    Color color;

};

struct RBTree {

    //红黑树的根
    Node root;
    //红黑树节点数
    int size;

};

/**
 * 创建一个红黑树节点
 * @param key
 * @param val
 * @return
 */
static Node createNode_RBTree(K key, V val);

/**
 * 创建一棵红黑树
 * @return
 */
RBTree initRBTree(void);

/**
 * 红黑树节点总数
 * @param rbTree
 * @return
 */
int size_RB(RBTree rbTree);

/**
 * 红黑树是否为空
 * @param rbTree
 * @return
 */
bool isEmpty_RB(RBTree rbTree);


/**
 * 根据键查找值
 * @param rbTree
 * @param key
 * @return
 */
V get_RB(RBTree rbTree, K key);

/**
 * 在以node为根节点的红黑树中查找键为key的值
 * @param node
 * @param key
 * @return
 */
static V get_RB_static(Node node, K key);

//键的比较函数以及辅助函数
static int compare(K k1, K k2);

static int compareTo_Helper(K key1, K key2, int(*compare)(K, K));

static int compareTo(K key1, K key2);

/**
 * 红黑树中是否包含键为key的节点
 * @param rbTree
 * @param key
 * @return
 */
bool constains_RB(RBTree rbTree, K key);

/**
 * 以node为根节点的红黑树中是否包含键为key的节点
 * @param node
 * @param key
 * @return
 */
static bool contains_RB_static(Node node, K key);

/**
 * 设置红黑树中键为key的值
 * @param rbTree
 * @param key
 * @param val
 * @return 是否设置成功
 */
bool set_RB(RBTree rbTree, K key, V val);

/**
 * 设置以node为根节点的红黑树中的键为key的节点的值
 * @param node
 * @param key
 * @param val
 * @return 是否设置成功
 */
static bool set_RB_static(Node node, K key, V val);

/**
 * 向红黑树中插入节点
 * @param rbTree
 * @param key
 * @param val
 */
void addNode_RB(RBTree rbTree, K key, V val);

/**
 * 向以node为根节点的红黑树中插入节点
 * @param node
 * @param key
 * @param val
 * @return  插入节点后的新的红黑树的根
 */
static Node addNode_RB_static(RBTree  rbTree , Node node, K key, V val);

/**
 * 对node节点进行左旋传
 * @param node
 * @return  旋转后的红黑树的根
 */
static Node rotateWithLeft(Node node);

/**
 * 对node节点进行右旋转
 * @param node
 * @return  旋转后的红黑树的根
 */
static Node rotateWithRight(Node node);

/**
 * 判断节点是否为红节点
 * @param node
 * @return
 */
static bool isRed(Node node);

/**
 * 颜色翻转
 * @param node
 */
static void fliperColor(Node node);


#endif //DSA2_RBTREE_H
