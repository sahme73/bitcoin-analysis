### Grade
Not Yet Competent (70%)

Must resubmit!

REGRADE: Sophisticated (100%) - 10% (Regrade Penalty)
### Comments

**Leading Question**
My initial concerns about your definition of 'relative trustworthiness' were answered in your algorithms section (simply finding the node with the highest user voted score is *not* interesting -- performing pagerank on the dataset is).

**Data** 
The dataset is well described. However there is a major flaw with your proposal in regards to the use / preprocessing of your dataset for the algorithms you propose. 

**Algorithm**
While Dijkstra's algorithm *can* be done in O(n lg n + m), it requires advanced data structures (a dynamic Fibonnaci min-heap) to do so. There are easier solutions with looser bounds as well. [Note this is not the 'flaw', just a warning.]

The larger issue with your algorithm is that your dataset is weighted with *negative* edge weights which can potentially break both Dijkstras and Pagerank. You should submit with additional details explaining how you can adjust your dataset to *not* contain negative weights. As part of this resubmission, I would encourage you to include the graph inputs needed for each algorithm (not just the function parameters like start and end node).

**Timeline**
Please note that data parsing is not the same as completing an algorithm and for full credit you must have one of your three proposed algorithms implemented by the mid-project checkin. You may want to adjust your time accordingly.
