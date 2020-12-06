#include "pch.h"
#include "CppUnitTest.h"
#include "C:\Users\Руслан\source\repos\АлгиСтр(Лр3)\АлгиСтр(Лр3)\BinaryHeap.cpp"
#include "C:\Users\Руслан\source\repos\АлгиСтр(Лр3)\АлгиСтр(Лр3)\BinaryHeap.h"
#include "C:\Users\Руслан\source\repos\АлгиСтр(Лр3)\АлгиСтр(Лр3)\LinkedList.h"
#include "C:\Users\Руслан\source\repos\АлгиСтр(Лр3)\АлгиСтр(Лр3)\LinkedListcpp.cpp"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestЛР3
{
	TEST_CLASS(BinaryHeapTests)
	{
	public:

		TEST_METHOD(contains)
		{
			BinaryHeap test;
			test.insert(1);
			test.insert(2);
			test.insert(3);
			Assert::AreEqual(test.contains(1), true);
			Assert::AreEqual(test.contains(4), false);
		}

		TEST_METHOD(insert)
		{
			BinaryHeap test;
			test.insert(1);
			test.insert(2);
			test.insert(3);
			Assert::AreEqual(test.contains(1), true);
			Assert::AreEqual(test.contains(2), true);
			Assert::AreEqual(test.contains(3), true);
		}

		TEST_METHOD(remove)
		{
			BinaryHeap test;
			test.insert(1);
			test.insert(2);
			test.insert(3);
			Assert::AreEqual(test.contains(1), true);
			Assert::AreEqual(test.contains(2), true);
			Assert::AreEqual(test.contains(3), true);

			test.remove(3);
			Assert::AreEqual(test.contains(1), true);
			Assert::AreEqual(test.contains(2), true);
			Assert::AreEqual(test.contains(3), false);
		}

		TEST_METHOD(dft_iterator)
		{
			BinaryHeap test;
			int array[7] = { 6,5,4,3,2,1,0 };
			int check[7] = { 6,5,3,2,4,1,0 };
			for (int i = 0; i < 7; i++)
				test.insert(array[i]);
			Iterator* heap_dft_iterator = test.create_dft_iterator();
			for (int i = 0; i < 7; i++)
				Assert::IsTrue(heap_dft_iterator->next() == check[i]);
		}

		TEST_METHOD(bft_iterator)
		{
			BinaryHeap test;
			int array[7] = { 6,5,4,3,2,1,0 };
			for (int i = 0; i < 7; i++)
				test.insert(array[i]);
			Iterator* heap_bft_iterator =test.create_bft_iterator();
			for (int i = 0; i < 7; i++)
				Assert::IsTrue(heap_bft_iterator->next() == array[i]);
		}
	};
}
