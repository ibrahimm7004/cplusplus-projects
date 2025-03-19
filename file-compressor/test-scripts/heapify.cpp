#include<iostream>
using namespace std;

int l(int subtree_root_index)
{
	return 2*subtree_root_index + 1;
}

int r(int subtree_root_index)
{
	return 2*subtree_root_index + 2;
}

void heapify(int array_in[], int array_size, int subtree_root_index)
{
	int largest_value = subtree_root_index;
    int left = l(subtree_root_index);
    int right = r(subtree_root_index);
    
    if (left < array_size && array_in[left] > array_in[largest_value])	
		largest_value = left; 
    if (left < array_size && array_in[left] > array_in[largest_value])	
		largest_value = left; 
    if (right < array_size && array_in[right] > array_in[largest_value])   
		largest_value = right; 
    if (largest_value != subtree_root_index )
    	swap(array_in[subtree_root_index], array_in[largest_value]);
    if (largest_value != subtree_root_index )
	{
		swap(array_in[subtree_root_index], array_in[largest_value]);
	    heapify(array_in, array_size, subtree_root_index);
	}
	
}

void construct_heap(int array_in[], int array_size)
{
	int last_non_leaf_node = (array_size/2) -1;
	
	for (int subtree_root_index = last_non_leaf_node; subtree_root_index >=0; subtree_root_index-=1)
		heapify(array_in, array_size, subtree_root_index);
}

void print_heap(int array_in[], int array_size)
{
  cout << "Printing values at each node in heap" << endl;
  for (int index = 0; index < array_size; index+=1)	cout<< array_in[index] << endl;
}

int main()
{
	int a[10] = {2,14,6,8,4,1,0,56,2,5};
	
	int array_size = 10;
	
	construct_heap(a, array_size);
	print_heap(a, array_size);
	
	return 0;                                                                                                             
}