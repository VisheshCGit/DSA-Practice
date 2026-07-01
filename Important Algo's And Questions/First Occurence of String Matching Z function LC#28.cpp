#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

vector<int> zFunction(string s){
    int n=s.size();
    vector<int> z(n,0);

    int l=0,r=0; //current z-box [l...r] stores the farthest prefix match found till now

    for(int i=1;i<n;i++){

        //if current index lies inside the z-box, reuse the already computed information
        if(i<=r)
            z[i]=min(z[i-l],r-i+1); //don't go outside the current z-box

        //try extending the match beyond the current z-box
        while(i+z[i]<n && s[z[i]]==s[i+z[i]])
            z[i]++;

        //if current match goes farther than the existing z-box, update it
        if(i+z[i]-1>r){
            l=i;
            r=i+z[i]-1;
        }
    }

    return z;
}

int strStr(string haystack,string needle){

    //combine pattern and text so that every Z value represents
    //how many characters from the pattern match from that position
    string combined=needle+"#"+haystack;

    vector<int> z=zFunction(combined);
    int m=needle.size();

    //start checking only from the beginning of the text
    for(int i=m+1;i<combined.size();i++){

        //entire pattern matched
        if(z[i]==m)
            return i-(m+1); //convert combined string index into haystack index
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