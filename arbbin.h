/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   arbbin.h
 * Author: marwilc
 *
 * Created on 7 de mayo de 2016, 03:32 PM
 */

#ifndef ARBBIN_H
#define ARBBIN_H
#include <iostream>
#include <sstream>
#include <string>
#include "nodebin.h"
#include "list.h"
#include "stack.h"
#include "tail.h"

using namespace std;

template <class T>
class Arbbin
{
    private:
        Nodebin<T> *nodeRoot;
        int dim;
        
        static Nodebin<T>* copyNodeBin(Nodebin<T> *ptr);
        static void preOrderRoute(Nodebin<T> *ptr);
        static void inOrderRoute(Nodebin<T> *ptr);
        static void postOrderRoute(Nodebin<T> *ptr);
        static void levelsRoute(Nodebin<T> *ptr, int level, List<T> &l1, List<int> &lnum);
        static int heightBin(Nodebin<T> *aux);
        static void saveLeaves(Nodebin<T> *ptr, List<T> &leaves);
        static T higher(Nodebin<T> *ptr);
        static T less(Nodebin<T> *ptr);
        static bool search(const T &e, Nodebin<T> *ptr);
        static Nodebin<T> *gps(const T &e, Nodebin<T> *ptr);
        static int gradeSearch(Nodebin<T> *ptr);
        static Nodebin<T> *boolBrother(const T &e1,const T &e2, Nodebin<T> *ptr);
        static bool complete(Nodebin<T> *ptr);
        static int checkFull(Nodebin<T> *ptr);
        static int calculateWeight(Nodebin<T> *ptr);
        static int searchLevel(const T &e, Nodebin<T> *ptr);
        static void checkAlmostFull(Nodebin<T> *ptr, int height, int &level, bool &right);
        static bool equal(Nodebin<T> *n1, Nodebin<T> *n2);
        static bool estruct(Nodebin<T> *n1, Nodebin<T> *n2);
        static bool isSimilar(Nodebin<T> *ptr, const Arbbin<T> &a2);
        static bool thereIsOccurrence(Nodebin<T> *ptr, const Arbbin<T> &a2);
        static bool subTree(Nodebin<T> * ptr,Nodebin<T> *ptr2);
        static void roadOfNodes(Nodebin<T> *ptr, const T &e, const List<T> &road, bool &band);
        static void getDiameter(Nodebin<T> *ptr, int &diam, int &height);
        static Nodebin<T> *searchFather(Nodebin<T> *ptr, const T &e);
        static Nodebin<T> *searchBrother(Nodebin<T> *ptr, const T &e);
        static float sintaxis(Nodebin<T> *ptr);
        static float operar(const float &op1,const float &op2, const string &cad);
    public:
        //destroyer
        ~Arbbin<T>();
        void emptyBinaryTree();
        
        //constructores
        Arbbin<T>():nodeRoot(NULL), dim(0){};
        Arbbin<T>(const T &e){nodeRoot= new Nodebin<T>(e); dim=1;}
        Arbbin(const T &e, const Arbbin &a1, const Arbbin &a2);
        void buildPreIn(List<T> &pre, List<T> &in);
        void buildPostIn(List<T> &post, List<T> &in);
        //void rebuildPost(Stack<T> &capital, Stack<T> &lowerCase);
        
        //consult
        bool isNull() const {return(nodeRoot==NULL);}
        T getRoot()const {return (nodeRoot->getInfo());};
        Arbbin<T> SonLeft() const;
        Arbbin<T> SonRight() const;
        int weight()const {return (dim);}
        bool isLeaf()const {return((nodeRoot!=NULL)?nodeRoot->nodeLeaf():false);}
        int height()const {return((nodeRoot!=NULL)? heightBin(nodeRoot): -1);}
        List<T> getLeaves()const;
        T higherElement()const;
        T lessElement()const;
        bool itIsFound(const T &e) const {return ((nodeRoot==NULL)? false: search(e,nodeRoot));}
        Nodebin<T> *locate(const T &e)const {return((nodeRoot==NULL)?NULL:gps(e,nodeRoot));}
        int gradeTree()const {return(((nodeRoot==NULL)||(nodeRoot->nodeLeaf()))? 0: gradeSearch(nodeRoot));}
        Nodebin<T> *brothers(const T &e1,const T&e2)const {return((nodeRoot==NULL)?NULL:boolBrother(e1,e2,nodeRoot));}
        bool treeComplete()const{return((nodeRoot==NULL)? false: complete(nodeRoot));}
	bool treeFull()const{return((checkFull(nodeRoot))!= -1);}
	bool treeAlmostFull()const;
	int weighTree()const{return(calculateWeight(nodeRoot));}  //pesar arbol
	int gradeNode(const T &e)const;
	int heightNode(const T &e)const;///**/
	int levelNode(const T &e)const{return((nodeRoot==NULL)?-1:searchLevel(e,nodeRoot));}
	bool isomorphic(const Arbbin<T> &a2)const {return(estruct(this->nodeRoot, a2.nodeRoot));}
	bool similar(const Arbbin<T> &a2)const {return((nodeRoot==NULL && a2.nodeRoot!=NULL)?false:isSimilar(nodeRoot, a2));}
	bool occurrence(const Arbbin<T> &a2)const {return(thereIsOccurrence(nodeRoot, a2));}
	List<T> getRoadNodes(const T &e1, const T &e2)const;
	int diameter() const ;
	Nodebin<T>* father(const T &e)const{return((nodeRoot==NULL||this->isLeaf())?NULL:searchFather(nodeRoot, e));}//retorna el padre, si no lo encuentra retorna nulo
        Nodebin<T>* getBrother(const T &e)const{return((nodeRoot==NULL||this->isLeaf())?NULL:searchBrother(nodeRoot, e));}
        bool arbLess (const Arbbin<T> &B) const;
        float valueTreeSintaxis()const;
	
        //routes
	void preOrder()const {preOrderRoute(this->nodeRoot);cout<<endl;};
	void inOrder()const {inOrderRoute(this->nodeRoot);cout<<endl;};
	void postOrder()const {postOrderRoute(this->nodeRoot);cout<<endl;};
	void levels()const;
        void levels(int n, int m)const;

	//modifiers
	void copyTreeBinary(const Arbbin<T> &Ab);
	void setRootBinary(const T &e);
	void setSonLeft(const Arbbin<T> &Ab);
	void setSonRight(const Arbbin<T> &Ab);
	void insertSubTreeBinary(const Arbbin<T> &tree); //es inutil
	void deleteSonLeft();
	void deleteSonRight();

	//Tree Binary Search
	void buildTBS(List<T> &l1);
	void addElemTBS(const T &e){addTBS(nodeRoot, e);}
	static void addTBS(Nodebin<T>* ptr, const T &e);
	bool searchElementTBS(const T &e) const;
	static Nodebin<T>* searchTBS(Nodebin<T>* ptr, const T &e);
	void deleteElementTBS(const T &e);
	static void deleteTBS(Nodebin<T>* ptr, const T &e);

	//overLoads
	void operator=(const Arbbin<T>& a2);
	bool operator==(const Arbbin<T>& a2) const{return(equal(this->nodeRoot, a2.nodeRoot));}
};
//destroyer- Reset
template<class T>
Arbbin<T>:: ~Arbbin<T>()
{
    Stack<Nodebin<T>* > P;
    Nodebin<T> *aux;
    if(this->nodeRoot!=NULL)
    {
        P.Stacking(this->nodeRoot);
        while(!P.isEmpty())
        {
            aux=P.getTop();
            P.unStacking();
            
            if(aux->getSonLeft()!= NULL)
                P.Stacking(aux->getSonLeft());				
            if(aux->getSonRight() != NULL)
                P.Stacking(aux->getSonRight());
            
            //liberar nodo arbolB
            aux->setSonLeft(NULL);
            aux->setSonRight(NULL);
            delete(aux);
        }
    }
    this->nodeRoot=NULL;
    dim=0;
}

template<class T>
void Arbbin<T>:: emptyBinaryTree()
{
    Stack<Nodebin<T>* > P;
    Nodebin<T> *aux;
    if(this->nodeRoot!=NULL)
    {
	P.Stacking(this->nodeRoot);
	while(!P.isEmpty())
	{
            aux=P.getTop();
            P.unStacking();
            if(aux->getSonLeft()!= NULL)
		P.Stacking(aux->getSonLeft());
					
            if(aux->getSonRight() != NULL)
		P.Stacking(aux->getSonRight());
            ///liberar nodo arbolB
            aux->setSonLeft(NULL);
            aux->setSonRight(NULL);
            delete(aux);
	}
    }
    this->nodeRoot=NULL;
    dim=0;
}
	
//constructor
template<class T>
Arbbin<T>:: Arbbin(const T &e, const Arbbin &A1, const Arbbin &A2)
{
    Arbbin arbolaux;
		
    nodeRoot= new Nodebin<T>(e);
    arbolaux.copyTreeBinary(A1);
    this->nodeRoot->setSonLeft(arbolaux.nodeRoot);
    arbolaux.copyTreeBinary(A2);
    this->nodeRoot->setSonRight(arbolaux.nodeRoot);
    arbolaux.nodeRoot= NULL;
    dim= (A1.dim)+ (A2.dim) +1;
}

template <class T>
void Arbbin<T>:: buildPreIn(List<T> &pre,List<T> &in)
{
    Arbbin<T> Aizq, Ader;
    List<T> listD, listI;
    T e;
    int n;

    if ((!pre.isEmpty())&&(!in.isEmpty()))
    {
        e= pre.consult(1);
	pre.erase(1);
	n= in.itsFound(e);///OBERVACION: que pasa si hay elementos repetidos?...
	nodeRoot=new Nodebin<T>(e);
        dim++;
	listI= in.generarSLint(1,n-1);
        listD= in.generarSLint(n+1,in.length());
	Aizq.buildPreIn(pre, listI);
	nodeRoot->setSonLeft(Aizq.nodeRoot);
	dim=dim+Aizq.dim;
	Ader.buildPreIn(pre, listD);
	nodeRoot->setSonRight(Ader.nodeRoot);
	dim=dim+Ader.dim;
	Ader.nodeRoot=NULL;
	Aizq.nodeRoot=NULL;
    }
}

template <class T>
void Arbbin<T>:: buildPostIn(List<T> &post,List<T> &in)
{
    Arbbin<T> Aizq, Ader;
    List<T> listD, listI;
    T e;
    int n;
    
    if ((!post.isEmpty())&&(!in.isEmpty()))
    {
        e= post.consult(post.length());
	post.erase(post.length());
        n= in.itsFound(e);///OBERVACION: que pasa si hay elementos repetidos?...
	nodeRoot=new Nodebin<T>(e);
	dim++;			
        listD= in.generarSLint(n+1,in.length());
	listI= in.generarSLint(1,n-1);
        Ader.buildPostIn(post, listD);
        nodeRoot->setSonRight(Ader.nodeRoot);
	dim=dim+Ader.dim;
	Aizq.buildPostIn(post, listI);
	nodeRoot->setSonLeft(Aizq.nodeRoot);
        dim=dim+Aizq.dim;
	Ader.nodeRoot=NULL;
	Aizq.nodeRoot=NULL;
    }
}

//estaticos
template<class T>
Nodebin<T>* Arbbin<T>:: copyNodeBin(Nodebin<T>* ptr)
{
    Nodebin<T>* nvo;
    if (ptr== NULL)
        nvo= NULL;
    else
	nvo= new Nodebin<T>(ptr->getInfo(), copyNodeBin(ptr->getSonLeft()), copyNodeBin(ptr->getSonRight()));
    return nvo;
}

template<class T>
void Arbbin<T>:: preOrderRoute(Nodebin<T>* ptr)
{
    if (ptr!=NULL)
    {
	cout<<ptr->getInfo()<<" ";
	preOrderRoute(ptr->getSonLeft());
	preOrderRoute(ptr->getSonRight());
    }
}

template<class T>
void Arbbin<T>:: inOrderRoute(Nodebin<T>* ptr)
{
    if (ptr!=NULL)
    {
	inOrderRoute(ptr->getSonLeft());
	cout<<ptr->getInfo()<<" ";
	inOrderRoute(ptr->getSonRight());
    }		
}

template<class T>
void Arbbin<T>:: postOrderRoute(Nodebin<T>* ptr)
{
    if (ptr!=NULL)
    {
	postOrderRoute(ptr->getSonLeft());
	postOrderRoute(ptr->getSonRight());
	cout<<ptr->getInfo()<<" ";
    }		
}

template<class T>
void Arbbin<T>:: levelsRoute(Nodebin<T>* ptr, int level, List<T> &l1, List<int> &lnum)
{
    int i, n;
    if (ptr!=NULL)
    {
        if (lnum.length()<level)
	{
            lnum.insert(1,level);
	}
	else
	{
            lnum.Set_info(level,1+ lnum.consult(level));
        }
	n=1;
	for (i = 1; i < level; i++)
            n=lnum.consult(i)+n;
	l1.insert(ptr->getInfo(),n);
        levelsRoute(ptr->getSonRight(), level+1, l1, lnum);
	levelsRoute(ptr->getSonLeft(), level+1, l1, lnum);
    }
}

template<class T>
int Arbbin<T>:: heightBin(Nodebin<T>* aux)
{
    int i=0, d=0;
    if (aux== NULL)
    {
        i=-1;
    }
    else
    {
	if (aux->nodeLeaf())//si es nodo hoja
        {
            i=0;
	}
        else
        {
            d=1+ heightBin(aux->getSonRight());
            i=1+ heightBin(aux->getSonLeft());
	}
	if (d>i)
	{
            i=d;
	}
    }
    return i;
}

template<class T> 
void Arbbin<T>:: saveLeaves(Nodebin<T>* ptr, List<T> &leaves)
{
    if (ptr!=NULL)
    {
	if (ptr->nodeLeaf())
	{
            leaves.insert(ptr->getInfo(), leaves.length()+1);
	}
	else
	{
            saveLeaves(ptr->getSonLeft(), leaves);
            saveLeaves(ptr->getSonRight(), leaves);
	}
    }
}

template<class T>
T Arbbin<T>:: higher(Nodebin<T>* ptr)
{
    T e, i, d;
    
    if (ptr->nodeLeaf())
        e= ptr->getInfo();
    else
    {
	if (ptr->getSonLeft()==NULL)
            e=higher(ptr->getSonRight());
	else if (ptr->getSonRight()==NULL)
                e=higher(ptr->getSonLeft());
            else
            {
		i=higher(ptr->getSonLeft());
		d=higher(ptr->getSonRight());
		e=(i>=d)? i:d;
            }
            
        if (e< ptr->getInfo())
            e= ptr->getInfo();					
    }
    return e;
}

template<class T>
T Arbbin<T>:: less(Nodebin<T>* ptr)
{
    T e, i, d;
    
    if (ptr->nodeLeaf())
	e= ptr->getInfo();
    else
    {
	if (ptr->getSonLeft()==NULL)
            e=less(ptr->getSonRight());
	else if (ptr->getSonRight()==NULL)
                e=less(ptr->getSonLeft());
            else
            {
                i=less(ptr->getSonLeft());
		d=less(ptr->getSonRight());
		e=(i<=d)? i:d;
            }
	if (e> ptr->getInfo())
            e= ptr->getInfo();					
    }
    return e;
}

template <class T>
bool Arbbin<T>:: search(const T &e, Nodebin<T>* ptr)
{
    bool rsp, rd=0, ri=0;
    
    if (ptr->getInfo()==e)
    {
	rsp= true;
    }
    else if (ptr->nodeLeaf())
    {
        rsp= false;
    }
    else
    {
        if (ptr->getSonLeft()!=NULL)
	{
            ri=search(e,ptr->getSonLeft());
	}
	if (ptr->getSonRight()!=NULL)
        {
            rd=search(e,ptr->getSonRight());
        }
	rsp= ((ri==true)||(rd==true))? true:false;
    }
    return (rsp);
}

template<class T>
Nodebin<T>* Arbbin<T>:: gps(const T &e, Nodebin<T>* ptr)
{
    Nodebin<T> *sol=NULL, *rd=NULL, *ri=NULL;

    if (ptr->getInfo()==e)
	sol=ptr;
    else if (ptr->nodeLeaf())
            sol=NULL;
	else
	{
            if (ptr->getSonLeft()!=NULL)
		ri=gps(e,ptr->getSonLeft());
            if (ptr->getSonRight()!=NULL)
		rd=gps(e,ptr->getSonRight());
            sol= ((ri==NULL)&&rd==NULL)? NULL:( (ri==NULL)? rd: ri );
	}
    return (sol);
}

template<class T>
int Arbbin<T>:: gradeSearch(Nodebin<T>* ptr)
{
    int g, gi, gd;
		
    if (ptr->fullNode())
	g=2;
    else if (ptr->getSonLeft()==NULL)
            g=gradeSearch(ptr->getSonRight());
	else
            g=gradeSearch(ptr->getSonLeft());
    
    g= (g<ptr->grade())? ptr->grade(): g;
    
    return (g);
}

template<class T>
Nodebin<T>* Arbbin<T>:: boolBrother(const T &e1,const T &e2, Nodebin<T>* ptr)
{
    Nodebin<T> *sol=NULL, *ri=NULL, *rd=NULL;

    if(ptr!= NULL)
    {
	if ((ptr->fullNode())&&(ptr->adn(e1,e2)))
            sol=ptr;
	else if (ptr->nodeLeaf())
                sol=NULL;
            else
            {
		if (ptr->getSonLeft()!=NULL)
                    ri=boolBrother(e1, e2,ptr->getSonLeft());
		if (ptr->getSonRight()!=NULL)
                    rd=boolBrother(e1, e2,ptr->getSonRight());
		sol= ((ri==NULL)&&(rd==NULL))? NULL:( (ri==NULL)? rd: ri );
            }
    }
    return (sol);
}

template<class T>
bool Arbbin<T>:: complete(Nodebin<T>* ptr)
{
    bool rsp;
    
    if (ptr->nodeLeaf())
	rsp=true;
    else if (!ptr->fullNode())
            rsp=false;
        else
            rsp=(complete(ptr->getSonLeft())&&complete(ptr->getSonRight()));
    return rsp;
}

template<class T>
int Arbbin<T>:: checkFull(Nodebin<T>* ptr)
{
    int rsp, i=0,d=0;

    if (ptr->nodeLeaf())
	rsp=0;
    else if (!ptr->fullNode())
            rsp=-1;
	else
	{
            d=checkFull(ptr->getSonRight());
            i=checkFull(ptr->getSonLeft());
            rsp=((i==-1) || (d==-1) || (i!=d))? -1: i+1;
	}
    return rsp;
}

template<class T>
int Arbbin<T>:: calculateWeight(Nodebin<T>* ptr)
{
    int p;

    if (ptr==NULL)
        p=0;
    else if(ptr->nodeLeaf())
            p=1;
	else
            p=1+(calculateWeight(ptr->getSonRight())+ calculateWeight(ptr->getSonLeft()));
    return p;
}

template<class T>
int Arbbin<T>:: searchLevel(const T &e,Nodebin<T> *ptr)
{
    int rsp=-1, i=-1, d=-1;

    if (ptr!=NULL)
    {
	if (e==ptr->getInfo())
	{
            rsp=0;
	}
	else if (ptr->nodeLeaf())
	{
            rsp=-1;
	}
	else
	{
            d=searchLevel(e, ptr->getSonRight());
            i=searchLevel(e, ptr->getSonLeft());
            rsp=((i==-1)&&(d==-1))? -1: ((i==-1)?d:i)+1;
	}
    }
    return rsp;	
}

template<class T>
void Arbbin<T>:: checkAlmostFull(Nodebin<T>* ptr, int height, int &level, bool &right)
{
    int lvlI, lvlD;
    bool derD=true , derI=true;

    if (height==1)
    {
	if (ptr->fullNode())
            level=-1;//indica que de este lado en el ultimo nivel hay elementos
	else if (ptr->nodeLeaf())
	{
            level= 1;//indica que de este lado en el ultimo nivel NO hay elementos
            right= false;//indica al que lo invoco que no debe recibir mas subarboles(del lado derecho) con elementos en el ultimo nivel
	}
	else if ((ptr->getSonLeft()==NULL))
		level=0;//indica que ya NO es un arbol Casi lleno
            else//mocho derecho
            {
		level=-1;//indica que de este lado en el ultimo nivel hay elementos
		right=false;
            }
    }
    else
    {
	if (ptr->nodeLeaf())
            level=1;
	else if (!ptr->fullNode())
		level=0;
            else
            {
		checkAlmostFull(ptr->getSonLeft(), height-1, lvlI, derI);
		checkAlmostFull(ptr->getSonRight(), height-1, lvlD, derD);
		if (lvlD==0 || lvlI==0)//si no son arboles casillenos
                    level=0;//indica que este tampoco es casi lleno
		else
		{
                    if (!derI)//del lado izq hay un nodoHoja o un nodo Mocho derecho
                    {
			right=false;
			if (lvlD<0)//del lado der hay un fullnode o un nodo mocho derecho
                            level=0;
			else//del lado der hay un nodoHoja
			{
                            if (lvlI<0)//del lado izq hay un nodo mocho derecho
				level=((lvlI*-1)==lvlD)?(lvlI)-1 :0;//lvlI-1 porque de este lado del camino hay un nodo en el ultimo nivel
                            else//del lado izq hay un nodo hoja
                                level=((lvlI)==lvlD)?lvlI+1 :0;
			}
                    }
                    else//del lado izq hay un fullnode
                    {
			if (!derD)//del lado der hay un nodoHoja o un nodo Mocho derecho
			{
                            right=false;
                            if (lvlD>0)//del lado der hay un nodoHoja
				lvlD=lvlD* (-1);
                        
                            level=(lvlI==lvlD)?lvlI-1:0;//lvlI-1 porque de este lado del camino hay un nodo en el ultimo nivel
			}
			else//del lado der hay un fullnode
                            level=(lvlI==lvlD)?lvlI-1:0;//lvlI-1 porque de este lado del camino hay un nodo en el ultimo nivel
                    }
		}
            }
    }
}

template<class T>
bool Arbbin<T>:: equal(Nodebin<T>* n1,Nodebin<T>* n2)
{

    if (n1==NULL && n2==NULL)
    {
	return true;
    }
    else if ((n1==NULL) ||(n2==NULL))
        {
            return false;
        }
	else
	{
            if(n1->getInfo()!=n2->getInfo())
            {
		return false;
            }
            else
            {
                if (equal(n1->getSonLeft(), n2->getSonLeft()) && equal(n1->getSonRight(),n2->getSonRight()))
		{
                    return true;
		}
		else
		{
                    return false;
		}
            }
	}
}

template<class T>
bool Arbbin<T>:: estruct(Nodebin<T>* n1,Nodebin<T>* n2)
{
    bool rsp;

    if (n1==NULL && n2==NULL)
	rsp= true;
    else if ((n1==NULL) ||(n2==NULL))
            rsp= false;
    else if (n1->nodeLeaf() && n2->nodeLeaf())
		rsp= true;
            else
            {
		if( (estruct(n1->getSonLeft(), n2->getSonLeft())) && estruct(n1->getSonRight(), n2->getSonRight()))
                    rsp= true;
		else
                    rsp= false;
            }
    return rsp;
}

template<class T>
bool Arbbin<T>:: isSimilar(Nodebin<T>* ptr, const Arbbin<T> &a2)
{
    if(ptr==NULL)
	return true;
    else
    {
        if(!a2.itIsFound(ptr->getInfo()))
            return false;
	else
	{
            if((isSimilar(ptr->getSonLeft(), a2))&&(isSimilar(ptr->getSonRight(), a2)))
		return true;
            else
		return false;
	}
    }
}

template<class T>
bool Arbbin<T>:: thereIsOccurrence(Nodebin<T> *ptr, const Arbbin<T> &a2)
{
    bool rsp;
    
    if (ptr==NULL)
    {
        rsp=false;
    }
    else
    {
        if(subTree(ptr,a2.nodeRoot))
	{
            rsp= true;
	}
	else
        {
            if(thereIsOccurrence(ptr->getSonLeft(), a2) || thereIsOccurrence(ptr->getSonRight(), a2))
            {
                rsp= true;
            }
            else
            {
                rsp= false;
            }
	}
    }
    return rsp;
}

template<class T>
bool Arbbin<T>::subTree(Nodebin<T>* ptr, Nodebin<T>* ptr2)
{
    bool rsp=true;
    
    if (ptr2!=NULL)
    {
	if(ptr==NULL)
            rsp= false;
	else if(ptr2->getInfo() != ptr->getInfo())//si llega aqui es porque ambos son distintos de null
                rsp= false;
            else
            {
		if(!subTree(ptr->getSonLeft(), ptr2->getSonLeft()) || !subTree(ptr->getSonRight(), ptr2->getSonRight()))
                    rsp= false;
            }
    }
    return rsp;
}
	
template<class T>
void Arbbin<T>:: roadOfNodes(Nodebin<T>* ptr, const T &e, const List<T> &road, bool &band)
{
    bool bandI= false, bandD=false;

    if (ptr->getInfo()==e)
    {
	band= true;
	road.insert(ptr->getInfo(),1);
    }
    else if (ptr->nodeLeaf())
            band= false;
	else
	{
            if (ptr->getSonLeft()!=NULL)
		roadOfNodes(ptr->getSonLeft(), e, road, bandI);
            if (ptr->getSonRight()!=NULL)
		roadOfNodes(ptr->getSonRight(), e, road, bandD);
			
            if((bandD)||(bandI))
            {
		band=true;
		road.insert(ptr->getInfo(),1);
            }
	}
}

template <class T>
void Arbbin<T>::getDiameter(Nodebin<T> *ptr, int &diam, int &height)
{
    int diamI=0, diamD=0, altI=0, altD=0;
    
    if(ptr==NULL)
    {
	diam=-1;
	height=-1;
    }
    else if (ptr->nodeLeaf())
        {
            diam=0;
            height=0;
	}
        else
	{
            getDiameter(ptr->getSonLeft(), diamI, altI);
            getDiameter(ptr->getSonRight(), diamD, altD);
            diam=(diamI>diamD)?diamI:diamD;
            if ((altD+altI)+2 >diam)
		diam= altD+altI+2;
            height=(altI> altD)?altI+1:altD+1;
	}
}

template<class T>
Nodebin<T>* Arbbin<T>::searchFather(Nodebin<T> *ptr, const T &e)
{
    Nodebin<T> *sol=NULL, *ri=NULL, *rd=NULL;
    
    if(ptr!= NULL)
    {
	if (ptr->nodeLeaf())
            sol=NULL;
	else if (ptr->isFather(e)>0)
                sol=ptr;
            else
            {
                if (ptr->getSonLeft()!=NULL)
                    ri=searchFather(ptr->getSonLeft(), e);
                if (ptr->getSonRight()!=NULL)
                    rd=searchFather(ptr->getSonRight(), e);
		sol= ((ri==NULL)&&(rd==NULL))? NULL:( (ri==NULL)? rd: ri );
            }
    }
    return (sol);
}

template<class T>
Nodebin<T>* Arbbin<T>:: searchBrother(Nodebin<T> *ptr, const T &e)
{
    Nodebin<T> *sol=NULL, *ri=NULL, *rd=NULL;
    
    if(ptr!= NULL)
    {
	if (ptr->nodeLeaf())
            sol=NULL;
	else if (ptr->isFather(e)==1)//si es padre por su hijo izquierdo
		sol=ptr->getSonRight();//retorna el hijo derecho (el hermano)
            else if (ptr->isFather(e)==2)//si es padre por su hijo derecho
                    sol=ptr->getSonLeft();//retorna el hijo izquierdo (el hermano)
                else
		{
                    if (ptr->getSonLeft()!=NULL)
			ri=searchFather(ptr->getSonLeft(), e);
                    if (ptr->getSonRight()!=NULL)
                        rd=searchFather(ptr->getSonRight(), e);
                    sol= ((ri==NULL)&&(rd==NULL))? NULL:( (ri==NULL)? rd: ri );
                }
    }
    return (sol);
}

template <class T>
float Arbbin<T>::sintaxis(Nodebin<T> *ptr)
{
    stringstream ss;
    float op;
    if(ptr->nodeLeaf())
    {
        ss<<ptr->getInfo();
        ss>>op;
        return(op);
    }
    else
    {
        return(operar(sintaxis(ptr->getSonLeft()),sintaxis(ptr->getSonRight()),ptr->getInfo()));
    }
   
    
}

template <class T>
float Arbbin<T>:: operar(const float &op1,const float &op2, const string &cad)
{
    if(cad=="+")
        return(op1+op2);
    if(cad=="-")
        return(op1-op2);
    if(cad=="*")
        return(op1*op2);
    if(cad=="/")
        return(op1/op2);
}
	
//modifiers
template <class T>
void Arbbin<T>:: insertSubTreeBinary(const Arbbin<T> &tree)
{
    Arbbin<T> Arbolhijo;

    Arbolhijo=tree;
    if(this->nodeRoot!=NULL)
    {
	if(nodeRoot->getSonLeft()==NULL)
	{
             nodeRoot->setSonLeft(Arbolhijo.nodeRoot);
	}
	else
	{
            if(nodeRoot->getSonRight()==NULL)
            {
		nodeRoot->setSonRight(Arbolhijo.nodeRoot);
            }
	}
    }
    dim=dim +Arbolhijo.dim;
    Arbolhijo.nodeRoot= NULL;
}

template<class T>
void Arbbin<T>:: copyTreeBinary(const Arbbin<T> &Ab)
{
    this->nodeRoot= copyNodeBin(Ab.nodeRoot);
    this->dim= Ab.dim;
}

template<class T>
void Arbbin<T>:: setRootBinary(const T &e)
{
    if (nodeRoot==NULL)
    {
	nodeRoot= new Nodebin<T>(e);
	dim=dim+1;
    }
    else
	nodeRoot->setInfo(e);
}

template<class T>
void Arbbin<T>:: setSonLeft(const Arbbin<T> &Ab)
{
    Arbbin Aaux;

    Aaux.copyTreeBinary(Ab);
    if (this->nodeRoot==NULL)
    {
	this->nodeRoot= new Nodebin<T>();
	dim++;
    }
    this->deleteSonLeft();
    this->nodeRoot->setSonLeft(Aaux.nodeRoot);
    Aaux.nodeRoot= NULL;
    this->dim= this->dim+ Ab.dim;
}

template<class T>
void Arbbin<T>:: setSonRight(const Arbbin<T> &Ab)
{
    Arbbin<T> Aaux;

    Aaux.copyTreeBinary(Ab);
    if (this->nodeRoot==NULL)
    {
	this->nodeRoot= new Nodebin<T>();
	dim++;
    }
    this->deleteSonRight();
    this->nodeRoot->setSonRight(Aaux.nodeRoot);
    Aaux.nodeRoot= NULL;
    this->dim= this->dim+ Ab.dim;
}

template <class T>
void Arbbin<T>::deleteSonLeft()
{
    int i=0;	
    Arbbin<T> Arbolhijo;
    Nodebin<T>* aux;
    Stack <Nodebin<T>* > P;
		
    if(nodeRoot!=NULL)
    {
	if(nodeRoot->getSonLeft()!=NULL)
	{
            Arbolhijo.nodeRoot= nodeRoot->getSonLeft();
            nodeRoot->setSonLeft(NULL);
            P.Stacking(Arbolhijo.nodeRoot);
            while(!P.isEmpty())
            {
                aux= P.getTop();
                P.unStacking();
		i++; 
		if(aux->getSonLeft()!= NULL)
                    P.Stacking(aux->getSonLeft());
		if(aux->getSonRight() != NULL)
                    P.Stacking(aux->getSonRight());
		///liberar nodo arbolB
		aux->setSonRight(NULL);
		aux->setSonLeft(NULL);
		delete(aux);
            }
            dim=dim -i ;
            nodeRoot->setSonLeft(NULL);
            Arbolhijo.nodeRoot= NULL;
	}
    }
}

template <class T>
void Arbbin<T>::deleteSonRight()
{
    int i=0;	
    Arbbin<T> Arbolhijo;
    Nodebin<T>* aux;
    Stack <Nodebin<T>* > P;
		
    if(nodeRoot!=NULL)
    {
	if(nodeRoot->getSonRight()!=NULL)
	{
            Arbolhijo.nodeRoot= nodeRoot->getSonRight();
            nodeRoot->setSonRight(NULL);
            P.Stacking(Arbolhijo.nodeRoot);
            while(!P.isEmpty())
            {
		aux= P.getTop();
		P.unStacking();
		i++; 
		if(aux->getSonLeft()!= NULL)
                    P.Stacking(aux->getSonLeft());
		if(aux->getSonRight() != NULL)
                    P.Stacking(aux->getSonRight());
		///liberar nodo arbolB
		aux->setSonRight(NULL);
		aux->setSonLeft(NULL);
		delete(aux);
            }
            dim=dim -i ;
            nodeRoot->setSonRight(NULL);
            Arbolhijo.nodeRoot= NULL;
	}
    }
}

//consultores
template<class T>
Arbbin<T> Arbbin<T>:: SonLeft() const
{
    Arbbin<T> hijos, aux;
		
    aux.nodeRoot= this->nodeRoot.getSonLeft();
    hijos.copyTreeBinary(aux);
    aux.nodeRoot= NULL;
    return hijos;
}

template<class T>
Arbbin<T> Arbbin<T>:: SonRight() const
{
    Arbbin<T> hijos, aux;

    aux.nodeRoot= this->nodeRoot->getSonRight();
    hijos.copyTreeBinary(aux);
    aux.nodeRoot= NULL;
    return hijos;
}

template<class T>
List<T> Arbbin<T>:: getLeaves() const
{
    List<T> hojas;
    saveLeaves(this->nodeRoot, hojas);
    return hojas;
}

template<class T>
T Arbbin<T>:: higherElement()const
{
    T e;
    if (nodeRoot!=NULL)
	e=higher(nodeRoot);
    return(e);
}

template<class T>
T Arbbin<T>:: lessElement()const
{
    T e;
    if (nodeRoot!=NULL)
    {
	e=less(nodeRoot);
    }	
    return(e);
}

template<class T>
int Arbbin<T>::gradeNode(const T &e)const
{
    Nodebin<T>* sol;
    
    sol=locate(e);
    return((sol==NULL)? -1: sol->grade());
}

template<class T>
int Arbbin<T>:: heightNode(const T &e)const
{
    Nodebin<T>* sol;
		
    sol= locate(e);
    return((sol== NULL)? -1:heightBin(sol));
}

template<class T>
bool Arbbin<T>:: treeAlmostFull()const
{
    bool der;
    int lvl;
    treeAlmostFull(nodeRoot, heightBin(nodeRoot),lvl,der);
    return(lvl!=0);
}

template<class T>
List<T> Arbbin<T>:: getRoadNodes(const T &e1, const T &e2)const
{
    List<T> camino;
    Nodebin<T>* p1;
    bool band;

    p1=this->locate(e1);
    if (e1!=NULL)
	roadOfNodes(p1, e2, camino, band);
		
    return camino;
}

template<class T>
int Arbbin<T>:: diameter() const
{
    int diam=0, alt;
    if(nodeRoot!=NULL)
	getDiameter(nodeRoot, diam, alt);
    return(diam);
}

template <class T>
bool Arbbin<T>:: arbLess (const Arbbin<T> &B) const
{
	 return(this->higherElement() < B.lessElement()); //Verdadero si A es menor que B
}
template <class T>
 float Arbbin<T>::valueTreeSintaxis()const
{   
    return (sintaxis(this->nodeRoot));
}

//recorridos
template<class T>
void Arbbin<T>:: levels()const
{
    int i;
    List<T> l1;
    List<int> lnum;
    if(nodeRoot!=NULL)
	levelsRoute(this->nodeRoot, 1, l1, lnum);
	
    while (!lnum.isEmpty())
    {
	cout<<"{";
	for (i = 0; i < lnum.consult(1); i++)
	{
            cout<<l1.consult(1)<<" ";
            l1.erase(1);
	}
	cout<<"}";
        lnum.erase(1);
    }
    cout<<endl;
}

template<class T>
void Arbbin<T>:: levels(int n, int m)const
{
    int i, suma=0, a=0, b;
    List<T> l1,l2;
    List<int> lnum;
    if(nodeRoot!=NULL)
	levelsRoute(this->nodeRoot, 1, l1, lnum);
	
    for(i=1;i<n;i++)
    {
        a=lnum.consult(i)+a;
    }
    for(i=n;i<=m;i++)
    {
        suma=lnum.consult(i)+suma;
    }
    b=a+suma;
    a++;
    l2=l1.generarSLint(a,b);
    cout<<l2;
    l2.emptying();
    l1.emptying();
    lnum.emptying();
}
//SobreCargas
template<class T>
void Arbbin<T>::operator=(const Arbbin<T>& a2)
{
    this->emptyBinaryTree();
    if(a2.nodeRoot!=NULL)
    {
        this->nodeRoot= copyNodeBin(a2.nodeRoot);
        this->dim= a2.dim;
    }
    else
    {
        nodeRoot= NULL;
	dim=0;
    }
}
//ABB
template<class T>
void Arbbin<T>:: buildTBS(List<T> &l1)
{
    while(!l1.isEmpty())
    {
	this->addElemTBS(l1.consult(1));
        l1.erase(1);
    }
}

template<class T>
void Arbbin<T>:: addTBS(Nodebin<T>* ptr, const T &e)
{
    Nodebin<T> *nvo;

    if (ptr==NULL)
	ptr= new Nodebin<T>(e);
    else
    {
        if(e <= ptr->getInfo())
	{
            if(ptr->getSonLeft()!=NULL)
		addTBS(ptr->getSonLeft(), e);
            else
            {
		nvo= new Nodebin<T>(e);
		ptr->setSonLeft(nvo);
            }	
        }
	else if (e> ptr->getInfo())
            {
		if(ptr->getSonRight()!=NULL)
                    addTBS(ptr->getSonRight(), e);
		else
		{
                    nvo= new Nodebin<T>(e);
                    ptr->setSonRight(nvo);
		}
            }
	nvo=NULL;
    }
}

template<class T>
bool Arbbin<T>:: searchElementTBS(const T &e) const
{
    bool band= false;
    if (searchTBS(nodeRoot)!= NULL)
        band= true;
    return(band);
}

template<class T>
Nodebin<T>* Arbbin<T>:: searchTBS(Nodebin<T>* ptr, const T &e)
{
    Nodebin<T>* sol=NULL;

    if(ptr!=NULL)
    {
        if (ptr->getInfo()==e)
            sol= ptr;
        else
	{
            if (e< ptr->getInfo())
		searchTBS(ptr->getSonLeft(),e);
            else
		searchTBS(ptr->getSonRight(),e);
	}
    }
    return sol;
}

template<class T>
void Arbbin<T>:: deleteElementTBS(const T &e)
{
    Nodebin<T> *ptr;

    if(this->isLeaf())
    {
	if (this->nodeRoot->getInfo()==e)
	{
            ptr= nodeRoot;
            nodeRoot= NULL;
            delete(ptr);
	}
    }
    else
    {
	ptr= this->father(e);//busca el padre
	deleteTBS(ptr, e);
    }
}

template<class T>
void Arbbin<T>:: deleteTBS(Nodebin<T>* ptr, const T &e)
{
    Nodebin<T> *del, *hmnor, *ptr2;
		
    if (ptr!=NULL)//si encontro el padre
    {
        if(ptr->isFather(e)==1)//si hay que eliminar al hijo izquierdo
	{
            del= ptr->getSonLeft();
            if (del->nodeLeaf())//si no tiene hijos
		ptr->setSonLeft(NULL);
            else if (!del->fullNode())//si tiene un solo hijo
		{
                    if(del->getSonLeft()!=NULL)
                        ptr->setSonLeft(del->getSonLeft());
                    else
			ptr->setSonLeft(del->getSonRight());
                }
                else
		{
                    hmnor= del->getSonRight();
                    ptr2=NULL;
                    while (hmnor->getSonLeft()!=NULL)//retorna el padre del menor de sus hijos derechos
                    {
			ptr2=hmnor;
			hmnor= hmnor->getSonLeft();
                    }//fin de ciclo
                    if (ptr2!=NULL)//si existe un padre para el menor de los hijos derecho, diferente a "del"
                    {
			ptr2->setSonLeft(hmnor->getSonRight());
			ptr->setSonLeft(hmnor);
			hmnor->setSonRight(del->getSonRight());
			hmnor->setSonLeft(del->getSonLeft());
                    }
                    else
                    {
			ptr->setSonLeft(hmnor);
			hmnor->setSonLeft(del->getSonLeft());
                    }
		}
        }
        else//sino, hay que eliminar al hijo derecho
        {
            del= ptr->getSonRight();
            if (del->nodeLeaf())//si no tiene hijos
                ptr->setSonRight(NULL);
            else if (!del->fullNode())//si tiene un solo hijo
                {
                    if(del->getSonLeft()!=NULL)
                        ptr->setSonRight(del->getSonLeft());
                    else
                        ptr->setSonRight(del->getSonRight());
                }
                else
                {
                    hmnor= del->getSonRight();
                    ptr2=NULL;
                    while (hmnor->getSonLeft()!=NULL)//retorna el padre del menor de sus hijos derechos
                    {
                        ptr2=hmnor;
                        hmnor= hmnor->getSonLeft();
                    }//fin de ciclo			
                    if (ptr2!=NULL)//si existe un padre para el menor de los hijos derecho, diferente a "del"
                    {
                        ptr2->setSonLeft(hmnor->getSonRight());
                        ptr->setSonRight(hmnor);
                        hmnor->setSonRight(del->getSonRight());
                        hmnor->setSonLeft(del->getSonLeft());
                    }
                    else
                    {
                        ptr->setSonRight(hmnor);
                        hmnor->setSonLeft(del->getSonLeft());
                    }
                }
        }
        del->setSonLeft(NULL);
        del->setSonRight(NULL);
        delete(del);
    }
}

/*template <class T>
void Arbbin<T>::rebuildPost(Stack<T> &capital, Stack<T> &lowerCase)
{
    Arbbin<T> arbolAux2;
    T e;
	
    if (!capital.isEmpty() && !lowerCase.isEmpty())
    {
	e=capital.getTop();
	capital.unStacking();
	nodeRoot=new Nodebin<T>(e);
	dim++;
        arbolAux2.rebuildPost();
    }	
}*/
#endif /* ARBBIN_H */
