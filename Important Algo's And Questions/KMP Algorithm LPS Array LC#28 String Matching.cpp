#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> buildLPS(string pattern){
    int n=pattern.size();
    vector<int> lps(n,0);

    int len=0; //length of current longest prefix which is also a suffix

    for(int i=1;i<n;i++){

        //if current border fails, jump to the next possible border
        while(len>0 && pattern[i]!=pattern[len])
            len=lps[len-1];

        //current character extends the existing border
        if(pattern[i]==pattern[len])
            len++;

        lps[i]=len; //store longest border length for current prefix
    }

    return lps;
}

int strStr(string haystack,string needle){

    if(needle.empty())
        return 0;

    vector<int> lps=buildLPS(needle);

    int i=0,j=0; //i -> text pointer, j -> pattern pointer

    while(i<haystack.size()){

        if(haystack[i]==needle[j]){
            i++;
            j++;
        }

        //entire pattern matched
        if(j==needle.size())
            return i-j;

        //mismatch after some matches
        else if(i<haystack.size() && haystack[i]!=needle[j]){

            //don't restart from beginning, jump to next valid border
            if(j!=0)
                j=lps[j-1];
            else
                i++; //nothing matched, move to next text character
        }
    }

    return -1;
}

int main(){

    string haystack,needle;

    cout<<"Enter Haystack : ";
    cin>>haystack;

    cout<<"Enter Needle : ";
    cin>>needle;

    int index=strStr(haystack,needle);

    if(index==-1)
        cout<<"Pattern Not Found";
    else
        cout<<"Pattern Found At Index : "<<index;

    return 0;
}