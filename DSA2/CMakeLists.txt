cmake_minimum_required(VERSION 3.12)
project(DSA2)

set(CMAKE_CXX_STANDARD 14)
#set(CMAKE_C_FLAGS_DEBUG)

#BST
#add_executable(DSA2 DataStructs/BinarySearchTree/BST.h DataStructs/BinarySearchTree/BST.c DataStructs/BinarySearchTree/main.c LeetCode/3. Longest Substring Without Repeating Characters/SolutionOne.cpp)

#Array
#add_executable(DSA2 DataStructs/Array/Array.h DataStructs/Array/Array.c DataStructs/Array/main.c LeetCode/5. Longest Palindromic Substring/Solution.cpp)

#Stack
#add_executable(DSA2 DataStructs/Array/Array.h DataStructs/Array/Array.c DataStructs/Stack/Stack.h DataStructs/Stack/Stack.c DataStructs/Stack/main.c)

#Queue
#add_executable(DSA2 DataStructs/Queue/LoopQueue.h DataStructs/Queue/LoopQueue.c DataStructs/Queue/main.c)

#LinkedList
#add_executable(DSA2 DataStructs/LinkedList/LinkedList.h DataStructs/LinkedList/LinkedList.c DataStructs/LinkedList/main.c )

#  BSTSet
#add_executable(DSA2 DataStructs/BinarySearchTree/BST.h DataStructs/BinarySearchTree/BST.c DataStructs/Set/BSTSet/BSTSet.h DataStructs/Set/BSTSet/BSTSet.c DataStructs/Set/BSTSet/main.c)

#  BSTMap
#add_executable(DSA2 DataStructs/Map/BSTMap/BST.h DataStructs/Map/BSTMap/BST.c DataStructs/Map/BSTMap/BSTMap.h DataStructs/Map/BSTMap/BSTMap.c DataStructs/Map/BSTMap/main.c )

#  MaxHeap
#add_executable(DSA2 DataStructs/UnionFind/UnionFind.h DataStructs/UnionFind/UnionFind.c DataStructs/UnionFind/main.c)

#  UnionFind
#add_executable(DSA2 DataStructs/Array/Array.h DataStructs/Array/Array.c DataStructs/Heap/MaxHeap/MaxHeap.h DataStructs/Heap/MaxHeap/MaxHeap.c DataStructs/Heap/MaxHeap/main.c)

#AVLTree
#add_executable(DSA2 DataStructs/AVLTree/AVLTree.h DataStructs/AVLTree/AVLTree.c "DataStructs/AVLTree/main.c")

#AVLTreeMap
#add_executable(DSA2 DataStructs/Map/AVLTreeMap/AVLTree.h DataStructs/Map/AVLTreeMap/AVLTree.c DataStructs/Map/AVLTreeMap/AVLTreeMap.h DataStructs/Map/AVLTreeMap/AVLTreeMap.c DataStructs/Map/AVLTreeMap/main.c)

#AVLTreeSet
#add_executable(DSA2 DataStructs/Set/AVLTreeSet/AVLTree.h DataStructs/Set/AVLTreeSet/AVLTree.c DataStructs/Set/AVLTreeSet/AVLTreeSet.h DataStructs/Set/AVLTreeSet/AVLTreeSet.c DataStructs/Set/AVLTreeSet/main.c DataStructs/RedBlackTree/RBTree.h DataStructs/RedBlackTree/RBTree.c)

#RBTree
#add_executable(DSA2 DataStructs/RedBlackTree/RBTree.h DataStructs/RedBlackTree/RBTree.c DataStructs/RedBlackTree/main.c)

#-------------------------LeetCode---------------------------------------------
#LeetCode Two
#add_executable(DSA2 LeetCode/2. Add Two Numbers/Solution3.cpp)

#LeetCode Three
#add_executable(DSA2 LeetCode/3. Longest Substring Without Repeating Characters/SolutionOne.cpp LeetCode/4. Median of Two Sorted Arrays.cpp)

#LeetCode 4. Median of Two Sorted Arrays
#add_executable(DSA2 LeetCode/4. Median of Two Sorted Arrays/4. Median of Two Sorted Arrays.cpp)

#LeetCode 5. Longest Palindromic Substring
#add_executable(DSA2  LeetCode/5. Longest Palindromic Substring/SolutionU.cpp LeetCode/6. ZigZag Conversion/Solution.cpp)

#LeetCode 6. ZigZag Conversion
##add_executable(DSA2 LeetCode/6. ZigZag Conversion/Solution.cpp DataStructs/Queue/Queue.h DataStructs/Queue/Queue.c)

#LeetCode 7. Reverse Integer
#add_executable(DSA2 "LeetCode/7. Reverse Integer/Solution.cpp" "LeetCode/9. Palindrome Number/Solution.cpp")

#LeetCode 203. Remove Linked List Elements
#add_executable(DSA2 "LeetCode/203. Remove Linked List Elements/Solution.cpp" "LeetCode/8. String to Integer (atoi)/Solution.cpp")


#LeetCode 8. String to Integer (atoi)
#add_executable(DSA2 "LeetCode/8. String to Integer (atoi)/Solution.cpp")

#LeetCode 9. Palindrome Number
#add_executable(DSA2 "LeetCode/9. Palindrome Number/Solution.cpp")

#LeetCode 10. Regular Expression Matching
#add_executable(DSA2 "LeetCode/10. Regular Expression Matching/Solution.cpp" )

#11. Container With Most Water
#add_executable(DSA2 "LeetCode/11. Container With Most Water/Solution2C.c" Algorithm/SortingAlgorithm/SortAlgorithmHelper.h)


#LeetCode 12. Integer to Roman
#add_executable(DSA2 "LeetCode/12. Integer to Roman/Solution.cpp")

#LeetCode 14. Longest Common Prefix
#add_executable(DSA2  "LeetCode/14. Longest Common Prefix/Solution2.cpp")
#16. 3Sum Closest
#add_executable(DSA2 "LeetCode/16. 3Sum Closest/Solution.cpp" "LeetCode/18. 4Sum/Solution.cpp")
#18. 4Sum
add_executable(DSA2 "LeetCode/18. 4Sum/Solution2.cpp")

#--------------------------------Algorithm----------------------------
#sortalgorithm
#add_executable(DSA2 Algorithm/SortingAlgorithm/SortAlgorithmHelper.h Algorithm/SortingAlgorithm/SortAlgorithm.h Algorithm/SortingAlgorithm/main.cpp)

#senior TEST
#add_executable(DSA2 Senior/TEST/test.c)