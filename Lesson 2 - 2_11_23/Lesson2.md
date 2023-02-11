# **HKOI Lesson 2 - Data Structures**

<br>

## **Common Types of operations**

- insertion
- detection
- modification
- query
    - min/max
    - find a specific value
<br>
<br>
<br>

## **Binary Heap**

### **What is it?**

Binary Heap is a complete binary tree

> A complete binary tree is a perfect binary tree with some rightmost node removed on the last level

<br>

Heap supports query and deletion of min/max element

In a min heap, each element is not less than its parent element
- min element is stored in the root
- maintains this property during insertion and deletion

<br>

### **Insertion** 

A binary heap inserts a node at the next available slot, and then checks values with the parent node to see if a swap is neccessary

> Time complexity is O(log N)

<br>

### **Query** 

min/max element is always O(1) because it is the root node

<br>

### **Deleting** 

Deleting the minimum node requires you to:

1. Swap the minimum and the last node
2. Delete the last node
3. Sift-down the root to maintain the property of the heap, such that each element >= parent
    - Swap with the lesser of the two child nodes

<br>

### **Array Representation**

In a 0-indexed array:

- root of heap --> `arr[0]`
- parent of node `arr[k]` --> `arr[(k-1) / 2]`
- Left children of node `arr[k`] --> `arr[k * 2]`
- Right children of node `arr[k]` --> `arr[k * 2 + 1]`
- Last node in the heap --> `arr[N - 1]`
- Next node inserted --> `arr[N]`

<br>

### **In C++**

`<priority_queue>` supports all 3 operations

declare `priority_queue<type, container type, compare parameter> `

> `container type` = `vector<int>`

> `compare parameter` = `std::less()` or nothing for max heap and `std::greater()` for min heap

<br>
<br>
<br>

## **Binary Search Tree**
> - insertion O(log N)
> - deletion O(log N)
> - query O(log N)
> - modification O(log N)

### **Structure**

- a directed binary tree (each node has 0 - 2 children)
- each node stores an element
- value of all nodes in the left subtree of node k < value of node k
- value of all nodes in the right subtree of node k >= value of node k

### **Insertion**

- DFS from root
- repeatedly travel down the tree 
    - if the inserted value < the current value's node --> go left
    - if the inserted value >= the current value's node --> go right

### **Query**
- Find if a number exists
- Find range
- Find min/max element

How to do it:
- DFS From root
- repeatedly travel down the tree
    - same logic as insertion
- until the value is found

**To find the maximum value**, just keep going right

**To find the minimum value**, just keep going left

**To find the lower bound**
> The lower bound = the smallest element  >  `N`

- Continue going right until a number > `N`
- Then, keep going left until a number <= `N`

### **Deletion**

- locate the to-be-deleted element
- depends on the location of the node:
    - if it is a leaf node, delete directly
    - if it has a left subtree, swap it with the largest element in its left subtree
    - if it has a right subtree, swap it with the smallest element in its right subtree
- Do the previous recursively until the to-be deleted node is a leaf and delete it directly