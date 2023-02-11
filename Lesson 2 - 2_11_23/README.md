<center>

# **HKOI Lesson 2 - Data Structures**

</center>

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

### [**Problem 01019**](01019.cpp)

<br>
<br>

## **Binary Search Tree (BST)**
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

### **Time Complexity**

- Usually O(log N)
- in the worst case, tree is a chain --> time complexity = O(N)
    - if there are Q operations, O(QN Is very slow)

*To avoid this, we can either -->*
- shuffle the elements before insertion
- use self balancing BST
    - similar to the normal BST but it maintains it height close to O(log N)
    - BUT very hard to code
- use other search trees


### **In C++**

- set and mao are implemented by red-black tree
- however raanking operations are not supported
- what is supported:
    - insert
    - delete
    - query
    - extrema
    - lower_bound
    - exact value

both map and set does not support duplicate keys - use multiset / multimap instead

`std::lower_bound` != `set::lower_bound` / `map::lower_bound`

<br>

### [**Problem M0811**](M0811.cpp)

<br>
<br>

## **Hash Table**

### **What is it?**

- an array that supports the following
    - insertion O(1)
    - CHECK SLIDES

### **Hash function**

- hash function is a function that takes an element and maps to an integer which the integer is used as the arr index
- given a wide range of integers[0, 10^9], we want to fit them in an arr (CHECK SLIDES)
- **based on modulo**
- if two values are assigned to the same cell:
    - use a vector array - open hashing
    - store them both in cell 7

#### **Handling Collision:**

- closed hashing
    - linear probing <-- vector array
    - quadratic probing <-- (research more)
    - double hashing <-- hash twice
- rehashing

#### **A Good Hash Function**

- Goal: avoid collision - distrivute the elements evenly in the hash table
    - bigger hash table
    - prime number modulo
- just use the stl hash table

#### **Rolling Hash**

How do we hash a string (suppose string is lowercase)
- first map the character to a integer, e.g. a = 1, b = 2, etc.
- choose a prime modulus M
    - commonly use 10^9 + 7, but any large prime should work
- the hash value of any string can be computed by 
    - `S[0] + S[1] * 27 + S[2] + 27^2 + ... + S[N-1] * 27^[N-1] % M`
- can adjust based off of input constraints

#### **Time complexity**

- suppose we have a good hash function, can distribute n elements evenly
- O(1) for all insertion

### **In C++**

- `unordered_map` / `unordered_set` in c++ use hash table
- supports insert, delete, query, in O(1)

> `unordered_map`:
> - stores element in a key-value combination
> - keys are unordered
> - no duplicate keys - use `unordered_multimap` instead

> `unordered_set`:
> - keys are hashed into indicies of hash table
> - keys are unordered
> - only unique keys are allowed - use `unordered_multset` instead

<br>
<br>

## **Disjoint-set union-find (DSU) *CHECK SLIDES***

### [**Good Article about Disjoint Sets + Union and Find**](https://medium.com/@harshits337/disjoint-set-unions-by-rank-and-path-compression-3a7b3946f550)

<br>

### **What is it?**
Tracks elements partitioned into a number of disjointed sets
- one element belongs to exactly one group
- one group may consist of any number of elements

#### **Operations**

- Union - merge two groups
    - elements from two groups now belong to the same group
- Find - find the group an element belongs to (ususally represents a group ID)
    - check if two elements belong to the same group
        - Let (1) be group 1, (2,3) be group 2, and (4,5,6) to be group 3
        - Find(2) = 2
        - Find(3) = 2
        - Find(4) = 3

### **Representation**

> (1) Maintain an array `p[i]` which represents the group ID of element `i`

> (2) Use tree structure to represent the groups, the group ID is the root of each tree, using an array `p[i]` to represent the parent of the element i

### [**Problem N1511**](N1511.cpp)

<br>
<br>

## **Heaps (CHECK SLIDES)**