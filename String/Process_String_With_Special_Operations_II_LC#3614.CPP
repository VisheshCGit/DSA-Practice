#include<iostream>
#include<vector>
#include<string>
#include<cctype>
using namespace std;

char processString(string s,long long k){

    int n=s.size();
    vector<long long> len(n);
    long long currentLength=0;

    for(int i=0;i<n;i++){

        if(islower(s[i])){
            currentLength=min(currentLength+1,(long long)1e18);
        }
        else if(s[i]=='*'){
            if(currentLength>0)
                currentLength--;
        }
        else if(s[i]=='#'){
            currentLength=min(currentLength*2,(long long)1e18);
        }

        len[i]=currentLength;
    }

    if(k>=currentLength)
        return '.';

    for(int i=n-1;i>=0;i--){

        long long previousLength=(i==0?0:len[i-1]);

        if(islower(s[i])){

            if(k==previousLength)
                return s[i];
        }
        else if(s[i]=='#'){

            if(previousLength>0 && k>=previousLength)
                k-=previousLength;
        }
        else if(s[i]=='%'){

            k=len[i]-1-k;
        }
    }

    return '.';
}

int main(){

    string s;
    long long k;

    cout<<"Enter string: ";
    cin>>s;

    cout<<"Enter k: ";
    cin>>k;

    cout<<"Answer: "<<processString(s,k);

    return 0;
}