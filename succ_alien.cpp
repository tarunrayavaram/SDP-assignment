#include<bits/stdc++.h>

using namespace std;

string succ_alien(string n, string B)
{
	if(B.size() > 10)
	{
		return "NOT POSSIBLE";
	}
	map<char, char> bti;
	map<char, char> itb;
	int Bsize = B.size();
	for(int i=0;i<Bsize;i++)
	{
		itb[i+48] = B[i];
		bti[B[i]] = i+48;
	}
	int N = n.size();
	string N1 = "";
	for(int i=0;i<N;i++)
	{
		N1+=bti[N[i]];
	}
	int carry = 1;
	int i=0;
	string result = "";
	while(i<N)
	{
		int r = N1[i]-48+carry;
		carry = r/Bsize;
		int rem = r%Bsize;
		result+=itb[rem];
	}
	if(carry >= 1)
	{
		result+=itb[carry];
	}
	reverse(result.begin(), result.end());
	return result;
}

int main()
{
	string n = "!@^&*";
	string B = "!@^&*";
	string s = succ_alien(n,B);
	cout << s << endl;
	return 0;
}
