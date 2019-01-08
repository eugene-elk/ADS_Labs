#include<iostream>
#include<fstream>
#include<vector>

using namespace std;

vector <int> a;

int kth_order_statistics(int n, int k)
{
    int left = 0;
    int right = n;
	while(true)
	{
		if (right <= left + 1)
		{
			if (a[right] < a[left])
				swap(a[left], a[right]);
			return a[k];
		}

		int mid = (left + right) / 2;
		swap(a[mid], a[left + 1]);
		if (a[left] > a[right])
			swap(a[left], a[right]);
		if (a[left + 1] > a[right])
			swap(a[left + 1], a[right]);
		if (a[left] > a[left + 1])
			swap(a[left], a[left + 1]);

		int i = left + 1;
		int j = right;
		int cur = a[left + 1];
		while(true)
		{
		    i++;
			while (a[i] < cur) i++;
            j--;
			while (a[j] > cur) j--;
			if (i > j) break;
			swap(a[i], a[j]);
		}

		a[left + 1] = a[j];
		a[j] = cur;

		if (j >= k)
			right = j - 1;
		if (j <= k)
			left = i;

	}
}

int main()
{
    ifstream fin("kth.in");
    ofstream fout("kth.out");

	int n, k;
	int A, B, C;
	int x, y;
	fin >> n >> k;
	fin >> A >> B >> C;
	fin >> x >> y;
	a.push_back(x);
	a.push_back(y);
	for (int i = 2; i < n; i++)
    {
        x = A * a[i - 2] + B * a[i - 1] + C;
		a.push_back(x);
    }
	kth_order_statistics(n-1, k-1);
	fout << a[k-1];
	return 0;
}
