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
	int capacity; // capacity 디폴트 크기
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
// heap의 크기를 size만큼 늘리는 함수.
//작성
{
	if (size < 0) { throw "New length must be >= 0"; }
	capacity = size;
	T* tmp = new T[size]; // 새로운 배열
	copy(heap, heap + heapSize, tmp);
	delete[]heap;
	heap = tmp;
}

template <class T>
void Maxheap<T>::Push(const T& newdata)
// 작성
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
// 작성
{
	if (IsEmpty())throw "Heap is empty. Cannot delete";
	heap[1].~T();
	
	// 히프의 마지막 원소 제거
	T lastE = heap[heapSize--];

	// trickle down
	int currentNode = 1; // root
	int child = 2; // currentNode의 자식

	while (child <= heapSize)
	{
		//child를 currentNode의 큰 자식으로 설정
		if (child < heapSize && heap[child] < heap[child + 1])child++;

		//currentNode에 lastE를 삽입할 수 있는가?
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
// Maxheap 생성자 (capacity를 입력받음)
{
	if (_capacity < 1)
		throw "Must be > 0";
	capacity = _capacity;
	heap = new T[capacity + 1];
}

#endif



