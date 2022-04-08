# Final Project Proposal
 **Team Members:**
---
 - Safeer Ahmed (sahme73)
 - Thomas Alakkatt (talakk2)
 - Matt Casper (mcasper3)
 - James Lu (jameslu2)

---

# Final Project Proposal
**Leading Question:** 
The goal of this project is to analyze trading taking place between bitcoin accounts with the key feature being to determine which accounts seem to be most suspect for fraudulent behavior based on trading patterns in the dataset. Simply put, our goal is to assess relative trustworthiness of different bitcoin users and identify the most and least trustworthy ones using a page-rank algorithm.

**Dataset Acquisition and Processing:** 
The public dataset we will be utilizing for this project is from a platform called Bitcoin Alpha. The dataset is available via the following link: http://snap.stanford.edu/data/soc-sign-bitcoin-alpha.html. 

**Data Format:** 
The dataset includes approximately 24,000 entries that track the transactions between bitcoin trades among users of the Bitcoin Alpha platform. Each entry includes four parameters: the source account’s identifier, the target account’s identifier, the rating of the trade with the target account, and the time at which the trade took place. We are given the information that there are a total of 3,783 nodes and 24,186 edges in the directed graph formed by the entire dataset which is downloadable in a .csv format. This indicates that there are a total of 3,783 unique account identifiers on the platform and over 24,000 total trades taking place that need to be accounted for. It should be noted that the rating scale makes the overall graph network a trust weighted network that is signed/verified by the time of the trade. A -10 rating is the lowest rating possible in a trade and +10 is the highest rating. 

Since not all users of the platform are required to trade with each other, it is highly possible that the overall graph of all the nodes in the network is disconnected. Our goal is to analyze each individual network of trades to find fraudulent patterns, because looking at the entire network of possibly disconnected graphs/trades would not be as useful as hyper-focusing on each connected graph component. Essentially, we will be utilizing all four of the parameters of the dataset and all the data provided; however, we will create subsets based on each connected graph component, rather than the broad graph formed by the entire dataset. This would allow for more sensible traversals and application within our algorithms.

**Data Correction:** While reading the data in and setting it up for use, we will check what we have already stored for a duplicate entry. A duplicate entry is one which takes place between the same two users in the same direction. If it has the same trustworthiness rating, we will simply ignore it. If it has a different one, we will take the integer average of the two values. We will also check if any data is missing. If any pieces of information from a transaction are missing, they cannot be useful for our purpose and will be ignored. To avoid problems in our algorithms caused by negative numbers and zeros, we will add 11 to every rating, adjusting the range of ratings from [-10,10] to [1,21] for internal use.

**Data Storage:** In order to store our data, we will have vectors storing the nodes and edge objects and all relevant data within them. We will utilize an adjacency matrix to store the connections within the graph. The adjacency matrix will store pointers or indexes to refer to the actual edge they are referencing in constant time.

**DFS:**
A Depth First search method of traversing the graph would be more useful to answer our leading question.  Following chains of trades may be useful to identify paths of fraudulent or suspicious activity with a network or connected component. Since it is highly likely that this graph is unconnected, the user will specify a trader of interest and that will be the starting location of the depth first search traversal. 

Function Inputs: An integer that is the identifier of the trader the user would like to begin the traversal at. This will also require our adjacency matrix.

Function Outputs: A vector storing all of the nodes (users) visited. We will print this information to the screen as a sequence of numbers.

Function Efficiency: The depth-first search traversal will be O(n) in both time and memory where n is the number of users. 

**Dijkstra’s Algorithm:**
Dijkstra’s algorithm is a way where we could determine the shortest paths between two nodes in a graph. In order to detect suspicious activity and monitor transactions within a network, using this algorithm could give us a perfect view on the relationships between each transaction and each buyer. By finding the shortest paths between two traders, we would be able to analyze the direct relationships in the trade in order to calculate how suspicious the actions are. 

Function Inputs: The start and end traders of interest (as integer identifiers). We will need our adjacency matrix and our vector of edges to access rating weights.

Function Outputs: A vector storing all nodes (users) on the shortest path between the nodes, or an empty vector if it does not exist. We will also print this information to the screen as a list of numbers.

Function Efficiency: Dijkstra’s Algorithm has a running time of O(n lg n + m) where m is the number of edges and n is the number of vertices in the graph if we use a Fibonnaci heap. We will not be using one, and will strive for a runtime of O(n^2 lg n). Its memory usage is O(n^2).

**PageRank Algorithm:**
To determine the relative trustworthiness of each user, we will use a variation of the page rank algorithm where instead of simply counting inward connections, we will evaluate their rankings from other users, perhaps against the ratings the rater usually gives (therefore a 10 from a user who frequently gives them is worth less than a 10 from a user who rarely gives them). The goal will be to establish which traders in the network are the most trustworthy and which are the least trustworthy. This will answer our leading question by determining who can and cannot be trusted within the network.

Function inputs: A desired trader, or nothing to get a list of all traders. We will need to use the vector of nodes, edges and the adjacency matrix.

Function outputs: A vector containing each trader’s identifier and their score. We will also try to print this information in a way that is visually pleasing and easy to read, perhaps just the top and bottom 10.

Function Efficiency: The PageRank algorithm can run in O(n+m) time where n is the number of nodes and m is the number of edges. It will require O(n) memory. 

**Timeline:** Once this is accepted, we will spend the weekend setting up the graph in memory. We will spend part of the weekend and next week writing and testing our traversal so it is done by the mid project check in. We will try to finish and test the other two algorithms in the following weeks, and prepare all presentation materials shortly before the start of week 15.
