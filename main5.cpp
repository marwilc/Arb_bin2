/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main5.cpp
 * Author: marwilc
 *
 * Created on 5 de junio de 2016, 08:00 PM
 */

#include <cstdlib>
#include "arbbin.h"

using namespace std;

/*
 * 
 */
int main() {
    
    Arbbin<int> arb1,arb2;
    List<int> listPre,listPost,listIno;
    string cadena;
    int i,n, num, cont;
    
    cont=0;
    while(cin>>cadena)
    {
        cin>>n;
        if(cadena=="POSTORDEN")
            for(i=1;i<=n;i++)
            {
                cin>>num;
                listPost.insert(num,i);
            }
        else if(cadena=="PREORDEN")
                for(i=1;i<=n;i++)
                {
                    cin>>num;
                    listPre.insert(num,i);
                }
            else
            {
                cont++;
                for(i=1;i<=n;i++)
                {
                    cin>>num;
                    listIno.insert(num,i);
                }
            }
        if(cont==1)
        {
            if(!listPost.isEmpty() && !listIno.isEmpty())
            {
                //cout<<listPost<<endl;
                //cout<<listIno<<endl;
                arb1.buildPostIn(listPost,listIno);
                listPost.emptying();
                listIno.emptying();
            }
            else if(!listPre.isEmpty() && !listIno.isEmpty())
                {
                    //cout<<listPre<<endl;
                    //cout<<listIno<<endl;
                    arb1.buildPreIn(listPre,listIno);
                    listPre.emptying();
                    listIno.emptying();
                }
        }
        else if(cont==2)
            {
                cont=0;
                if(!listPost.isEmpty() && !listIno.isEmpty())
                {
                    arb2.buildPostIn(listPost,listIno);
                    listPost.emptying();
                    listIno.emptying();
                }
                else if(!listPre.isEmpty() && !listIno.isEmpty())
                     {
                        arb2.buildPreIn(listPre,listIno);
                        listPre.emptying();
                        listIno.emptying();
                     }
                
                if(arb1.occurrence(arb2))
                {
                    cout<<"A1 ocurre en A2."<<endl; 
                }
                else
                {
                    cout<<"A1 no ocurre en A2."<<endl; 
                }
                arb1.emptyBinaryTree();
                arb2.emptyBinaryTree();
                
            }
    }
            
    return 0;
}
