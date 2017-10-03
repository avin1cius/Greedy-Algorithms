#include "binary_heap.hpp"

MinHeap::MinHeap( const int capacity, std::vector<Elements> &elements ) : 
    capacity_{ capacity }, elements_{ elements } 
    {
        BuildHeap();
    }

void MinHeap::Heapify( int index )
{
    int left = 2*index + 1;
    int right = 2*index + 2;
    int smallest = index;

    if ( ( left < size_ ) && ( elements_[left].key_ < elements_[smallest].key_ ) ) smallest = left; 

    if ( ( right < size_ ) && ( elements_[right].key_ < elements_[smallest].key_ ) ) smallest = right;

    if ( smallest != index )
    {
        std::swap( elements_[index], elements_[smallest] );
        Heapify( smallest );
    }
}

void MinHeap::BuildHeap()
{
    size_ = elements_.size();

    if ( size_ <= 1 ) return;

    for ( int i = ( size_ - 2 )/2; i >= 0; i-- )
    {
        Heapify( i );
    }
}

inline Elements MinHeap::Minimum()
{
    return elements_[0];
}

Elements MinHeap::ExtractMin()
{
    if ( size_ < 1 )
    {
        std::cout << "Empty" << std::endl;
        Elements null;
        return null;
    }

    Elements min = elements_[0];
    elements_[0] = elements_[size_ - 1];
    //std::swap( elements_[0], elements_[size_ - 1] );
    size_--;
    Heapify( 0 );

    return min;
}

void MinHeap::Decrease( int index, int key )
{

    if ( key >= elements_[index].key_ )
    {
        std::cout << "Nothing to do" << std::endl;
        return;
    }

    elements_[index].key_ = key;
    
    int parent = (index - 1)/2;

    while ( index > 0 &&  elements_[parent].key_ > elements_[index].key_ )
    {
        std::swap( elements_[index], elements_[parent] );
        index = parent;
        parent = (index - 1)/2;
    }
}

void MinHeap::Insert( int key )
{
    if ( size_ == capacity_ )
    {
        std::cout << "Overflow" << std::endl;
        return;
    }

    size_++;
    elements_[size_ - 1].key_ = INT_MAX;

    Decrease( size_ - 1, key );
}

int MinHeap::GetSize()
{
    return size_;
}

void MinHeap::PrintHeap()
{
    for ( int i = 0; i < size_; i++ )
    {
        std::cout << elements_[i].index_ << " " << elements_[i].key_ << std::endl;
    }
}
