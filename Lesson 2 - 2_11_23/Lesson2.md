# **HKOI Lesson 2 - Data Structures**

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

**Insertion** in a binary heap inserts a node at the next available slot, and then checks values with the parent node to see if a swap is neccessary

> Time complexity is O(log N)

<br>

**Query** of the min/max element is always O(1) because it is the root node

<br>

**Deleting** the minimum node requires you to:

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