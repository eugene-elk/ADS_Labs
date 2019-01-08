#include <iostream>
#include <vector>
#include <fstream>

int heap[100002];

using namespace std;

int n;

void heapy(int tmp)
{
    int max = tmp, left = 2 * tmp + 1, right = tmp * 2 + 2;

    //left >= n ? left = tmp : 1;
    //right >= n ? right = tmp : 1;

    if ((left <= n) && (heap[left] > heap[max])) {
        max = left;
    }
    if ((right <= n) && (heap[right] > heap[max])) {
        max = right;
    }
    if (max != tmp) {
        swap(heap[max], heap[tmp]);
        heapy(max);
    }
}

int main() {
    vector<int> answer;
    ifstream in("sort.in");
    ofstream out("sort.out");

    in >> n;
    for (int i = 0; i < n; i++) {
        in >> heap[i];
    }
    for (int i = (n / 2 -1); i >= 0; i--) {
        heapy(i);
    }

    for (int i = 0; i < n; i++) {
        answer.push_back(heap[0]);
        heap[0] = -1000000001;
        heapy(0);
    }
    for (int i = n-1; i >= 0; i--)
    {
        out << answer[i] << " ";
    }
    return 0;
}
