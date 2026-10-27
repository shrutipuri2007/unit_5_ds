# unit_5_ds
represent electrical substations and possible transmission lines with construction costs and apply kruskals algorithm to determin the minimum spanning tree
Electrical Substation Network Using Kruskal's Algorithm

 Project Overview

This project represents electrical substations and possible transmission lines as a weighted graph. Each transmission line has a construction cost. Kruskal's Algorithm is used to determine the Minimum Spanning Tree (MST), which connects all substations with the minimum total construction cost without forming cycles.

 Aim

To implement Kruskal's Algorithm in C++ to find the minimum-cost transmission network connecting electrical substations.

 Objectives
- Represent electrical substations as vertices in a graph.
- Represent transmission lines as weighted edges.
- Assign construction costs to each transmission line.
- Apply Kruskal's Algorithm to find the Minimum Spanning Tree.
- Calculate the minimum total construction cost.

 Technologies Used
- Programming Language: C++
- Algorithm: Kruskal's Algorithm
- Data Structure: Weighted Graph
- Cycle Detection: Disjoint Set Union (DSU)

 Working Principle
1. Accept the number of electrical substations and possible transmission lines.
2. Read the source substation, destination substation, and construction cost for each line.
3. Sort all transmission lines in ascending order of construction cost.
4. Select the line with the lowest cost that does not form a cycle.
5. Repeat until all substations are connected or no more valid lines are available.
6. Display the selected transmission lines and the minimum total construction cost.

 Algorithm
1. Start.
2. Read the number of substations and transmission lines.
3. Store the transmission lines with their construction costs.
4. Sort the lines by increasing cost.
5. Initialize each substation as a separate set.
6. Select the cheapest line that connects two different sets.
7. Merge the sets to prevent cycles.
8. Continue until "V - 1" lines are selected, where "V" is the number of substations.
9. Display the selected lines and total cost.
10. Stop.

 Time Complexity
O(E log E)

Where- "E" = Number of possible transmission lines.
- "V" = Number of electrical substations.

 Applications
- Electrical power transmission network planning.
- Minimum-cost network design.
- Connecting substations efficiently.
- Infrastructure and utility network optimization.

 Conclusion
This project demonstrates how Kruskal's Algorithm can be used to design a minimum-cost electrical transmission network. It selects transmission lines efficiently while avoiding cycles and calculates the minimum total construction cost required to connect all substations, provided the network is connected.
