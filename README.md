# Graph data structure and its algorithms

## How do we store a graph in memory ? 
1. Adjacency Matrix: Can be used only for smaller numbers of nodes
2. Adjacency List: Can be used for larger values of nodes

If the graph is weighted, use pair class to store the weights 

## How de we traverse a graph ?
### 1. BFS  
    TC = O(N+E)
    SC = O(N+E) + O(N) + O(N)
### Algorithm 
    1. Run a loop for connected components
    2. Check if the node has been visited
    2. Make a queue and store the first node in it, iff the node hasn't been visited
    3. Run a loop as long as queue is not empty and pop out the front node of queue and process it
    4. For that node run a loop to traverse the list for that node and push those nodes which aren't been visited

### 2. DFS
    TC = O(N+E)
    SC = O(N+E) + O(N) + O(N)
### Algorithm
    1. Run a loop for connected components
    2. Check if the node has been visited 
    3. Call a recursive dfs function and pass the first node, visited array, adjacency list and the processing list
    4. In the recursive dfs call mark the node as visited and process the node.
    5. Recursive call the dfs on the adjacency list if it's not been visited.
### Detect a cycle in an undirected graph using BFS 
    TC = O(N+E) and SC = O(N+E) + O(N) + O(N)
### Algorithm
    1. Run a loop for connected components.
    2. Call the checking function.
    3. Modify the BFS queue by taking the parent elements of the node as well.
        <node,parent>
    4. Traverse in BFS way and check if the adjacent node has already been visited but is not the parent.


### Detect a cycle in an undirected graph using DFS 
    TC = O(N+E) and SC = O(N+E) + O(N) + O(N)
### Algorithm
    1. Run a loop for connected components.
    2. Call the checking function.
    3. Store parent and well as the child(anything) and keep calling it in DFS until one of the component returns true
```C++
    dfs(list,&cache,node,parent) 
```