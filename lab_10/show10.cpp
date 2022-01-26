#include "HashTable.h"

// show10.cpp: contains implementation of the HashTable showStructure function
template<typename T, typename KeyType>
void HashTable<T, KeyType>::showStructure() const {
	for (int i = 0; i < tableSize; ++i) {
		cout << i << ": ";
		dataTable[i].writeKeys();
	}
}
