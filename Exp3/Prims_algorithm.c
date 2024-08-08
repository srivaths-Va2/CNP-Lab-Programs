/* C program for Prim's algorithm */

#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int src;
    int dst;
    int wgt;
    int added_to_mst;
    int discard_edge;
}edge;

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

void prims(edge g[], int N)
{
    edge out[20];
    int idx = 0;
    int vtx_arr[20];        // temporary array to hold the vertices that form the MST
    int idx_arr = 0;

    // add the seed vertex
    vtx_arr[idx_arr] = g[0].src;
    idx_arr++;

    // flag to check whether the edge has been added by greedy method
    int greedy_add_flag = 0;
    
    // iterate across the edges to find the edge with minimum weight -> greedy approach
    for(int k = 0; k < 15; k++)
    {
        while(greedy_add_flag == 0)
        {
            edge edge_to_add;
            int minimum_wt = 1000;
            int edge_idx = 0;
            for(int i = 0; i < idx_arr; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    // get those edges that are connected to the vertices forming MST
                    if(vtx_arr[i] == g[j].src && g[j].added_to_mst == 0 && g[j].discard_edge == 0)
                    {
                        // check if it is the minimum edge
                        if(g[j].wgt < minimum_wt)
                        {
                            minimum_wt = g[j].wgt;
                            edge_to_add = g[j];
                            edge_idx = j;
                        }

                    }

                }
            }

            // Check if the edge when added to output forms a cycle
            int check_cyc_flag = check_cycle(out, edge_to_add, idx);

            // if the edge does not form a cycle
            if(check_cyc_flag == 1)
            {
                // add the edge to the MST
                out[idx] = edge_to_add;
                idx++;
                g[edge_idx].added_to_mst = 1;       // added to MST confirmation

                // Updating vtx_arr
                vtx_arr[idx_arr] = edge_to_add.src;
                idx_arr++;

                // print the added edge
                printf("Added edge : {source : %d, destination : %d, weight : %d}\n", edge_to_add.src, edge_to_add.dst, edge_to_add.wgt);

                // as the edge has been added by greedy method, update greedy_add_flag
                greedy_add_flag = 1;
            }

            // if edge forms a cycle, set discard flag
            else if(check_cyc_flag == 0)
            {
                g[edge_idx].discard_edge = 1;
                greedy_add_flag = 0;
            }
        }
    }

    // Printing the output MST
    printf("Prim's MST\n");
    for(int i = 0; i < idx; i++)
    {
        printf("{source : %d, destination : %d, weight : %d}\n", out[i].src, out[i].dst, out[i].wgt);
    }
}

void main()
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

        G[i].added_to_mst = 0;
    }

    // perform Prim's algorithm on the edges to find the MST
    prims(G, N);
}
