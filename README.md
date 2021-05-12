# Graph data structure and its algorithms

![alt text](https://www.uniquesoftwaredev.com/wp-content/uploads/2019/12/directed_undirected.png)
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

### 8.Topological sort

    TC : O(N+E) SC: O(N) ASC: O(N)
Linear Ordering of vertices such that if there exists a directed edge between x and y then x will appear before y
It is only possible for DAGs
There can  be multiple TopoSort sol
![alt text](https://i.imgur.com/Q3MA6dZ.png)

    1. Run a loop for all the nodes. Carry a stack as well as visited list
    2. Traverse in a DFS way
    3. When a DFS call for 1 node is over, put the node in a stack
    4. Reverse the stack and that's one of your topo sort output

### 9. Kahn Algorithm for TopoSort (BFS)
    1. Calculate indegree of each node
    2. Store indegree 0 in a queue
    3. Traverse in BFS way and at each visit subtract the indegree by 1, as long as it doesn't reach 0 
    4. If the indegree of the node becomes 0, push it into the queue;
    5. The queue after the BFS traversal has one of Toposort orderings

### 10. Kahn Algorithm for Cycle Detection 
    1. Similar to Toposort 
    2. We maintain a counter variable to count the elements of queue while traversing
    3. If the counter is not equal to the number of nodes then a cycle must exist because of which TopoSort failed

### 11. Shortest Path in an Undirected graph from a node to all other nodes with unit weights
    1. Traverse in BFS way
    2. Maintain a list of distances and assign those values to inf
    3. For every adjacent node we are exploring, we check if the distance of that node is greater than the distance of the path we  came from + 1 and storing the less expensive value.
    4. Whenever step 3 becomes true we push the node in the queue.
    5. The list obtained at the last will be our shortest path to all nodes from the source node. 

### 12. Shortest Path in an DAG from source to other nodes
    1. Find the toposort and store it in a stack
    2. Pop out one by one and find if the node has been visited before 
    3. check if the distance of the adjacent node is less than prev.
    4. Keep updating the values for the distance list

### 13. Dijkstra's Algortithm
    TC = O(nlog2n)

    1.Maintain a min heap<{distance,node}>
    2.BFS traversal
    3.Initially marks every distance as inf and source vertex = 0
    4.Whenever we find a better distance push the node and dist in minHeap of that node and distance
    
