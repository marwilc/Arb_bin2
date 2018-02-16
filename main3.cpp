/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main3.cpp
 * Author: marwilc
 *
 * Created on 30 de mayo de 2016, 04:14 PM
 */

#include <cstdlib>
#include "arbbin.h"

/*
 * 
 */
int main() {
    int i, n, m, k;
    string cadena1, cadena2, cadena3, cadena4;
    List<int> list1, list2, list3, list4;
    Arbbin<int> arb1, arb2;
    
    while(cin>>cadena1)
    {    
            
            cin>>m;
            
            for(i=1;i<=m;i++)
            {
                cin>>n;
                list1.insert(n,i);
                   
            }
            
            cin>>cadena2;
            cin>>m;
            
            for(i=1;i<=m;i++)
            {
                cin>>n;
                list2.insert(n,i);
                   
            }
            
            if(cadena1.compare("POSTORDEN")==0)
                arb1.buildPostIn(list1,list2);
            
            if(cadena1.compare("PREORDEN")==0)
                arb1.buildPreIn(list1,list2);
            
         
            cin>>cadena3;
           
            cin>>m;
            
            for(i=1;i<=m;i++)
            {
                cin>>n;
                list3.insert(n,i);
                   
            }
           
            cin>>cadena4;
            cin>>m;
            for(i=1;i<=m;i++)
            {
                cin>>n;
                list4.insert(n,i);
                   
            }
            
            
            if(cadena3.compare("POSTORDEN")==0)
                arb2.buildPostIn(list3,list4);
                
            if(cadena3.compare("PREORDEN")==0)    
                arb2.buildPreIn(list3,list4);
            
            
            
            if(arb1.arbLess(arb2))
                cout<<"Es menor"<<endl;
            else
                cout<<"No es menor"<<endl;
           
            list1.emptying();
            list2.emptying();
            list3.emptying();
            list4.emptying();
            arb1.emptyBinaryTree();
            arb2.emptyBinaryTree();
                    
        } 
    return 0;
}

