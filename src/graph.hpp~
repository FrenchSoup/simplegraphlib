//
// Created by cyprien on 14/08/16.
//

#pragma once
#include <iostream>
#include "vertice.hpp"

using namespace std;
template <class T, class D>
class Graph{

  /*
    -Constructor:
    Graph();

    -Operators:
    Vertice<T,D> operator [](int i);
    Graph<T,D> operator +(Graph<T,D> add);
    Graph<T,D> operator +(Vertice<T,D> add);
    Graph<T,D> operator -(Graph<T,D> sub);
    Graph<T,D> operator -(Vertice<T,D> sub);
    bool operator ==(Graph<T,D> eq);
    bool operator !=(Graph<T,D> eq)
    friend ostream& operator <<(ostream& stream, Graph<T,D> &graph);

    -Functionnal Methods:
    Graph<T,D> map(Vertice<T,D> fun(Vertice<T,D>));
    Graph<T,D> filter(bool fun(Vertice<T,D>));
    template<class F> vector<F> foreach(F fun(Vertice<T,D>));
    template<class F, class P> vector<F> foreach(F fun(Vertice<T,D>, P parameter), vector<P> parameters);
 
    -Access methods:
    int getNbVertices();
    Vertice<T,D>* getVerticeByIndex(int i);
    int getVerticeIndex(T label);
    bool contain(T label);

    -Graph manipulation methods:
    int addVertice(T label, D data);
    int addVertice(Vertice<T,D> v);
    int addNeighbour(Vertice<T,D> v1, Vertice<T,D> v2);
    int addOrientedEdge(T v1, T v2);
    int addEdge(T v1, T v2);
    int addGraph(Graph<T,D> graph);
    int removeVertice(T label);
    int substract(Graph<T,D> graph);
    int clear();
    int copy(Graph<T,D>* copy);

    -"Pretty" printer
    int printGraph(ostream& stream);

  */


  
    /////////////////////////////////////////////////////////////
    //Class code begins here!
    /////////////////////////////////////////////////////////////



private:

public:

  int nbVertices;
  vector<Vertice<T,D> > vertices;
  
  Graph(){this->nbVertices=0;};
  
  Vertice<T,D> operator [](int i){
    return vertices[i];
  }
  
  Graph<T,D> operator +(Graph<T,D> add){
    addGraph(add);
    return this;
  }
  
  Graph<T,D> operator +(Vertice<T,D> add){
    addVertice(add.label);
        return this;
  }
  
  Graph<T,D> operator -(Graph<T,D> sub){
    substract(sub);
    return this;
  }
  Graph<T,D> operator -(Vertice<T,D> sub){
    removeVertice(sub.label);
    return this;
  }
  
  bool operator ==(Graph<T,D> eq){
    if(this->nbVertices != eq.nbVertices) return false;

    #pragma omp parallel for
    for(int i=0;i<nbVertices;i++){
      if((*this)[i] != eq[i]) return false;
    }
    return true;
  }

  bool operator !=(Graph<T,D> eq){
    return !((*this)==eq);
  }
  
  Graph<T,D> map(Vertice<T,D> fun(Vertice<T,D>)){

    #pragma omp parallel for
    for(int i=0;i<nbVertices;i++)
      {
	vertices[i]=fun(vertices[i]);
      }
        return this;
  }
  
  Graph<T,D> filter(bool fun(Vertice<T,D>)){
    int nbLabels=0;
    vector<int>labels;

    #pragma omp parallel for
    for(int i=0;i<nbVertices;i++){
      if(!fun(vertices[i])){
	labels.push_back(i);
	nbLabels++;
      }
    }
    removeVerticesByIndex(nbLabels,labels);
    return this;
  }

  template<class F>
  vector<F> foreach(F fun(Vertice<T,D>)){
    vector<F> ret;
    
    #pragma omp parallel for
    for(int i=0;i<nbVertices;i++){
      ret.push_back(fun(vertices[i]));
    }
    return ret;
  }
  
  template<class F, class P>
  vector<F> foreach(F fun(Vertice<T,D>, P parameter), vector<P> parameters){
    vector<F> ret;
    #pragma omp parallel for
    for(int i=0;i<nbVertices;i++){
      ret.push_back(fun(vertices[i],parameters[i]));
    }
    return ret;
  }
  
  friend ostream& operator <<(ostream& stream, Graph<T,D> &graph){
    graph.printGraph(stream);
    return stream;
  }
  
  int addVertice(T label, D data){
    nbVertices++;
    vertices.push_back(Vertice<T,D>(label, data));
    return 0;
  }
  
  int addVertice(Vertice<T,D> v){
    nbVertices++;
    vertices.push_back(v);
    return 0;
  }
  
  int addNeighbour(Vertice<T,D> v1, Vertice<T,D> v2){
    if(!(this->contain(v2.label))){
      this->addVertice(v2);
    }
    this->addEdge(v1.label,v2.label);
    return 0;
  }
  
  int addOrientedEdge(T v1, T v2){
    getVertice(v1)->addNeighbour(*getVertice(v2));
    return 0;
  }
  
  int addEdge(T v1, T v2){
    addOrientedEdge(v1,v2);
    addOrientedEdge(v2,v1);
    return 0;
  }
  
  int addGraph(Graph<T,D> graph){
    bool testVertice;
    bool testNeighbour;
    Vertice<T,D>tmp;
    
    for(int i=0;i<graph.nbVertices;i++){
            testVertice=false;
            for(int j=0;j<nbVertices;j++){
	      if(graph[i].label == vertices[j].label){
		testVertice=true;
	      }
            }
            if(testVertice)
	      addVertice(graph[i]);
            else{
                tmp=*getVertice(graph[i].label);
                for(int k=0;k<graph[i].nbNeighbours;k++){
		  testVertice=false;
		  for(int l=0;l<vertices[i].nbNeighbours;l++){
		    if(graph[i][k].label == tmp[l].label){
		      testNeighbour=true;
		    }
		  }
		  if(!testNeighbour){
		    tmp.addNeighbour(graph[i][k].label);
		  }
                }
            }
    }
    return 0;
  }
  
  int removeVertice(T label){
    #pragma omp parallel for
    for(int i=0;i<nbVertices;i++){
      if(vertices[i].label==label)
	removeVerticeByIndex(i);
    }
  }
  
  int removeVerticeByIndex(int index){
    vertices.erase(vertices.begin()+index);
    nbVertices--;
  }

  int removeVerticesByIndex(int nbVerticesToRemove, vector<int> toRemove){
    #pragma omp parallel for
    for(int i=0;i<nbVerticesToRemove;i++){
      removeVerticeByIndex(toRemove[i]);
    }
  }
  
  int getNbVertices(){ return nbVertices;}
  
  Vertice<T,D>* getVertice(T label){
    #pragma omp parallel for
    for(int i=0;i<nbVertices;i++){  
      if(vertices[i].label==label){
	return &(vertices[i]);
      }
    }
    return NULL;
  }
  
  Vertice<T,D>* getVerticeByIndex(int i){
    return &vertices[i];
  }
  
  int getVerticeIndex(T label){
    #pragma omp parallel for
    for(int i=0;i<nbVertices;i++){
      if(vertices[i].label==label)
	return i;
    }
    return -1;
  }
  
    bool contain(T label){
      if(this->getVerticeIndex(label)!=-1){
	return true;
      }
      return false;
    }
  
  void pop_front(std::vector<T>& vec)
  {
    vec.front() = move(vec.back());
    vec.pop_back();
  }
  
    int substract(Graph<T,D> graph){
      Vertice<T,D>* toSubstract;
      T l;
      for(int i=0;i<graph.nbVertices;i++){
	toSubstract=getVertice(graph[i].label);
	for(int j=0;j<graph[i].nbNeighbours;j++){
	  toSubstract->removeNeighbour(graph[i][j].label);
	}
	if(toSubstract->nbNeighbours==0){
	  removeVertice(toSubstract->label);
	}
      }
      return 0;
    }
  
  int copy(Graph<T,D>* copy){
    copy->clear();
    int j;
    #pragma omp parallel for private(j)
    for(int i=0;i<nbVertices;i++){
      copy->addVertice(vertices[i].label);
      for(j=0;j<vertices[i].nbNeighbours;j++){
	copy->vertices[i].addNeighbour(vertices[i][j].label);
      }
    }
    return 0;
  }
  
  int clear(){
    vertices.clear();
    nbVertices=0;
  }
  
  int printGraph(ostream& stream){
    stream << nbVertices <<  endl;
    for(int i=0;i<nbVertices;i++){
      stream << vertices[i].label <<"[ ";;
      for(int j=0;j<vertices[i].nbNeighbours;j++){
	stream << vertices[i][j].label << " ";
      }
      stream << "]" <<endl;
    }
    return 0;
  }
};
