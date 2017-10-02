#include "prim.hpp"

std::vector<int> Prim( std::vector< std::vector<int> > &adj_matrix ) 
{
    int size = adj_matrix.size();
    int min_index;

    std::vector<Elements> elements( size );
    std::vector<bool> included( size, false );
    std::vector<int> parents( size );

    for ( int i = 1; i < size; i++ )
    {
        elements[i].index_ = i;
        elements[i].key_ = INT_MAX;
        //parents[i] = -1;
    }
    
    parents[0] = -1;

    MinHeap min_heap( size, elements );

    while ( min_heap.GetSize() )
    {
        min_index = min_heap.ExtractMin().index_;

        included[min_index] = true;

        for ( int j = 0; j < size; j++ )
        {         
            if ( ( adj_matrix[min_index][j] && !included[j] ) && ( adj_matrix[min_index][j] < elements[j].key_ ) )
            {
                parents[j] = min_index;
                min_heap.Decrease( j, adj_matrix[min_index][j] );
            }
        }
    }
    return parents;
}
