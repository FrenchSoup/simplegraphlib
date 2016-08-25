//
// Created by cyprien on 14/08/16.
//

#pragma once
#include <vector>
#include <omp.h>

using namespace std;
template <class T, class D>
class Vertice{

  /*
    -public fields:
    T label;
    D data;
  

    -Constructor:
    Vertice<T,D>(T label, D data);

    -Operators:
    Vertice<T,D> operator [](int i);
    Vertice<T,D> operator +(Vertice<T,D> add);
    Vertice<T,D> operator -(Vertice<T,D> sub);
    bool operator ==(Vertice<T,D> eq);
    bool operator !=(Vertice<T,D> neq);

    -Functionnal Methods:
    Vertice<T,D> map(Vertice<T,D> fun(Vertice<T,D>));
    Vertice<T,D> filter(bool fun(Vertice<T,D>));
    template<class F> vector<F> foreach(F fun(Vertice<T,D>));
    template<class F, class P> vector<F> foreach(F fun(Vertice<T,D>, P parameter), vector<P> parameters);

    -Neighbours manipulation methods:
    bool neighbour(T label);
    bool hasNeighbours();
    int addNeighbour(Vertice<T,D> v);
    Vertice<T,D>* getNeighbour(T label);
    int removeNeighbour(T label);
    int removeNeighbourByIndex(int index);
    int removeNeighboursByIndex(int nbVerticesToRemove, vector<int> toRemove);

  */
  
    /////////////////////////////////////////////////////////////
    //Class code begins here!
    /////////////////////////////////////////////////////////////


private:
  vector<Vertice> neighbours;
  int nbNeighbours;
  
public:

  T label;
  D data;
   
  Vertice<T,D>(T label, D data){
    this->label=label;
    this->data=data;
    this->nbNeighbours=0;
  }
  
  
  Vertice<T,D> operator [](int i){
    return neighbours[i];
  }
  
  Vertice<T,D> operator +(Vertice<T,D> add){
    addNeighbour(add);
    return this;
  }
  
  Vertice<T,D> operator -(Vertice<T,D> sub){
    removeNeighbour(sub.label);
    return this;
  }

  bool operator ==(Vertice<T,D> eq){
    return (this->label == eq.label && this->data==eq.data);
  }

  
  bool operator !=(Vertice<T,D> neq){
    return !((*this)==neq);
  }

  
  Vertice<T,D> map(Vertice<T,D> fun(Vertice<T,D>)){
    #pragma omp parallel for
    for(int i=0;i<nbNeighbours;i++){
	neighbours[i]=fun(neighbours[i]);
      }
    return this;
  }
  
  Vertice<T,D> filter(bool fun(Vertice<T,D>)){
    int nbLabels=0;
    vector<int>labels;
    
    #pragma omp parallel for
    for(int i=0;i<nbNeighbours;i++){
      if(!fun(neighbours[i])){
	labels.push_back(i);
	nbLabels++;
      }
    }
    removeNeighboursByIndex(nbLabels,labels);
    return this;
  }

  template<class F>
  vector<F> foreach(F fun(Vertice<T,D>)){
    vector<F> ret;
    
    #pragma omp parallel for
    for(int i=0;i<nbNeighbours;i++){
      ret.push_back(fun(neighbours[i]));
    }
    return ret;
  }
  
  template<class F, class P>
  vector<F> foreach(F fun(Vertice<T,D>, P parameter), vector<P> parameters){
    vector<F> ret;

    #pragma omp parallel for
    for(int i=0;i<nbNeighbours;i++){
      ret.push_back(fun(neighbours[i],parameters[i]));
    }
    return ret;
  }
  
  bool neighbour(T label){

    #pragma omp parallel for
    for(int i=0;i<this->nbNeighbours;i++){
      if(this->neighbours[i].label==label)
                return true;
    }
    return false;
  }
  
  bool hasNeighbours(){
    return nbNeighbours;
  }
  
  int addNeighbour(Vertice<T,D> v){
    if(!neighbour(v.label)){
      neighbours.push_back(v);
      nbNeighbours++;
    }
    return 0;
  }
  
  Vertice<T,D>* getNeighbour(T label){
    #pragma omp parallel for
    for(int i=0;i<nbNeighbours;i++){
      if(neighbours[i]==label) return &neighbours[i];
    }
    throw "NoSuchElement";
  }
  
  int removeNeighbour(T label){
    #pragma omp parallel for
    for(int i=0;i<nbNeighbours;i++){
      if(neighbours[i].label == label){
	neighbours.erase(neighbours.begin()+i);
	nbNeighbours--;
	return 0;
      }
    }
    return -1;
  }

  int removeNeighbourByIndex(int index){
    neighbours.erase(neighbours.begin()+index);
    nbNeighbours--;
  }

  
  int removeNeighboursByIndex(int nbVerticesToRemove, vector<int> toRemove){
    #pragma omp parallel for
    for(int i=0;i<nbVerticesToRemove;i++){
      removeNeighbourByIndex(toRemove[i]);
    }
  }

  
  
};
