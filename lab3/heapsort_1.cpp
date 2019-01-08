#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

vector<int> heap;

void heapify(int k)
{
    int min = k;
    int left = (2 * k) + 1;
    int right = (2 * k) + 2;

    if ((left < heap.size()) && (heap[left] < heap[min]))
        min = left;

    if ((right < heap.size()) && (heap[right] < heap[min]))
        min = right;

    if (min != k)
    {
        swap(heap[k], heap[min]);
        heapify(min);
    }
};

int main()
{
    ifstream fin("sort.in");
    ofstream fout("sort.out");
    int num;
    int x;
    fin >> num;
    for (int i = 0; i < num; i++)
    {
        fin >> x;
        heap.push_back(x);
    }
    for (int i = (heap.size() / 2) - 1; i >= 0; i--)
        heapify(i);
    for (int i = 0; i < num; i++)
    {
        fout << heap[0] << " ";
        swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        heapify(0);
    }

}
