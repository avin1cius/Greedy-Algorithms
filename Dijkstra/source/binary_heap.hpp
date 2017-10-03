#ifndef BINARY_HEAP_HPP_
#define BINARY_HEAP_HPP_

#include <iostream>
#include <vector>
#include <climits>

struct Elements
{
    int index_;
    int key_;    
};

class MinHeap
{
    int capacity_;
    int size_;
    std::vector<Elements> &elements_;
public:
    MinHeap();
    MinHeap( const int, std::vector<Elements> & ); 

    void Heapify( int );    
    void BuildHeap();   
    Elements Minimum();    
    Elements ExtractMin();  
    void Decrease( int, int );
    void Insert( int );

    int GetSize();
    void PrintHeap();    
};

#endif // BINARY_HEAP_HPP_