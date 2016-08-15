/// g++ -g -Wall -o shell_sort main.cpp
#include <cstdlib>
#include <vector>
#include <cassert>
#include <iostream>

using namespace std;

bool swap(vector<int>& data, int index1, int index2)
{
	if (data[index1] > data[index2])
	{
		int tmp = data[index2];
		data[index2] = data[index1];
		data[index1] = tmp;
		return true;
	}
	return false;
}

void shell_sort(vector<int>& data)
{
	int iteration = data.size()/2;
	while (iteration > 0)
	{
		for (int i = 0; i < (int)data.size()-iteration; i++)
		{
			int j = i;
			while (swap(data,j,j+iteration) && j-iteration >= 0)
			{
				j -= iteration;
			}
			
		}
		iteration /= 2.2;
	}
	
}

int main(int argc, char** argv)
{
	vector<int> data;
	data.push_back(4);
	data.push_back(2);
	data.push_back(7);
	data.push_back(6);
	data.push_back(0);
	data.push_back(1);
	data.push_back(3);
	data.push_back(5);
	cout << "unsorted: ";
	for (int i = 0; i < (int)data.size(); i++)
	{
		cout << data[i] << ", ";
	}
	cout << endl;
	shell_sort(data);
	cout << "sorted: ";
	for (int i = 0; i < (int)data.size(); i++)
	{
		cout << data[i] << ", ";
	}
	cout << endl;
}


