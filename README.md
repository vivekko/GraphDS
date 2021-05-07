# Graph data structure and its algorithms

## How do we store a graph in memory ? 
1. Adjacency Matrix: Can be used only for smaller numbers of nodes
2. Adjacency List: Can be used for larger values of nodes

If the graph is weighted, use pair class to store the weights 

## How de we traverse a graph ?
### 1. BFS  
    TC = O(N+E)
    SC = O(N+E) + O(N) + O(N)
#### Algorithm 
```rust
    1. Run a loop for connected components
    2. Check if the node has been visited
    2. Make a queue and store the first node in it, iff the node hasn't been visited
    3. Run a loop as long as queue is not empty and pop out the front node of queue and process it
    4. For that node run a loop to traverse the list for that node and push those nodes which aren't been visited
```
### 2. DFS
    TC = O(N+E)
    SC = O(N+E) + O(N) + O(N)
#### Algorithm
```py
    1. Run a loop for connected components
    2. Check if the node has been visited 
    3. Call a recursive dfs function and pass the first node, visited array, adjacency list and the processing list
    4. In the recursive dfs call mark the node as visited and process the node.
    5. Recursive call the dfs on the adjacency list if it's not been visited.
```
### 3. Detect a cycle in an undirected graph using BFS 
    TC = O(N+E) and SC = O(N+E) + O(N) + O(N)
#### Algorithm
```java
    1. Run a loop for connected components.
    2. Call the checking function.
    3. Modify the BFS queue by taking the parent elements of the node as well.
        <node,parent>
    4. Traverse in BFS way and check if the adjacent node has already been visited but is not the parent.
```

### 4. Detect a cycle in an undirected graph using DFS 
    TC = O(N+E) and SC = O(N+E) + O(N) + O(N)
#### Algorithm
```C++
    1. Run a loop for connected components.
    2. Call the checking function.
    3. Store parent and well as the child(anything) and keep calling it in DFS until one of the component returns true
    dfs(list,&cache,node,parent) 
```

### 5. Check if the graph is Bipartite or not using BFS (2 colourable)
    TC = O(N+E) and SC = (N + E) + O(N) + O(N)
#### Algorithm
```dart
    1. Run a loop for connected components 
    2. Instead of visted list, maintain a colour list, initially set to -1
    3. We use the concept of graph colouring in this algo
    4. Traverse in BFS way and intially colour the node to 1 and its adjancent to the opposite( 1 - 1)
    5. If at any point of the traversal we find that the parent node and its adjacent node has the same colour, we call off the search operation and return false  
```
### 6. Check if the graph is Bipartite or not using DFS (2 colourable) 
     TC = O(N+E) and SC = (N + E) + O(N) + O(N)
```kotlin
    1. Run a loop for connected components 
    2. Instead of visted list, maintain a colour list, initially set to -1
    3. We use the concept of graph colouring in this algo
    4. Traverse in DFS way and intially colour the node to 1 and its adjancent to the opposite( 1 - 1) and call DFS again
    5. If at any point of the traversal we find that the parent node and its adjacent node has the same colour, we call off the search operation and return false  
```

### 7. Detect cycle in a directed graph
```C
    1. Run a loop for connected components 
    2. Here we need two list to mark visited nodes, one to keep track of visited nodes and other to keep track of the dfs calls
    3. We use visited list to keep track of the places where we did not get any cycle and it becomes useless to go the same place searching for a cycle 
    4. We traverse in a DFS way similar to undirected graph but unmarking the dfsvisited list once we get out of the recursion call
    5. When dfsvisited graph finds a node which has been visited before then we got our cycle otherwise better luck in the next component.
```