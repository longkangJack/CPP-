#include <iostream>
#include <vector>
using namespace std;
//��������
void InsertSort(int array[],int size)
{
	for (int i = 1; i < size; i++)
	{
		int key = array[i];
		int end = i- 1;
		while (end >= 0 && key < array[end])
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
}
//ϣ������
void ShellSort(int array[],int size)
{
	int gap = 3;
	while (gap > 0)
	{
		for (int i = gap; i < size; i+=gap)
		{
			int key = array[i];
			int end = i - gap;
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
		gap--;
	}
}
//ѡ������
void SelectSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxpos = 0;
		for (int j = 1; j < size - i; j++)
		{
			if (array[maxpos] < array[j])
			{
				maxpos = j;
			}
		}
		if (maxpos != size - i-1)
		{
			/*int tmp = array[maxpos];
			array[maxpos] = array[size - i - 1];
			array[size - i - 1] = tmp;*/
			swap(array[maxpos], array[size - i - 1]);
		}

	}
}
//ð������
void BubbleSort(int array[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap(array[j], array[j + 1]);
			}
		}
	}
}
//����
//�ӵ�����һ����Ҷ�ӽڵ㿪ʼ����(size-2)/2
//����
void HeapAdjust(int array[], int size, int parent)
{
	int child = parent * 2 + 1;//����
	while (child < size)
	{
		if (child + 1 < size && array[child] < array[child + 1])
		{
			child += 1;
		}
		if (array[child] > array[parent])
		{
			swap(array[child], array[parent]);
			parent = child;//����˫��λ�� �������µ���
			child = parent * 2 + 1;		
		}
		else
		{
			/*parent--;
			child = parent * 2 + 1;*/
			return;
		}
	}
}
void HeapSort(int array[],int size)
{
	//1.����
	int root = (size - 2) / 2;
	for(root;root>=0;root--)
	HeapAdjust(array, size, root);
	//2.����
	int end = size - 1;
	while (end)
	{
		swap(array[0], array[end]);
		HeapAdjust(array, end, 0);//�����Ǹ�λ�ô��Ǹ�λ�õ�Ԫ���±�
		end--;
	}	
}
int main()
{
	int arr[] = { 9,1,2,5,7,4,8,6,3,5};
	//InsertSort(arr, sizeof(arr) / sizeof(arr[0]));
	//ShellSort(arr, sizeof(arr) / sizeof(arr[0]));
	//SelectSort(arr, sizeof(arr) / sizeof(arr[0]));
	//BubbleSort(arr, sizeof(arr) / sizeof(arr[0]));
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (auto& e : arr)
		cout << " " << e;
	cout << endl;
	return 0;
}