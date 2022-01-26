//--------------------------------------------------------------------
//
//  Laboratory 7                                       QueueArray.cpp
//
//  ** SOLUTION: Array implementation of the Queue ADT **
//
//--------------------------------------------------------------------

#ifndef QUEUEARRAY_CPP
#define QUEUEARRAY_CPP

#include <iostream>

#include "QueueArray.h"

//--------------------------------------------------------------------

template <typename DataType>
QueueArray<DataType>::QueueArray(int maxNumber)

// Creates an empty queue. Allocates enough memory for maxNumber
// data items (defaults to MAX_QUEUE_SIZE in class declaration).

{
    //initialize variables
    front = -1; // front to -1 space
    back = -1; // back to -1 space
    maxSize=maxNumber // set maxsize to maxnumber

        // Allocate Memory space for dataItems with new Datatype
    dataItems = new DataType[maxNumber];
}

//--------------------------------------------------------------------

template <typename DataType>
QueueArray<DataType>::~QueueArray() 

// Frees the memory used by a queue.

{
    delete[] dataItems;
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::enqueue(const DataType& newDataItem) throw (logic_error)

// Inserts newDataItem at the rear of a queue.

{  // insert data item at back of queue
        if (isFull()) {
            throw logic_error("enqueue() while queue full");
        }

        back = (++back) % maxSize;  // use to ensure quue is not full
        dataItems[back] = newDataItem;
        if (front == -1)  //if function to do so 
            front = 0;




 
}

//--------------------------------------------------------------------
// Sequeue function
template <typename DataType>
DataType QueueArray<DataType>::dequeue() throw (logic_error) 

// Removes the least recently added (front) data item from a queue
// and returns it.

{
    if (isEmpty()) {
	throw logic_error("dequeue() while queue empty");
    }

    //if function to removee added front item and reorganzie it 
    int retIndex = front;
    if ( front == back )
    {
        front = -1;
        back = -1;
    }
    else
    {

        front = (++front) % maxSize //queue is not empty 
    }
    return dataItems[retIndex]; // return dataitem with retindex 
}

//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::clear() 

// Removes all the data items from a queue.

{
    // set front and back to -1
    front = -1;
    back = -1;
}

//--------------------------------------------------------------------

template <typename DataType>
bool QueueArray<DataType>::isEmpty() const 
{
    return front == -1;
}

//--------------------------------------------------------------------

template <typename DataType>
bool QueueArray<DataType>::isFull() const 
{// compare front back
    return front == (back + 1) % maxSize;;
}

//--------------------------------------------------------------------

#if LAB7_TEST2
// insert data item
template <typename DataType>
void QueueArray<DataType>::putFront(const DataType& newDataItem) throw (logic_error) 

//  Enqueues newDataItem at the front of the queue --
//  deque behavior -- instead of at the back as would normally happen.

{
    if (isFull()) {
	throw logic_error("putFront() while queue full");
    }

    --front;
    if (front < 0) 		// Need to wrap around to end of array
    {
        front = maxSize - 1;
    }
   
    dataItems[front] = newDataItem;

}

//--------------------------------------------------------------------

template <typename DataType>
DataType QueueArray<DataType>::getRear() throw (logic_error) 

//  Removes and returns the dataItem at the rear of the queue --
//  deque behavior -- instead of at the head as would normally happen.

{
    if (isEmpty()) {
        throw logic_error("getRear() while queue empty");
    }

    int valuePos = back;
    --back;
    if (back == front - 1) {		// Just removed last item
        back = front = -1;
    }
    else if (back < 0) {
        back = maxSize - 1; // remove from max size 
    }
    // return data item
    return dataItems[valuePos];
}
#endif

//--------------------------------------------------------------------

#if LAB7_TEST3
template <typename DataType>
int QueueArray<DataType>::getLength() const 

//  Calculates and returns the length of the queue.

{
    //if function to Returns the number of dat items in a queue
    if( isEmpty() ) {
	return 0;
    }
    else if (front > back) {
	return (maxSize - front) + (back + 1);
    } 
    else {
	return (back - front) + 1;
    }
}
#endif
 
//--------------------------------------------------------------------

template <typename DataType>
void QueueArray<DataType>::showStructure() const 
// Array implementation. Outputs the data items in a queue. If the
// queue is empty, outputs "Empty queue". This operation is intended
// for testing and debugging purposes only.

{
    int j;   // Loop counter

    if ( front == -1 )
       cout << "Empty queue" << endl;
    else
    {
       cout << "Front = " << front << "  Back = " << back << endl;
       for ( j = 0 ; j < maxSize ; j++ )
           cout << j << "\t";
       cout << endl;
       if ( back >= front )
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) && ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       else
          for ( j = 0 ; j < maxSize ; j++ )
              if ( ( j >= front ) || ( j <= back ) )
                 cout << dataItems[j] << "\t";
              else
                 cout << " \t";
       cout << endl;
    }
}

#endif		//#ifndef QUEUEARRAY_CPP
