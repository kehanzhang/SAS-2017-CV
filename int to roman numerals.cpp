/*****************************
*    Kehan Zhang             *
*    6/18/2016               *
*    Enloe HS                *
*****************************/
#include<math.h>
#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

void output(int length, char &one, char &five, char &ten){//defines what each character should be with each certain case
    if(length > 3){
        one = 'M';
        five = 'V';
        ten = 'X';
    }
    else if(length > 2){
        one = 'C';
        five = 'D';
        ten = 'M';
    }
    else if(length > 1){
        one = 'X';
        five = 'L';
        ten = 'C';
    }
    else{
        one = 'I';
        five = 'V';
        ten = 'X';
    }
}

void run(int length, int current, char one, char five, char ten, string open){
    int loop = length;//temp holder for the value of length
    for(int c = 0; c<loop; c++){

        output(length, one, five, ten);//changes the characters to go with to the size
        if(current<4){//cause 1 = I , 2 = II and 3 = III
            for(int i = 0; i <current; i++){
                cout<<one;
            }
        }
        else if(current == 4){//all the other cases
            cout<<one<<five;
        }
        else if(current == 5){
            cout<<five;
        }
        else if(current == 6){
            cout<<five<<one;
        }
        else if(current == 7){
            cout<<five<<one<<one;
        }
        else if(current == 8){
            cout<<five<<one<<one<<one;
        }
        else{
            cout<<one<<ten;
        }

        current = atoi(open.substr(c+1, 1).c_str());//shifts current one to the right one
        length--;//helps refresh the output function now that current shifted
    }

}

int main(){

    string open;
    int numb, div;
    char one, five, ten;
    cout<<"Enter a number from 1-4000 to be converted into roman numerals"<<endl;
    cin>>open;//open is a string; used to get positional values later on
    int length = open.length();
    numb = atoi(open.c_str());//converting open(string) to an int

    int current = atoi(open.substr(0, 1).c_str());//sets starting point as the number to the way left
    run(length,current,one,five,ten,open);

    return 0;
}
