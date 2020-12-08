#include "BinaryHeap.h"
#include <iostream>

using namespace std;

////////////
//BinaryHeap 

//Constructor
BinaryHeap::BinaryHeap()
{
	HeapSize = 0;
	root = new int[MaxSize];
}

//Destructor
BinaryHeap::~BinaryHeap()
{
	delete[] root;
}


//Searching for an element in the tree by key
bool BinaryHeap::contains(int key)
{
	for (int i = 0; i < HeapSize; i++)
	{
		if (key == root[i])
			return true;
	}
	return false;
}

//Sifting up
void BinaryHeap::siftUP(int i)
{
	int parent = (i - 1) / 2;
	if (i > 0 && root[parent] < root[i])
	{
		int temp = root[i];
		root[i] = root[parent];
		root[parent] = temp;
		siftUP(parent);
	}
}
 
//Sifting down
void BinaryHeap::siftDown(int i)
{
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int greater;
	if (right<HeapSize && root[right]>root[left])
		greater = right;
	else
		greater = left;
	if (greater<HeapSize && root[greater]>root[i])
	{
		int temp = root[i];
		root[i] = root[greater];
		root[greater] = temp;
		siftDown(greater);
	}
}

//Heapify
void BinaryHeap::heapify(int key,int i)
{
	//for (int i = (HeapSize - 1) / 2; i >= 0; i--)
	//	siftDown(i);
	int parent = (i - 1) / 2;
	if (key >= root[parent])
		siftUP(i);
	else
		siftDown(i);
}

//Adding an element to the tree by key
void BinaryHeap::insert(int key)
{
	if (HeapSize == MaxSize)
	{
		int* transit = new int[MaxSize+10];
		for (int i = 0; i < HeapSize; i++)
			transit[i] = root[i];
		delete root;
		root = transit;
		MaxSize += 10;
	}
	root[HeapSize] = key;
	HeapSize++;
	heapify(key,HeapSize-1);
}

//Deleting a tree element by key
void BinaryHeap::remove(int key)
{
	if (this->HeapSize == 0)
		throw "Heap is empty";
	int i = 0;
	while (root[i] != key)
		i++;
	root[i] = root[HeapSize - 1];
	HeapSize--;
	heapify(key,i);
}

//Binary heap output as a tree
void BinaryHeap::out()
{
	int i = 0;
	int k = 1;
	while (i < HeapSize)
	{
		////Simple ouput to show the tree
		//if (i == 0)
		//	cout << "   ";
		//else if (i == 1)
		//	cout << "  ";
		////
		while ((i < k) && (i < HeapSize))
		{
			cout << root[i] << ' ';
			i++;
		}
		cout << endl;
		k = k * 2 + 1;
	}
}

//////////////
//dft_iterator
Iterator* BinaryHeap::create_dft_iterator()
{

	return new dft_iterator(0);
}

BinaryHeap::dft_iterator::dft_iterator(int index=0)
{
	this->index = index;
}

bool BinaryHeap::dft_iterator::has_next(BinaryHeap* t)
{
	if (index == 0)
		return true;
	if (t->HeapSize == 0)
		return false;
	if (!stk.isEmpty() && index != 0)
		return false;
	else
		return true;
}

int BinaryHeap::dft_iterator::next(BinaryHeap *t)
{
	if (!has_next(t))
		throw "The last element in the heap";
	int var = t->root[index];
	int left = index * 2 + 1, right = index * 2 + 2;
	if (index == 0)
		stk.push_back(0);
	if (right < t->HeapSize)
	{
		stk.push_back(right);
		index = left;
	}
	else if (left < t->HeapSize)
		index = left;
	else
	{
		if (stk.at(stk.get_size() - 1) == 0)
			stk.pop_back();
		else
		{
			index = stk.at(stk.get_size() - 1);
			stk.pop_back();
		}
		if (t->HeapSize == 1)
			index = -1;
	}
	return var;
}

//////////////
//Bft_iterator
Iterator* BinaryHeap::create_bft_iterator()
{

	return new bft_iterator(0);
}

BinaryHeap::bft_iterator::bft_iterator(int index = 0)
{
	this->index = 0;
}

bool BinaryHeap::bft_iterator::has_next(BinaryHeap* t)
{
	return index != t->HeapSize;
}

int BinaryHeap::bft_iterator::next(BinaryHeap *t)
{
	if (!has_next(t))
		throw "The last element in the heap";
	this->index++;
	return t->root[index-1];
}