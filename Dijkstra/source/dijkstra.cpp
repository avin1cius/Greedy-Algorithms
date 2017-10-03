#include "dijkstra.hpp"

std::vector<int> Dijkstra( const std::vector< std::vector<int> > &adj_matrix, std::vector<Elements> &elements ) 
{
    int graph_size = adj_matrix.size();
    Elements min;
    int min_index;

    //std::vector<Elements> elements( graph_size );
    std::vector<int> parents( graph_size, -1 );
    std::vector<bool> included( graph_size, false );

    for ( int i = 1; i < graph_size; i++ )
    {
        elements[i].index_ = i;
        elements[i].key_ = INT_MAX;
    }

    MinHeap min_heap( graph_size, elements );

    while ( min_heap.GetSize() )
    {
        min = min_heap.ExtractMin();
        min_index = min.index_;

        included[min_index] = true;

        for ( int j = 0, k = 0; j < graph_size; j++ )
        {
            for ( int i = 0; i < graph_size; i++ ) 
            {
                if ( elements[i].index_ == j ) 
                {
                    k = i;
                    break;
                }
            }           

            if ( ( adj_matrix[min_index][j] && !included[j] ) && ( ( adj_matrix[min_index][j] + min.key_ ) < elements[k].key_ ) )
            //if ( adj_matrix[min_index][j] && ( adj_matrix[min_index][j] < elements[k].key_ ) )
            {
                parents[j] = min_index;

                min_heap.Decrease( k, adj_matrix[min_index][j] + min.key_ );
            }
        }
    }
    return parents;
}
