#include <iostream>
#include <string>
#include <cctype>
#include <cassert>
using namespace std;

int appendToAll(string a[], int n, string value)
{
	if (n < 0)
		return -1;
	for (int x = 0; x < n; x++)
		a[x] += value;
	return n;
}

int lookup(const string a[], int n, string target)
{
	if (n < 0)
		return -1;
	for (int y = 0; y < n; y++)
		if (a[y] == target)
			return y;
	return -1;
}

int positionOfMax(const string a[], int n)  
{
	if (n <= 0)
		return -1;
	for (int z = 0; z < n; z++)
		for (int q = z; q < n; q++)
		{
			if (a[z] >= a[q])
			{
				if (q == n - 1)
					return z;
				else
					continue;
			}
			else
				break;
		}	
}
int rotateLeft(string a[], int n, int pos)
{
	if (n < 0 || pos >= n)
		return -1;
	string word = a[pos];
	for (int r = pos; r < n - 1; r++)
		a[r] = a[r + 1];
	a[n - 1] = word;
	return pos;
}
int countRuns(const string a[], int n)
{
	if (n < 0)
		return -1;
	int consCount = 0;
	for (int s = 0; s < n; s++)
	{
		if (s < n - 1 && a[s] == a[s + 1])
			continue;
		else
			consCount += 1;
	}
	return consCount;
}

int flip(string a[], int n)
{
	if (n < 0)
		return -1;
	string keepString;
	for (int t = 0; t < n/2; t++)
	{
		keepString = a[t];
		a[t] = a[n - 1 - t];
		a[n - 1 - t] = keepString;
	}
	return n;
}

int differ(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0)
		return -1;
	int shorter;
	if (n1 < n2)
		shorter = n1;
	else if (n2 < n1)
		shorter = n2;
	else
		shorter = n1;
	for (int u = 0; u < shorter; u++)
		if (a1[u] != a2[u])
			return u;
	return shorter;
}

int subsequence(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0 || n2 > n1)
		return -1;
	else if (n2 == 0)    
		return 0;  
	
	for (int v = 0; v < n1; v++)
	{
		if (a1[v] == a2[0])
			for (int w = 0; w < n2; w++)
			{
				if (v + n2 > n1)
					return -1;
				else if (a1[v + w] == a2[w])
				{
					if (w == n2 - 1)
						return v;
					else
						continue;
				}
				else
					break;
			}	
	}
	return -1;
}

int lookupAny(const string a1[], int n1, const string a2[], int n2)
{
	if (n1 < 0 || n2 < 0) 
		return -1;
	for (int i = 0; i < n1; i++)
		for (int j = 0; j < n2; j++)
			if (a1[i] == a2[j])
				return i;
	return -1;
}

int split(string a[], int n, string splitter)
{
	if (n < 0)
		return -1;
	int lowerString = 0;
	int equalString = 0;
	int higherString = 0;
	string largeString;
	for (int k = 0; k < n; k++)//count equals, highers, and lowers
		if (a[k] == splitter)
			equalString += 1;
		else if (a[k] > splitter)
			higherString += 1;
		else if (a[k] < splitter)
			lowerString += 1;
	for (int l = 0; l < equalString; l++)//only do this equalString times
		for (int m = 0; m < n; m++)//loop through array
			if (a[m] == splitter)//check if string is equal to splitter
			{
				for (int o = m; o < n - 1; o++)
				{
					a[o] = a[o + 1];//if it is, shift everything to the right of it left and copy it to the end
				}
				a[n - 1] = splitter;
				break;
			}
	for (int f = 0; f < higherString; f++)	//repeat with higherString
		for (int g = 0; g < n; g++)
			if (a[g] > splitter)
			{
				largeString = a[g];
				for (int e = g; e < n - 1; e++)
				{
					a[e] = a[e + 1];
				}
				a[n - 1] = largeString;
				break;
			}
	if (lowerString < n)
		return lowerString;
	else
		return n;
	
}

int main()
{

	string a[] = { " hi", " ho", " wazzap", " bird" };
	string ab[] = { " hi buddy", " ho buddy", " wazzap buddy", " bird" };
	assert(appendToAll(a, -1, " buddy") == -1);
	appendToAll(a, 3, " buddy");
	cout << a[0] << a[1] << a[2] << a[3] << endl;
	assert(lookup(a, 4, " bird") == 3);
	assert(lookup(a, 4, "jk") == -1);
	string h[7] = { "bernie", "hillary", "donald", "jeb", "", "carly", "ben" };
	assert(lookup(h, 7, "carly") == 5);
	assert(lookup(h, 7, "donald") == 2);
	assert(lookup(h, 2, "donald") == -1);
	assert(positionOfMax(h, 7) == 3);

	string g[4] = { "bernie", "hillary", "jeb", "carly" };
	assert(differ(h, 4, g, 4) == 2);
	assert(appendToAll(g, 4, "?") == 4 && g[0] == "bernie?" && g[3] == "carly?");
	assert(rotateLeft(g, 4, 1) == 1 && g[1] == "jeb?" && g[3] == "hillary?");
	
	string e[4] = { "donald", "jeb", "", "carly" };
	assert(subsequence(h, 7, e, 4) == 2); 
	string d[5] = { "hillary", "hillary", "hillary", "ben", "ben" };
	assert(countRuns(d, 5) == 2);
	string f[3] = { "jeb", "donald", "marco" };
	assert(lookupAny(h, 7, f, 3) == 2);
	assert(flip(f, 3) == 3 && f[0] == "marco" && f[2] == "jeb");

	assert(split(h, 7, "carly") == 3);
	cout << h[0] << h[1] << h[2] << h[3] << h[4] << h[5] << h[6] << endl;
	cout << "All tests succeeded" << endl;
}