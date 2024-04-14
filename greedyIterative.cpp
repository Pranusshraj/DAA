#include<iostream>
#include<set>
using namespace std;

set<int> Greedy_Activity_Selector(int S[],int s[],int f[],int n) {
	set<int> A;
  	A.insert(S[0]);
 	int k = 0,count=1;
 	for(int m=1;m<n;m++) {
  		if(s[m] >= f[k]) {
	   		A.insert(S[m]);
   			k = m;
  		}
 	}
 	return A;
}


void sortFinishTime(int S[],int s[], int f[], int n) {
	for(int i=0;i<n-1;i++) {
     		for(int j=0;j<n-i-1;j++) {
   			if(f[j] > f[j+1]) {
				swap(f[j],f[j+1]);
				swap(S[j],S[j+1]);
				swap(s[j],s[j+1]);
   			}
  		}
 	}

	cout << "\n\nAFTER SORTING\n";
	cout << "Activity No. \t: [\t";
 	for(int i=0;i<n;i++) {
	  	cout << S[i] << "\t";
 	}
 	cout << "]" << endl;

	cout << "Start Time \t: [\t";
 	for(int i=0;i<n;i++) {
  		cout << s[i] << "\t";
 	}	
	cout << "]" << endl;

 	cout << "Finish Time \t: [\t";
 	for(int i=0;i<n;i++) {
  		cout << f[i] << "\t";
 	}
  	cout << "]" << endl;
}

int main() {
	int n;
	cout << "Total No. of Activities : ";
 	cin >> n;
 	int S[n],s[n],f[n];
	
	cout << "\nStarting Time Array : " << endl;
	for(int i=0;i<n;i++) {
		S[i] = i+1;
		cin >> s[i];
 	}
	cout << "\nFinishing Time Array : " << endl;
	for(int i=0;i<n;i++) {
		cin >> f[i];
 	}

	sortFinishTime(S,s,f,n);

 	cout<<"\n\nActivity Order : [ ";
 	set<int>A = Greedy_Activity_Selector(S,s,f,n);
	set<int>::iterator itr;
	for(itr = A.begin(); itr != A.end(); itr++) {
  		cout << *itr << " ";
 	}
 	cout << "]" << endl;
	return 0;
}
