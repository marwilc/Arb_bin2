/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: marwilc
 *
 * Created on 8 de mayo de 2016, 04:10 PM
 */


#include "arbbin.h"
#include <iostream>
//using namespace std;


/*
 * 
 */
int main() {
    
    List<char> lIn, lPre;
    Arbbin<char> arb;
    int num, i;
    char caracter;
    
    cin>>num;
    for(i=1;i<=num;i++)
    {
        cin>>caracter;
        lPre.insert(caracter,i);
    }
    
    for(i=1;i<=num;i++)
    {
        cin>>caracter;
        lIn.insert(caracter,i);
    }
    arb.buildPreIn(lPre,lIn);
    arb.preOrder();
    arb.levels();
    arb.postOrder();
    arb.inOrder();
    cout<<endl;
    
    return 0;
}

