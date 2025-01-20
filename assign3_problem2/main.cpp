#include <bits/stdc++.h>

using namespace std;

// Structure represents an activity having start time and finish time.
struct Activity
{
    int start, finish;
    Activity(int s,int f)
    {
        start=s;
        finish=f;
    }
};

// This function is used for sorting activities according to finish time
bool Sort_activity(Activity s1, Activity s2)
{
    return (s1.finish< s2.finish);
}

/* 	Prints maximum number of activities that can
	be done by a single person or single machine at a time.
*/
void print_Max_Activities(Activity arr[], int n)
{
    // Sort activities according to finish time
	sort(arr, arr+n, Sort_activity);

	cout<< "Following activities are selected \n";

    // Select the first activity
    int i = 0;
	cout<< "(" <<arr[i].start<< ", " <<arr[i].finish << ")\n";

    // Consider the remaining activities from 1 to n-1
    for (int j = 1; j < n; j++)
    {
    	// Select this activity if it has start time greater than or equal
    	// to the finish time of previously selected activity
      	if (arr[j].start>= arr[i].finish)
      	{
			cout<< "(" <<arr[j].start<< ", "<<arr[j].finish << ") \n";
			i = j;
      	}
    }
}

// Driver program
int main()
{
    //int n;
    Activity arr[]={{3, 4}, {2, 5}, {1, 3}, {5, 9}, {0, 7}, {11, 12}, {8, 10}};
    int n =sizeof(arr)/sizeof(arr[0]);
    /*
	for(int i=0; i<=n-1; i++)
	{
		cout<<"Enter the start and end time of "<<i+1<<" activity \n";
		cin>>arr[i].start>>arr[i].finish;
    }
*/
	print_Max_Activities(arr, n);

    return 0;
}
