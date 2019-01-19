#include<iostream>
#include<string>
#include<map>
using namespace std;

map<int,int> keyMapping;

void setPermutation(string key)
{
	for(int i=0;i<key.length();++i)
		keyMapping[key[i]] = i;
}

string encrypt(string msg,string key)
{
	int row,col,j;
	string cipher = "";

	col = key.length();

	row = msg.length()/col;
	if(msg.length()%col)
		row+=1;

	char matrix[row][col];

	for(int i=0,k=0;i<row;++i)
	{
		for(int j=0;j<col;)
		{
			if(msg[k] == '\0')
			{
				matrix[i][j] = 'X';
				j++;
			}
			matrix[i][j] = msg[k];
			j++;k++;
		}
	}

	for(map<int,int>::iterator i = keyMapping.begin();i!=keyMapping.end();++i)
	{
		j=i->second;

		for(int i=0;i<row;++i)
		{
			cipher +=matrix[i][j];
		}
	}

	return cipher;
}

string decrypt(string cipher,string key)
{
	int col = key.length();

	int row = cipher.length()/col;
	char Matrix[row][col];

	for(int j=0,k=0;j<col;++j)
		for(int i=0;i<row;++i)
			Matrix[i][j] = cipher[k++];
	int index =0;
	for(map<int,int>::iterator i=keyMapping.begin();i!=keyMapping.end();++i)
		i->second = index++;

	char decipher[row][col];
	map<int,int>::iterator i=keyMapping.begin();
	int k=0;
	for(int l=0,j;key[l]!='\0';k++)
	{
		j = keyMapping[key[l++]];
		for(int i=0;i<row;++i)
			decipher[i][k] = Matrix[i][j];
	}

	string msg ="";

	for(int i=0;i<row;++i)
		for(int j=0;j<col;++j)
			msg += decipher[i][j];

	return msg;	

}

int main(void) 
{ 
    string msg = "",key1 = "great",key2 = "great";  
    
  	cout<<"Enter the keys:";
  	cin>>key1>>key2;

  	cout<<"\nEnter Message: ";
  	cin>>msg;

    setPermutation(key1); 
    string cipher = encrypt(msg,key1);

    keyMapping.clear();
    setPermutation(key2);
    cipher = encrypt(cipher,key2);

    cout << "Encrypted Message: " << cipher << endl; 
    
    keyMapping.clear();
    setPermutation(key2);
    cipher = decrypt(cipher,key2);
    keyMapping.clear();
    setPermutation(key1);
    cout << "Decrypted Message: " << decrypt(cipher,key1) << endl; 
  
    return 0; 
} 