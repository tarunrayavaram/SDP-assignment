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
	string n1 = "";
	for(int i=0;i<N;i++)
	{
		n1+=bti[n[i]];
	}
	int carry = 1;
	int i=N-1;
	string result = "";
	while(i>=0)
	{
		int r = n1[i]-48+carry;
		carry = r/Bsize;
		int rem = r%Bsize;
		result+=itb[rem+48];
		i--;
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
