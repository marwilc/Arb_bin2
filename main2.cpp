/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main2.cpp
 * Author: marwilc
 *
 * Created on 27 de mayo de 2016, 03:57 PM
 */

#include <cstdlib>
#include <string>
#include "arbbin.h"
using namespace std;

/*
 * 
 */
int main() {
    int casos, longitud, n, m, i, j;
    string cadena1, cadena2;
    char caracter;
    List<char> list1, list2;
    Arbbin<char> arb;
    
    cin>>casos;
    //cout<<casos<<endl;
    for(i=1;i<=casos;i++)
    {
        cin>>longitud;
        cin>>n;
        cin>>m;
        cin>>cadena1;
        //cout<<longitud<<" "<<n<<" "<<m<<endl;
        for(j=1;j<=longitud;j++)
        {
            cin>>caracter;
            list1.insert(caracter,j);
        }
        cin>>cadena2;
        for(j=1;j<=longitud;j++)
        {
            cin>>caracter;
            list2.insert(caracter,j);
        }
        //cout<<cadena1<<" "<<list1<<endl;
        //cout<<cadena2<<" "<<list2<<endl;
        if(cadena1.compare("POSTORDEN")==0)
            arb.buildPostIn(list1,list2);
        
        if(cadena1.compare("PREORDEN")==0)    
            arb.buildPreIn(list1,list2);
        
        cout<<"Caso #"<<i<<": ";
        arb.levels(n+1,m+1);
        cout<<endl;
        arb.emptyBinaryTree();
        list1.emptying();
        list2.emptying();
        //cout<<cadena1<<endl;
        //cout<<cadena2<<endl;
    }
    

    return 0;
}

