#include<bits/stdc++.h>

using namespace std;

/*string convert_to_b(string n, map<char, char> itb)
{
	string n1 = "";
	int N = n.size();
        for(int i=0;i<N;i++)
        {
                n1+=itb[n[i]];
        }
	return n1;
}

string convert_to_i(string b, map<char, char> bti)
{
        string b1 = "";
        int B = b.size();
        for(int i=0;i<B;i++)
        {
                b1+=bti[b[i]];
        }
        return b1;
}*/

string convert_to(string nb, map<char, char> mp)
{
        string nb1 = "";
        int NB = nb.size();
        for(int i=0;i<NB;i++)
        {
                nb1+=mp[nb[i]];
        }
        return nb1;
}

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
	string n1 = convert_to(n,bti);
	int carry = 1;
	int i=N-1;
	string result = "";
	while(i>=0)
	{
		int r = n1[i]-48+carry;
		carry = r/Bsize;
		int rem = r%Bsize;
		result+=rem+48;
		i--;
	}
	if(carry >= 1)
	{
		result+=itb[carry];
	}
	reverse(result.begin(), result.end());
	result = convert_to(result,itb);
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
