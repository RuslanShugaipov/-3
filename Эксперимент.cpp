#include "BinaryHeap.h"
#include <iostream>

using namespace std;

void main()
{
	BinaryHeap binheap;
	int j, max;
	cout << "Enter the number of elements: ";
	cin >> max;
	for (int i = 0; i < max; i++)
	{
		cin >> j;
		binheap.insert(j);
	}
	cout << endl;
	binheap.out();
	cout << endl;

	//Iterator depth-first traverse
	Iterator* heap_dft_iterator = binheap.create_dft_iterator();
	while (heap_dft_iterator->has_next(&binheap))
		cout << heap_dft_iterator->next(&binheap) << ' ';

	cout << "\n\n";

	//Iterator breadth-first traverse
	Iterator* heap_bft_iterator = binheap.create_bft_iterator();
	while (heap_bft_iterator->has_next(&binheap))
		cout << heap_bft_iterator->next(&binheap) << ' ';
}