#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) 
    {
        for(int i=0;i<arr.size();i++)
        {
            for(int j=i+1;j<arr.size();j++)
            {
                if(arr[i]==2*arr[j]||arr[i]*2==arr[j])
                {
                    return true;
                }
            }
        }
        return false;
    }
};

int main(){
    
}