    #include <iostream>
    #include<string>
    using namespace std;
     
    int main() {
    	// your code goes here
    	string str;int count[256] ={0};
    	cin>>str;
    	for(int i=0;i<str.length();++i)
    		count[str[i]]++;
    	for(int i=65;i<=90;++i)
    		cout<<count[i]<<" ";
    	return 0;
    }
