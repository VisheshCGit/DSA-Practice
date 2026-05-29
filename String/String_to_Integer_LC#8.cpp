#include<iostream>
#include<string>
#include<climits>
using namespace std;

int myAtoi(string s) {
        int l=s.length();
        long long ans=0;
        int sign=1;
        bool started=false;
       for(int i=0; i<l; i++){
        if(!started && s[i]==' ')
           continue;
        if(!started && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-')
            sign=-1;
           started=true;
           continue;
        }
        if(!isdigit(s[i]))
        break;
        else{
            started=true;
              ans=ans*10+(s[i]-'0');

            if(sign*ans >= INT_MAX)
                return INT_MAX;

            if(sign*ans <= INT_MIN)
                return INT_MIN;
        }
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