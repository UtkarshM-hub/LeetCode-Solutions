#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int n = A.size();
        int m = B.size();
        unordered_set<int> mp;
        
        int sum1 = 0;
        int sum2 = 0;
        
        for(int i=0; i<n; i++)
        {
            sum1 += A[i];
            mp.insert(A[i]);
        }
        
        for(int j=0; j<m; j++)
            sum2 += B[j];
        
        int diff = (sum1 - sum2)/2;
        
        for(int j=0; j<m; j++)
        {
            if(mp.find(B[j] + diff) != mp.end())
                return vector<int>{B[j]+diff, B[j]};
        }
        
        return vector<int>{};
    }
};

int main(){
    
}