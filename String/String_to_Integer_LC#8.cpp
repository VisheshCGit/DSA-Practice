#include<iostream>
#include<string>
#include<climits>
using namespace std;

int myAtoi(string s){
    int l=s.length();
    long long ans=0;
    int sign=1;
    int i=0;

    while(i<l && s[i]==' ')
        i++;

    if(i<l && (s[i]=='-' || s[i]=='+')){
        if(s[i]=='-')
            sign=-1;
        i++;
    }

    while(i<l){
        if(!isdigit(s[i]))
            break;

        ans=ans*10+(s[i]-'0');

        if(sign*ans >= INT_MAX)
            return INT_MAX;

        if(sign*ans <= INT_MIN)
            return INT_MIN;

        i++;
    }

    return sign*ans;
}

int main(){
    string s;

    cout<<"Please enter the string: ";
    getline(cin,s);

    int result=myAtoi(s);

    cout<<"Converted integer is: "<<result;

    return 0;
}