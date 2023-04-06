#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <chrono>

using namespace std;
using namespace std::chrono;

int partition(vector<int>& lst,int start, int end){
    int pivot = lst[end];
    int partitionIndex = start;
    for(int i = start;i<end;i++){
        if(lst[i]<=pivot){
            swap(lst[i],lst[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(lst[partitionIndex],lst[end]);
    return partitionIndex;
}

void quickSort(vector<int>& lst, int start, int end){
    if(start < end){
        int partitionIndex = partition(lst,start,end);
        quickSort(lst, start, partitionIndex-1);
        quickSort(lst, partitionIndex+1,end);
    }
}

void iterativeQuickSort(vector<int>& lst, int start, int end){
    stack<int> stack;
    stack.push(start);
    stack.push(end);
    while(!stack.empty()){
        end = stack.top();
        stack.pop();
        start = stack.top();
        stack.pop();
        int partitionIndex = partition(lst, start, end);

        if (partitionIndex - 1 > start) {
            stack.push(start);
            stack.push(partitionIndex - 1);
        }

        if (partitionIndex + 1 < end) {
            stack.push(partitionIndex + 1);
            stack.push(end);
        }
    }
}

vector<int> randomVector (int n, int upperBound) {
    vector<int> randomVec(n);
    for (size_t i = 0; i < n; i++) {
        randomVec[i] = rand ()% upperBound;
    }
    return randomVec;
}

int main(){

    vector<int> lst1 = randomVector(30000,100000);
    vector<int> lst2 = lst1;
    cout<<lst1.size()<<endl;

    auto start1 = high_resolution_clock::now();
    quickSort(lst1,0,lst1.size()-1);
    auto stop1 = high_resolution_clock::now();
    auto duration1 = duration_cast<microseconds>(stop1-start1);
    cout<<"Time for Recursive :"<<duration1.count()<<endl;

    auto start2 = high_resolution_clock::now();
    iterativeQuickSort(lst2,0,lst2.size()-1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2-start2);
    cout<<"Time for Iterative :"<<duration2.count()<<endl;

    return 0;
}