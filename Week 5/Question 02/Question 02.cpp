#include <iostream>
#include <vector>
# include <algorithm>


using namespace std;

vector<int> randomVector (int n, int upperBound) {
    vector<int> randomVec(n);
    for (size_t i = 0; i < n; i++) {
        randomVec[i] = rand ()% upperBound;
    }
    return randomVec;
}

int main(){
    int length;
    cout<<"Enter length of array :";
    cin>>length; // taking length as a input
    vector<int> arr = randomVector(length,1000); // generate a random array
    for(int i = 1;i<=length;i++){
        vector<int> arr1(arr.begin(),arr.begin()+i); // slice the list

        sort(arr1.begin(),arr1.begin()+i-1); // sort the list

        for(int j: arr1){
            cout<<j<<" ";
        }cout<<"    ";

        if(arr1.size()%2==1){
            cout.precision(1);
            cout << "Median: " << fixed << (double)arr1[arr1.size()/2] << endl;
        }else{
            int mid = arr1.size()/2;
            cout.precision(1);
            cout << "Median: " << fixed << (double)(arr1[mid]+arr1[mid-1])/2 << endl;
        }
    }
    return 0;
}