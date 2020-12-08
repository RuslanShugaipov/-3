#pragma once
#include "Iterator.h"
#include "LinkedList.h"


class BinaryHeap
{
protected:
	int MaxSize = 10;
	int* root;
	int HeapSize;
public:
	BinaryHeap();
	~BinaryHeap();
	bool contains(int);
	void insert(int);
	void heapify(int,int);
	void remove(int);
	void out();
	void siftUP(int);
	void siftDown(int);

	//Dft_iterator
	Iterator* create_dft_iterator();
	class dft_iterator : public Iterator
	{
	public:
		dft_iterator(int);
		int next(BinaryHeap*) override;
		bool has_next(BinaryHeap*) override;
	private:
		int index;
		LinkedList stk;
	};

	//Bft_iterator
	Iterator* create_bft_iterator();
	class bft_iterator :public Iterator
	{
	public:
		bft_iterator(int);
		int next(BinaryHeap*) override;
		bool has_next(BinaryHeap*) override;
	private:
		int index;
	};
};