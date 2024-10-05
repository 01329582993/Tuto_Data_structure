#include <iostream>
#include <vector>
#include <algorithm>


void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}


void heapify_up(std::vector<int> &heap, int index)
{
    while (index > 0 && heap[(index - 1) / 2] > heap[index])
    {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}


void heapify_down(std::vector<int> &heap, int index)
{
    int size = heap.size();
    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;

    if (left < size && heap[left] < heap[smallest])
    {
        smallest = left;
    }

    if (right < size && heap[right] < heap[smallest])
    {
        smallest = right;
    }

    if (smallest != index)
    {
        swap(heap[index], heap[smallest]);
        heapify_down(heap, smallest);
    }
}

int Heap_Minimum(const std::vector<int> &heap)
{
    return heap[0];
}


int Heap_extract_min(std::vector<int> &heap)
{
    if (heap.size() == 0)
    {
        return -1;
    }

    int min_value = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    heapify_down(heap, 0);
    return min_value;
}


void Min_heap_insert(int value, std::vector<int> &heap)
{
    heap.push_back(value);
    heapify_up(heap, heap.size() - 1);
}


void Heap_decrease_key(int i, int k, std::vector<int> &heap)
{
    if (i >= heap.size()) return;

    heap[i] -= k;
    heapify_up(heap, i);
}


void Heap_increase_key(int i, int k, std::vector<int> &heap)
{
    if (i >= heap.size()) return;

    heap[i] += k;
    heapify_down(heap, i);

}

void displayHeap(const std::vector<int> &heap)
{
    for (int val : heap)
    {
        std::cout << val << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::vector<int> heap;


    int val;
    while (std::cin >> val && val != -1)
    {
        Min_heap_insert(val, heap);
    }


    std::cout << "Min Heap: ";
    displayHeap(heap);

    int function_id;
    while (std::cin >> function_id)
    {
        if (function_id == 1)
        {
            std::cout << Heap_Minimum(heap) << std::endl;
        }
        else if (function_id == 2)
        {
            std::cout << Heap_extract_min(heap) << std::endl;
            displayHeap(heap);
        }
        else if (function_id == 3)
        {
            int value;
            std::cin >> value;
            Min_heap_insert(value, heap);
            displayHeap(heap);
        }
        else if (function_id == 4)
        {
            int i, k;
            std::cin >> i >> k;
            Heap_decrease_key(i - 1, k, heap);
            displayHeap(heap);
        }
        else if (function_id == 5)
        {
            int i, k;
            std::cin >> i >> k;
            Heap_increase_key(i - 1, k, heap);
            displayHeap(heap);
        }
    }

    return 0;
}
