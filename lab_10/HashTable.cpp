#include "HashTable.h"

//hash table function
template<typename T, typename KeyType>
HashTable<T, KeyType>::HashTable(int initTableSize) {
	tableSize = initTableSize; // set tablesize to have value
	dataTable = new BSTree<T, KeyType>[tableSize];
}

// hashtable function to copytable, and create table size
template<typename T, typename KeyType>
HashTable<T, KeyType>::HashTable(const HashTable &other) {
	tableSize = other.tableSize;
	dataTable = new BSTree<T, KeyType>[tableSize];
	copyTable(other);
}

// Hashtable operator function to clear and copytable
template<typename T, typename KeyType>
HashTable<T, KeyType>&HashTable<T, KeyType>::operator=(const HashTable &other) {
	clear();
	copyTable(other);
}
// hash table to clear function
template<typename T, typename KeyType>
HashTable<T, KeyType>::~HashTable() {
	clear();
}

// hashtable function to insert 
template<typename T, typename KeyType>
void HashTable<T, KeyType>::insert(const T& newDataItem) {

	int loc = T::hash(newDataItem.getKey()) % tableSize;
	dataTable[loc].insert(newDataItem);
}

// hash table function to remove 
template<typename T, typename KeyType>
bool HashTable<T, KeyType>::remove(const KeyType &deleteKey) {
	int loc = T::hash(deleteKey) % tableSize;
	return dataTable[loc].remove(deleteKey);
}

// rertriev function
template<typename T, typename KeyType>
bool HashTable<T, KeyType>::retrieve(const KeyType &searchKey, T &returnItem) const {
	int loc = T::hash(searchKey) % tableSize;
	return dataTable[loc].retrieve(searchKey, returnItem);
}

//clear function
template<typename T, typename KeyType>
void HashTable<T, KeyType>::clear() {
	for (int i = 0; i < tableSize; i++) {
		if (!dataTable[i].isEmpty()) {
			dataTable[i].clear();
		}
	}
}
// if function for iesmpty
template<typename T, typename KeyType>
bool HashTable<T, KeyType>::isEmpty() const {
	for (int i = 0; i < tableSize; i++) {
		if (!dataTable[i].isEmpty()) {
			return false;
		}
	}
	return true;
}
// include show 
#include "show10.cpp"
//standard deviation
template<typename T, typename KeyType>
double HashTable<T, KeyType>::standardDeviation() const {


	// Declare Variable
	double xbar;
	double sumOfSquares;
	int i;
	int n = 0;
	int totalNodes = 0;
	// for loop to get standard deviation
	for (i = 0; i < tableSize; i++) {
		if (dataTable[i].isEmpty()) { continue; }
		totalNodes += dataTable[i].getCount();
		n++;
	}
	// function  for table 
	xbar = totalNodes / n;

	for (i = 0; i < tableSize; i++) {
		if (dataTable[i].isEmpty()) { continue; }
		sumOfSquares += pow((dataTable[i].getCount() - xbar), 2);
	}
	//return function  
	return (n - 1) == 0 ? 0 : sqrt(sumOfSquares / (n - 1));
}

template<typename T, typename KeyType>
void HashTable<T, KeyType>::copyTable(const HashTable &source) {}
