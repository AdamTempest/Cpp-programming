#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int possiblePairs(int num){
        if (num == 1){
            return num;
        }
        return num + possiblePairs(num-1);
    }

    vector<int> findClosestPair(vector<int>& v,int c){
        int id = 0;
        int sml=10;
        vector<int> z;

        for (int i=0;i<c;i++){
            for (int j=i+1;j<c;j++){
                if (v[i]>v[j]){
                    if (v[i] - v[j] < sml){
                        z = {v[j],v[i]};
                    }
                } else {
                    if (v[j] - v[i] < sml){
                        z = {v[i],v[j]};
                    }
                }
            }
        }
        
        return z;
    }

    bool isPrime(int num){
        int n=num-1;
        int c=0;
        while (n>1){
            if (num % n == 0){
                c+=1;
            };
            n-=1;
        }
        return (c == 0);
    }

    vector<int> closestPrimes(int left, int right) {
        
        int c=0;
        vector<int> v = {-1,-1};

        for (int i=left;i<=right;i++){
            if (isPrime(i)){
                v[c] = i;
                c += 1;
            }
        }

        if (c==1){
            return {-1,-1};
        } 
        else if (c > 2){
            v = findClosestPair(v,c);
        }

        return v;
    }
};

void printVector(vector<int>& v){
    cout << "{ ";
    for(int i=0;i<v.size();i++){
        cout << v[i] << " ";
    }
    cout << "}"<< endl;
}

int main(){
    Solution a;
    int left = 10;
    int right = 19;
    vector<int> result = a.closestPrimes(left,right);
    cout << "Input: [ " <<left<< ", "<<right <<" ]"<< endl; 
    cout << "Output: [ ";
    for (auto i=result.begin();i!=result.end();i++){
        cout << *i<< " ";
    }
    cout << "]"<< endl;

    cout << "Possible pairs for 6 elements: " << a.possiblePairs(5) << endl;
    cout << "Possible pairs for 7 elements: " << a.possiblePairs(6) << endl;
    cout << "Possible pairs for 8 elements: " << a.possiblePairs(7) << endl;
    cout << "Possible pairs for 9 elements: " << a.possiblePairs(8) << endl;

    vector<int> cd = {26, 39, 33, 30};
    vector<int> res = a.findClosestPair(cd,4);
    cout << "Closest pair in [26, 39, 33, 30] = ";
    printVector(res);

    return 0;
}