#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void permute(string a, int l, int r)
{
    // Base case
    if (l == r)
        cout<<a<<endl;
    else
    {
        // Permutations made
        for (int i = l; i <= r; i++)
        {
 
            // Swapping done
            swap(a[l], a[i]);
 
            // Recursion called
            permute(a, l+1, r);
 
            //backtrack
            swap(a[l], a[i]);
        }
    }
}
 
// Driver Code
int main()
{
    string str;
    int n;
    cout << "Enter size: ";
    cin>>n;
    
    
    cout << "Enter elements: ";
    cin>>str;
    
    n = str.size();
    permute(str, 0, n-1);
    return 0;
}



