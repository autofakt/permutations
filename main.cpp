// Discrete Structures
// Program that takes a word input as integers and 
// calculates how many total permutations are possible.

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

unsigned factorial(unsigned n) 
{ 
    return (n==1 || n==0) ? 1: n * factorial(n - 1);  
} 

void vectorPrint(vector<unsigned> v){
    for(unsigned i = 0; i < v.size(); i++)
        cout << v[i] << " ";
        cout << endl;
}

vector<unsigned> vectorSort(vector<unsigned> v){
    vector<unsigned> temp = v;
    sort(temp.begin(),temp.end());
    return temp;
}

vector<unsigned> duplicateCounter(vector<unsigned> v){
    vector<unsigned> temp;
    vectorPrint(temp);
    for(unsigned i = 1; i<26; i++){
      if (count(v.begin(), v.end(), i) > 0){
          temp.push_back(count(v.begin(), v.end(), i));
      } 
    }
    return temp;
    
}

unsigned denominatorSum(vector<unsigned> v){
    unsigned sum = 1;
    for(unsigned i = 0; i<v.size(); i++){
    sum = sum * factorial(v[i]);
    }

    return sum;
}

unsigned mathCalculation(unsigned factoralSize, vector<unsigned> v){
    unsigned numerator = factorial(factoralSize);
    cout << "Numerator: " << numerator << endl;
    unsigned denominator = denominatorSum(v);
    cout << "Denominator: " << denominator << endl;
    return numerator/denominator;
    return 1;
}

unsigned permutations(vector<unsigned> v){
    unsigned answer = 0;
    unsigned size = v.size();    //size of original elements
    vector<unsigned> temp = v;
    temp = vectorSort(temp);
    vector<unsigned> count = duplicateCounter(temp);
    answer = mathCalculation(size, count);
    return answer;
}


int main()
{
    //vector<unsigned> v = {8,3,2,5,5,2,2,2,3,7,8};
    //vector<unsigned> v = {1,14,1,7,18,1,13,19};
    vector<unsigned> v = {1,5,5,1,5};
    vectorPrint(v);
    cout <<"Result: " << permutations(v);
    

    return 0;
}

