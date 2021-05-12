//Dynamic programming approach of finding The Longest Increasing Subsequence
//Algorithm Time Complexity = O(n^2) 
//Approach - Dynamic programming with time complexity O(n^2)


#include<iostream>
#include <vector>
#include <cmath>
#include <algorithm> //in order for max funtion to be used;

using namespace std;
void write_vector(vector<int>& V)			//the ordinary function for printing the vector
{
	cout << endl;
	for (int i = 0; i < V.size(); i++)
		cout << V[i] << " ";
}
vector<int> lis(vector<int> const& a)			//Dynamic Programming approach of getting LIS with O(n^2) titme complexity
{
	int n = a.size();				//getting the size of the array 
	vector<int> check(n, 1), hold(n, -1);		// restoring the subsequence we generate an additional auxiliary array p[0…n?1]/additional one to hold items
	for (int i = 0; i < n; i++)				//compuing alongside the array check[]. hold[i] will be the index j and hold[i] follwoing thru the computation of d[j]
	{										//of the second last element in the longest increasing subsequence ending in i.
		for (int j = 0; j < i; j++)			
		{
			if (a[j] < a[i] && check[i] < check[j] + 1)
			{
				check[i] = check[j] + 1;
				hold[i] = j;
			}
		}
	}
	//in the for loop originally assign the ancestors with hold[i]=?1 and check[i] = 1;
	int ans = check[0], pos = 0; //declaring answer plus a position 
	for (int i = 1; i < n; i++)
	{
		if (check[i] > ans)
		{
			ans = check[i];
			pos = i;	//getting it 
		}
	}

	vector<int> subseq;
	while (pos != -1)						//while the position is = -1
	{
		subseq.push_back(a[pos]);			// pushing the elements 
		pos = hold[pos];
	}
	reverse(subseq.begin(), subseq.end());  //then reversing the order since we have started from the end till the beggining
	return subseq;							//returning the subsequence
}


int main()
{
	int n;													//declaring n - number of elements we want to input
	int a;													//declaring a - the elements itself, to input
	vector <int> sequence;									//vector possesing these elements
	cout << "Enter number of elements in the sequence: ";   //enter the number of elemets
	cin >> n;
	cout << "Enter elements separated by space: ";			//entering the elements in the array/vector

	for (int i = 0; i < n; i++)
	{
		cin >> a;											//inputting elements
		sequence.push_back(a);								//posses them already
	}

	cout << "The elements in the LIS are: ";				//printing statement, saying about the LIS
	
	vector<int> subs = lis(sequence);						//information 
	int Size = subs.size();									//geting its size in order to be printed

	write_vector(subs);										//printing statements - the LIS values 	
	cout << "\nSize: " << Size;								//printing statement - it size

	return 0;
}
