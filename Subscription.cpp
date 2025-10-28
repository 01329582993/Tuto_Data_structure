#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>> t;
	while(t--){
	    float n, x;
	    cin>>n>>x;
	    if(n<6) 
	    cout<<x<<"\n";
	    else {
	        float m = ceil(n/6);
	        cout<< m * x <<"\n";
	    }
	}

}
