#include "stdafx.h"
#include <iostream>
using namespace std;
#define SIZE 20

int C[SIZE][SIZE];  
int d[SIZE], v[SIZE];  

int main()
{
	int minindex, min;
	int N, E;         
	cin >> N >> E;
	int MAX = 0;       
	int a;
	cin >> a;   
	int v1, v2, b;
	int temp;
	for (int i = 0; i < E; i++)
	{
		cin >> v1 >> v2 >> b;
		C[v1][v2] = b;
		C[i][i] = 0;
	}

	for (int i = 0; i<N; i++) {
		d[i] = 10000;
		v[i] = 1;
	}
	d[0] = a;  

	do {
		minindex = 10000;
		min = 10000;
		for (int i = 0; i<N; i++) {
			if ((v[i] == 1) && (d[i]<min)) {
				min = d[i];
				minindex = i;
			}
		}
		if (minindex != 10000) {
			for (int i = 0; i<N; i++) {
				if (C[minindex][i] > 0) {
					temp = min + C[minindex][i];
					if (temp < d[i])
						d[i] = temp;
				}
			}
			v[minindex] = 0;
		}
	} while (minindex < 10000);
	for (int i = 0; i<N; i++)
		cout << d[i] << " ";
	cout << endl;
	system("pause");
	return 0;
}
