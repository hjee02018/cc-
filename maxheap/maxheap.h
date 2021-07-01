#ifndef __MAXHEAP_H__
#define __MAXHEAP_H__
#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Maxheap
{
private:
	void ChangeSize1D(int);
	T* heap;
	int heapSize;
	int capacity; // capacity ����Ʈ ũ��
public:
	Maxheap(int);
	void Push(const T&);
	void Pop();
	bool IsEmpty() { return heapSize == 0; }
	T Top() { return heap[1]; }
	template <class T2> friend ostream& operator<<(ostream&, Maxheap<T2>&);
};

template <class T>
void Maxheap<T>::ChangeSize1D(int size)
// heap�� ũ�⸦ size��ŭ �ø��� �Լ�.
//�ۼ�
{
	if (size < 0) { throw "New length must be >= 0"; }
	capacity = size;
	T* tmp = new T[size]; // ���ο� �迭
	copy(heap, heap + heapSize, tmp);
	delete[]heap;
	heap = tmp;
}

template <class T>
void Maxheap<T>::Push(const T& newdata)
// �ۼ�
{
	if (heapSize == capacity)
	{
		ChangeSize1D(2 * capacity + 1);
	}
	int currentNode = ++heapSize;
	while (currentNode != 1 && heap[currentNode / 2] < newdata)
		// bubbling- up
		{
			heap[currentNode] = heap[currentNode / 2];
			currentNode /= 2;
		}
		heap[currentNode] = newdata;
}

template <class T>
void Maxheap<T>::Pop()
// �ۼ�
{
	if (IsEmpty())throw "Heap is empty. Cannot delete";
	heap[1].~T();
	
	// ������ ������ ���� ����
	T lastE = heap[heapSize--];

	// trickle down
	int currentNode = 1; // root
	int child = 2; // currentNode�� �ڽ�

	while (child <= heapSize)
	{
		//child�� currentNode�� ū �ڽ����� ����
		if (child < heapSize && heap[child] < heap[child + 1])child++;

		//currentNode�� lastE�� ������ �� �ִ°�?
		if (lastE >= heap[child])break; //yes

		//no
		heap[currentNode] = heap[child];
		currentNode = child;
		child *= 2;
	}

	heap[currentNode] = lastE;

}

template <class T>
ostream& operator <<(ostream& os, Maxheap<T>& H)
{
	os << "<Heap contents>";
	int i;
	for (i = 1;i <= H.heapSize;i++)
	{
		os << i << ":" << H.heap[i] << " ";
	}
	os << endl;
	return os;
}

template <class T>
Maxheap<T>::Maxheap(int _capacity=10) : heapSize(0)
// Maxheap ������ (capacity�� �Է¹���)
{
	if (_capacity < 1)
		throw "Must be > 0";
	capacity = _capacity;
	heap = new T[capacity + 1];
}

#endif



