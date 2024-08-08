/* C program to illustrate the kruskal algorithm */

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int src;
    int dst;
    int wgt;
}edge;

void sort(edge g[], int N)
/**
 * Sorts an array of edges in non-decreasing order based on their weights using bubble sort.
 * 
 * @param g The array of edges to be sorted
 * @param N The number of edges in the array
 */
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < (N - i - 1); j++)
        {
            if(g[j].wgt > g[j + 1].wgt)
            {
                edge temp = g[j];
                g[j] = g[j + 1];
                g[j + 1] = temp;
            }
        }
    }

    // print the sorted sequence of edges
    for(int i = 0; i < N; i++)
    {
        printf("{source : %d, destination : %d, weight : %d}\n", g[i].src, g[i].dst, g[i].wgt);
    }
}

int check_cycle(edge g[], edge ed, int N)
/**
 * Check if adding an edge creates a cycle in the graph.
 * 
 * @param g The array of edges representing the graph
 * @param ed The edge to be checked for cycle
 * @param N The number of edges in the graph
 * @return 1 if adding the edge creates a cycle, 0 otherwise
 */
{
    int flag = 1;
    for(int i = 0; i < N; i++)
    {
        if(ed.dst == g[i].src)
        {
            flag = 0;
            return flag;
        }

    }

    return flag;
}

void kruskal(edge g[], int N)
/**
 * Perform Kruskal's algorithm to find the Minimum Spanning Tree (MST) of a graph.
 * 
 * @param g The array of edges representing the graph
 * @param N The number of edges in the graph
 */
{
    edge out[20];
    int idx = 0;

    // iterate across the input graph list. Append the first edge
    for(int i = 0; i < N; i++)
    {
        if(i == 0 | i == 1)
        {
            out[idx] = g[i];
            idx++;
        }

        // for any other index apart from 0 and 1, check if a cycle is formed
        // If cycle is not formed, append to the output list. Else, discard the edge
        else
        {
            int flag = check_cycle(out, g[i], idx);

            // If upon inserting the new node, the graph does not form a cycle -> insert the node
            if(flag == 1)
            {
                out[idx] = g[i];
                idx++;
            }

            // If upon inserting the new node, the graph does form a cycle -> insert the node
            else if(flag == 0)
            {
                continue;
            }
        }
    }

    // print out the MST
    printf("Kruskal MST\n");
    for(int i = 0; i < idx; i++)
    {
        printf("{source : %d, destination : %d, weight : %d}\n", out[i].src, out[i].dst, out[i].wgt);
    }
}

void main()
/**
 * Main function to input edge data from the user, sort the edges in ascending order of weight, and find the Minimum Spanning Tree (MST) using Kruskal's algorithm.
 * Prompts the user to enter the number of edges and details for each edge (source node, destination node, and weight).
 * Calls the 'sort' function to arrange the edges in ascending order of weight.
 * Calls the 'kruskal' function to perform Kruskal's algorithm on the sorted edges to find the MST.
 */
{
    int N = 0;
    int source = 0;
    int destination = 0;
    int weight = 0;

    printf("Enter the number of edges :");
    scanf("%d", &N);

    edge G[20];

    // input edge data from the user
    for(int i = 0; i < N; i++)
    {
        printf("\n---------------------------------------------\n");
        printf("Data for Edge %d:\n", (i + 1));
        printf("Enter source node : ");
        scanf("%d", &G[i].src);
        printf("Enter destination node : ");
        scanf("%d", &G[i].dst);
        printf("Enter the weight of the edge : ");
        scanf("%d", &G[i].wgt);
    }

    // arranging the edges in ascending order of the weight
    sort(G, N);

    // perform kruskal algorithm on the set of sorted edges
    kruskal(G, N);
}