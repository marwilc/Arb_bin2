/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main4.cpp
 * Author: marwilc
 *
 * Created on 1 de mayo de 2016, 04:14 PM
 */

#include <cstdlib>
#include "arbbin.h"
#include <string>
#include <sstream>
/*
 * 
 */
int main() {
   int cont,i;
   Arbbin<string> arb;
   string cadena, ss;
   //stringstream ss;
   List<string> listPre, listPost, listIno;
   cont=1;
   while(cin>>cadena)
   {
       
       if(cadena=="PREORDEN")
       {    i=1;
            while(cin.get()!='\n')
            {
                cin>>ss;
                listPre.insert(ss,i);
                i++;
            }
       }
       else if (cadena=="POSTORDEN")
            {
                    
                i=1;
                while(cin.get()!='\n')
                {
                    cin>>ss;
                    listPost.insert(ss,i);
                    i++;
                }   
            }
            else
            {
                i=1;
                while(cin.get()!='\n')
                {
                    cin >> ss;
                    listIno.insert(ss,i);
                    i++;
                }
            }
            
       if((!listPost.isEmpty() && !listIno.isEmpty() || (!listPre.isEmpty() && !listIno.isEmpty())))
       {
            if(!listPost.isEmpty())
            {
                //cout<<listPost<<endl;
                //cout<<listIno<<endl;
                arb.buildPostIn(listPost, listIno);
                listPost.emptying();
                listIno.emptying();
            }
            else if(!listPre.isEmpty())
            {
                //cout<<listPre<<endl;
                //cout<<listIno<<endl;
                arb.buildPreIn(listPre, listIno);
                listPre.emptying();
                listIno.emptying();
              
            }
            
            //arb.levels();
            cout<<"Caso #"<<cont++<<':'<<endl;
            cout<<arb.valueTreeSintaxis()<<endl<<endl;
            arb.emptyBinaryTree();
                 
       }         
   }
    return 0;
}

