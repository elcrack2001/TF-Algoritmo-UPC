#include "Librerias.h"

using namespace std;

void swap(int *x, int *y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

class MaxHeap {
private:
	int *heap;
	int capacity;
	int position;
public:
	MaxHeap(int cap) {
		position = 1;
		capacity = cap + 1;
		heap = new int[capacity];
	}

	void insert(int value) {
		if (position == capacity) { // Si no llega a 7
			return;
		}
		heap[position] = value;  // heap[5] = 8
		position++;  // 6
		int child = position - 1; // 5
		int parent = child / 2; // 2
		while (heap[parent] < heap[child] && parent>0) {
			swap(heap[parent], heap[child]);
			child = parent;
			parent = child / 2;
		}
	}
	//-------------------------------------------------------------------------
	int extract() {
		int val = heap[1];
		position--;
		heap[1] = heap[position];
		heap[position] = 0;
		int i = 1;
		while (i <= position) {
			int lc = 2 * i;
			int rc = 2 * i + 1;
			int c = heap[lc] > heap[rc] ? lc : rc;
			if (heap[i] < heap[c]) {
				swap(heap[i], heap[c]);
				i = c;
			}
			else
				break;
			//heapify end
		}
		return(val);
	}
};


