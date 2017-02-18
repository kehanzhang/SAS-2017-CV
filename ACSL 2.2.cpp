#include<iostream>
#include<string>
#include<stdlib.h>
/*****************************
*    Kehan Zhang             *
*    2/8/2017                *
*    Enloe HS                *
*    Contest #2              *
*    Int - 5                 *
*****************************/

using namespace std;

int main(){
    for(int f = 0; f < 5; f++){
    string input;
    getline(cin, input);
    int first = int(input[0]) - 48;
    if(input.length() < first){ //Tests if string has enough values to loop according to prompt
        cout<<"Error: invalid string"<<endl;
    }
    else if(atoi(input.substr(1, first).c_str()) == 0){ //tests if first outputted answer is zero
        cout<<"Error: cannot lead with zero"<<endl;
    }
    else{
    string real = input.substr(1, first);
    for(int i = input.length(); i > first; i--){
        real = real + input[i];
    }
    real.erase(first,1);
    //***********************formated properly real
    int temp = 0;
    int start = 0;
    int outputn = 0;
    int adv = 0;
    int reall = real.length();
    string output;
    do{
        output = real.substr(start, first+ adv);
        outputn = atoi(output.c_str());
        if(outputn <= temp){
            adv++;
            output = real.substr(start, first+ adv);
            if(output[0] == '0'){//ignoring the zeros
                adv++;
                output = real.substr(start, first+ adv);
            }
            outputn = atoi(output.c_str());
        }
        cout<<outputn<<" ";//gets rid of zeros because of outputn being an int
        start = start + first + adv;
        temp = atoi(output.c_str());
    }
    while(reall- start > first);
    }
    cout<<endl;
    }
return 0;
}
