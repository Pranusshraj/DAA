#include<iostream>
#include<fstream>
#include<stdlib.h>
#include<time.h>
#include<limits.h>
#include<math.h>
using namespace std;

int A[10000],n,count;

struct subarray {
	int low;
	int high;
	int sum;
};

//------------------------------------------------------------------------------------------------

void genInputFile() {
	ofstream fout("input_maxSubarray.txt");
	srand((long int) clock());
	for(int i=0 ; i<10000 ; i++) {
		int num = rand() % 30;
		if(rand()%2 == 0)
			fout << -1*num << "\t";
		else
			fout << num << "\t";
	}
	fout.close();
}

void getInput() {
	cout << "\n\nEnter the size of the array : ";
	cin >> n;
	ifstream fin("input_maxSubarray.txt");
	for(int i=0 ; i<n ; i++) {
		fin >> A[i];
	}
	fin.close();
}

void writeOutput(subarray result) {
	cout << "Lower bound = " << result.low+1;
	cout << "\nHigher bound = " << result.high+1;
	cout << "\nMaximum sum = " << result.sum;
	cout << "\nCount = " << count;
}

//------------------------------------------------------------------------------------------------

subarray FIND_MAX_CROSS_SUBARRAY(int low,int mid,int high) {
    int sum = 0;
    int max_left = mid;  
    int max_right = mid;
	// base case : the maximum subarray is the middle element itself
    
    int left_sum = INT_MIN;
    for(int i = mid; i >= low; i--) {
        count++;
        sum += A[i];
        if(sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    
    sum = 0;
    int right_sum = INT_MIN;
    for(int i = mid+1; i <= high; i++) {
        count++;
        sum += A[i];
        if(sum > right_sum) {
            right_sum = sum;
            max_right = i;
        }
    }
    
    subarray result;
    result.low = max_left;
    result.high = max_right;
    result.sum = left_sum + right_sum;
    
    return result;
}

subarray FIND_MAX_SUBARRAY(int low,int high) {
	if(low == high) {
		subarray result;
		result.low = low;
		result.high = high;
		result.sum = A[low];
		
		return result;
	}
	
	else {
		int mid = floor((low+high)/2);
		subarray left = FIND_MAX_SUBARRAY(low,mid);
		subarray right = FIND_MAX_SUBARRAY(mid+1,high);
		subarray cross = FIND_MAX_CROSS_SUBARRAY(low,mid,high);
		
		if(left.sum >= right.sum && left.sum >= cross.sum) {
			return left;
		}
		else if(right.sum >= left.sum && right.sum >= cross.sum) {
			return right;
		}
		else {
			return cross;
		}
	}
}

//------------------------------------------------------------------------------------------------

int main() {
	genInputFile();
	do {
		getInput();
		count = 0;
		subarray result = FIND_MAX_SUBARRAY(0,n-1);
		writeOutput(result);
	}while(true);
}