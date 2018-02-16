/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   nodebin.h
 * Author: marwilc
 *
 * Created on 7 de mayo de 2016, 03:49 PM
 */

#ifndef NODEBIN_H
#define NODEBIN_H
#include <iostream>

using namespace std; 

template <class T>
class Nodebin
{
    private:
        T info;
        Nodebin<T> *sonLeft, *sonRight;
        
    public:
        //builders
        Nodebin<T>(): sonLeft(NULL), sonRight(NULL){};
        Nodebin<T>(const T &e): info(e), sonLeft(NULL),sonRight(NULL){};
        Nodebin<T>(const T &e, Nodebin<T> *left, Nodebin *right): info(e), sonLeft(left),sonRight(right){};
        
        //consultores
        T getInfo() const {return(info);};
        Nodebin<T> *getSonLeft(){return (sonLeft);};
        Nodebin<T> *getSonRight(){return(sonRight);};
        bool nodeLeaf()const {return((this->sonLeft==NULL)&&(this->sonRight==NULL));}
        bool fullNode()const {return((this->sonLeft!=NULL)&&(this->sonRight!=NULL));}
        int grade()const {return ((this->nodeLeaf())? 0:((this->fullNode())? 2: 1));}
        bool adn(const T &e1, const T &e2) const {return (((sonLeft->getInfo()==e1 && sonRight->getInfo()==e2)||(sonLeft->getInfo()==e2 && sonRight->getInfo()==e1))? true:false);}
        int isFather(const T &e) const
        {
            int resp=0;
            if(sonLeft!=NULL)
            {
                if(sonLeft->getInfo()==e)
                    resp=1;           
            }
            if(sonRight!=NULL)
            {
                if(sonRight->getInfo()==e)
                    resp=2;
            }
        }
        //modifiers
        void setInfo(const T &e) {this->info=e;};
        void setSonLeft(Nodebin<T> *left){sonLeft=left;};
        void setSonRight(Nodebin<T> *right){sonRight=right;};            
};
#endif /* NODEBIN_H */