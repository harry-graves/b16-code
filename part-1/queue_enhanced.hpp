#ifndef __queue_enhanced__
#define __queue_enhanced__

#include <cassert>
#include <vector>

#include "queue.hpp"

template <typename T> class Dequeue : public Queue<T>
{
  public:
    // Inherit the constructors of Queue<T>
    using Queue<T>::Queue;

    // Access the element at the back of the queue
    T &back()
    {
        assert(this->_size >= 1);
        return this->_storage[_tail()];
    }

    // Const-access the element at the back of the queue
    const T &back() const
    {
        assert(this->_size >= 1);
        return this->_storage[_tail()];
    }

    // Add a new element to the front of the queue by copying
    void enqueue_front(const T &value)
    {
        assert(this->_size < this->_storage.size());
        this->_size++;
        this->_storage[this->_head()] = value; // The head function does the wrapping around itself
    }

    // Remove the element at the back of the queue
    void dequeue_back()
    {
        assert(this->_size >= 1);
        this->_size--;
        this->_position = _tail();  // The tail function does the wrapping around itself
    }

    // Remove all elements from the queue
    void clear()
    { 
        this->_storage.clear();
    }

  protected:
    // Return the index of the element at the back of the queue
    size_t _tail() const
    {
        assert(this->_size >= 0);
        auto index = 0;
        if (this->_position + 1 == this->_storage.size())
        {
            index = 0;
        }
        else
        {
            index = this->_position + 1;
        }  
        return index;
    }
};

#endif // __queue_enhanced__