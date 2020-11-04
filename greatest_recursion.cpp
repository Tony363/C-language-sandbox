#include <iostream>
#include <cstdio>
#include<array>
using namespace std;

/*
 * Add `int max_of_four(int a, int b, int c, int d)` here.
 * */
int max_of_four(array<int,4> vector,int count,int greatest){
	if (vector.size() == count){
		//cout << vector.size() << count << endl;
		return greatest;
	}
	if (vector[count] > greatest){
		greatest = vector[count];
		//cout << greatest << endl;
		count++;
		return max_of_four(vector,count,greatest);
	}
	else{
		count++;
		return max_of_four(vector,count,greatest);
	}
}

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;
	array<int,4> vector{a,b,c,d};	
//	for(int i=0;i<vector.size();i++){
//		cout << i << vector[i] << endl;
//	}
	int count=0,greatest=0;
	int ans = max_of_four(vector,count,greatest);
	cout << ans << endl;
	return 0;
}
