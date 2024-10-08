/* C program to demonstrate Prim's algorithm */

#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int src;
    int dst;
    int wgt;
    int added_to_mst;
    int discard_edge;
} edge;

int is_in_mst(int vtx_arr[], int vtx, int idx_arr)
/**
 * Check if a vertex is in the minimum spanning tree (MST) represented by the given array.
 * 
 * @param vtx_arr The array containing vertices of the MST.
 * @param vtx The vertex to check for presence in the MST.
 * @param idx_arr The number of elements in the array.
 * @return 1 if the vertex is in the MST, 0 otherwise.
 */
{
    for (int i = 0; i < idx_arr; i++)
    {
        if (vtx_arr[i] == vtx)
        {
            return 1;
        }
    }
    return 0;
}

void prims(edge g[], int N, int total_vertices)
/**
 * Perform Prim's algorithm to find the Minimum Spanning Tree (MST) of a graph represented by the given edges.
 * 
 * @param g The array of edges representing the graph.
 * @param N The total number of edges in the graph.
 * @param total_vertices The total number of vertices in the graph.
 */
{
    edge out[20];
    int idx = 0;
    int vtx_arr[20];        // temporary array to hold the vertices that form the MST
    int idx_arr = 0;

    // Find the edge with minimum weight to start
    int min_edge_idx = -1;
    int minimum_wt = 1000;

    for (int i = 0; i < N; i++)
    {
        if (g[i].wgt < minimum_wt)
        {
            minimum_wt = g[i].wgt;
            min_edge_idx = i;
        }
    }

    if (min_edge_idx == -1)
    {
        printf("No edges available\n");
        return;
    }

    // Add the seed vertex (selecting the one connected to the minimum weight edge)
    vtx_arr[idx_arr++] = g[min_edge_idx].src;  // Start with the first vertex

    // Continue until we have N-1 edges in MST or all vertices are added
    while (idx < total_vertices - 1)
    {
        edge edge_to_add;
        int minimum_wt = 1000;
        int edge_idx = -1;

        for (int j = 0; j < N; j++)
        {
            if (g[j].added_to_mst == 0 && g[j].discard_edge == 0)
            {
                if (is_in_mst(vtx_arr, g[j].src, idx_arr) && !is_in_mst(vtx_arr, g[j].dst, idx_arr))
                {
                    if (g[j].wgt < minimum_wt)
                    {
                        minimum_wt = g[j].wgt;
                        edge_to_add = g[j];
                        edge_idx = j;
                    }
                }
                else if (is_in_mst(vtx_arr, g[j].dst, idx_arr) && !is_in_mst(vtx_arr, g[j].src, idx_arr))
                {
                    if (g[j].wgt < minimum_wt)
                    {
                        minimum_wt = g[j].wgt;
                        edge_to_add = g[j];
                        edge_idx = j;
                    }
                }
            }
        }

        // If no edge is found, break the loop
        if (edge_idx == -1)
        {
            printf("The graph is disconnected and no MST can be formed!");
            break;
        }

        // Add this edge to MST
        out[idx++] = edge_to_add;
        g[edge_idx].added_to_mst = 1;  // Mark the edge as added to MST

        // Update vtx_arr with the new vertex added to MST
        if (is_in_mst(vtx_arr, edge_to_add.src, idx_arr))
        {
            vtx_arr[idx_arr++] = edge_to_add.dst;
        }
        else
        {
            vtx_arr[idx_arr++] = edge_to_add.src;
        }

        // print the added edge
        printf("Added edge : {source : %d, destination : %d, weight : %d}\n", edge_to_add.src, edge_to_add.dst, edge_to_add.wgt);
    }

    // Printing the output MST
    printf("Prim's MST\n");
    for (int i = 0; i < idx; i++)
    {
        printf("{source : %d, destination : %d, weight : %d}\n", out[i].src, out[i].dst, out[i].wgt);
    }
}

int main()
/**
 * Main function to input the number of edges and vertices, and then create and initialize an array of edges based on user input.
 * 
 * Prompts the user to enter the number of edges and vertices, and then iterates to input source, destination, and weight for each edge.
 * Initializes the added_to_mst and discard_edge flags for each edge.
 * Calls the prims function to perform Prim's algorithm on the edges to find the Minimum Spanning Tree (MST).
 * 
 * @return 0 indicating successful execution of the program.
 */
{
    int N = 0;
    int total_vertices = 0;

    printf("Enter the number of edges :");
    scanf("%d", &N);
    printf("Enter the number of vertices :");
    scanf("%d", &total_vertices);

    edge G[20];

    // input edge data from the user
    for (int i = 0; i < N; i++)
    {
        printf("\n---------------------------------------------\n");
        printf("Data for Edge %d:\n", (i + 1));
        printf("Enter source node : ");
        scanf("%d", &G[i].src);
        printf("Enter destination node : ");
        scanf("%d", &G[i].dst);
        printf("Enter the weight of the edge : ");
        scanf("%d", &G[i].wgt);

        G[i].added_to_mst = 0;
        G[i].discard_edge = 0;
    }

    // perform Prim's algorithm on the edges to find the MST
    prims(G, N, total_vertices);

    return 0;
}
