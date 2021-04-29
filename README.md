# GraphDS

## How do we store a graph in memory ? 
1. Adjacency Matrix: Can be used only for smaller numbers of nodes
2. Adjacency List: Can be used for larger values of nodes

If the graph is weighted, use pair class to store the weights 

## How de we traverse a graph ?
1. BFS  
    TC = O(N+E)
    SC = O(N+E) + O(N) + O(N)
    ### Algorithm 
    1. Run a loop for connected components
    2. Make a queue and store the first node in it, iff the node hasn't been visited
    3. Run a loop as long as queue is not empty and pop out the front node of queue and process it
    4. For that node run a loop to traverse the list for that node and push those nodes which aren't been visited
    
2. DFS


