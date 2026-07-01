#include<iostream>
#include<string>
using namespace std;

int compareVersion(string version1,string version2){

    int i=0,j=0;

    while(i<version1.size() || j<version2.size()){

        int num1=0,num2=0;

        //read one revision from version1
        while(i<version1.size() && version1[i]!='.'){
            num1=num1*10+(version1[i]-'0');
            i++;
        }

        //read one revision from version2
        while(j<version2.size() && version2[j]!='.'){
            num2=num2*10+(version2[j]-'0');
            j++;
        }

        //compare current revisions
        if(num1>num2)
            return 1;

        if(num1<num2)
            return -1;

        //skip '.' and move to next revision
        if(i<version1.size())
            i++;

        if(j<version2.size())
            j++;
    }

    return 0;
}

int main(){

    string version1,version2;

    cout<<"Enter Version 1 : ";
    cin>>version1;

    cout<<"Enter Version 2 : ";
    cin>>version2;

    int ans=compareVersion(version1,version2);

    if(ans==1)
        cout<<"Version 1 is Greater";
    else if(ans==-1)
        cout<<"Version 2 is Greater";
    else
        cout<<"Both Versions are Equal";

    return 0;
}