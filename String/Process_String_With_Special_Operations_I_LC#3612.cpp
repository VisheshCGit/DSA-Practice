#include<iostream>
#include<string>
#include<algorithm>
#include<cctype>
using namespace std;

string processString(string str){

    string answer;

    for(char ch : str){

        if(isalpha(ch)){

            answer.push_back(ch); // add alphabet character

        }
        else if(ch=='*'){

            if(!answer.empty())
                answer.pop_back(); // remove last character
        }
        else if(ch=='#'){

            answer.append(answer); // duplicate current string
        }
        else{

            reverse(answer.begin(),answer.end()); // reverse current string
        }
    }

    return answer;
}

int main(){

    string str;

    cout<<"Please enter string: ";
    cin>>str;

    cout<<"Processed String: "<<processString(str);

    return 0;
}