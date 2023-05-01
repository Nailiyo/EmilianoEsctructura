#include <iostream>
using namespace std;



bool esPRIMO(int dato){
    if(dato==1 || dato==0)
        return false;
    else{
        for(int i=2; i < dato;i++){

            if( dato % i==0 )
                return false;
        }
    }
    return true;
}

int main(){
    int dato;
    cout<<"digite un dato.. -> \n";
    cin>>dato;
    if(esPRIMO(dato)==true)
        cout<<dato<<": es Primo \n";
    else
        cout<<dato<<": no es primo \n";
    return 0;
}