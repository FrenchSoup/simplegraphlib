//
// Created by cyprien on 14/08/16.
//

#pragma once

#include "graph.hpp"
#include <map>


template <class T, class D>
int widthFirstSearch(Graph<T,D> graph, T start, Graph<T,D>* result){
    result->clear();
    std::map<T,bool> state;
    vector<T> queue;
    for(int i=0;i<graph.nbVertices;i++){
        state.insert(pair<T,bool>(graph.vertices[i].label, false));
    }
    Vertice<T,D> pop = *getVertice(start);
    queue.push_back(pop.label);
    while(!queue.empty()){
        pop=*getVertice(queue[0]);
        pop_front(queue);
        result->addVertice(pop.label, pop.data);
        for(int j=0;j<pop.nbNeighbours;j++){
            if(!state[pop[j].label]){
                state[pop[j].label]=true;
                result->addVertice(pop[j].label, pop[j].data);
                result->addOrientedEdge(pop[j].label, pop.label);
                queue.push_back(pop[j].label);
            }
        }
    }

    return 0;
}

template <class T, class D>
int depthFirstSearch(Graph<T,D> graph, T start, Graph<T,D>* result){
    result->clear();
    map<T,bool> state;
    vector<T> queue;
    for(int i=0;i<graph.nbVertices;i++){
        state.insert(pair<T,bool>(graph.vertices[i].label, false));
    }
    Vertice<T,D> pop = *getVertice(start);
    queue.push_back(pop.label);
    while(!queue.empty()){
        pop=*getVertice(queue.back());
        queue.pop_back();
        result->addVertice(pop.label, pop.data);
        for(int j=0;j<pop.nbNeighbours;j++){
            if(!state[pop[j].label]){
                state[pop[j].label]=true;
                result->addVertice(pop[j].label, pop[j].data);
                result->addOrientedEdge(pop[j].label, pop.label);
                queue.push_back(pop[j].label);
            }
        }
    }
    return 0;
}

template <class T, class D>
int getPath(Graph<T,D> graph, T v1, T v2, Graph<T,D>* path){
  Graph<T,D> temp;
  T tmp=v2;
  Vertice<T,D> cursor;
  int ret=0;
  path->clear();
  widthFirstSearch(graph, v1, &temp);
  
  while(tmp!=v1){
    cursor=*getVertice(tmp);
    path->addVertice(cursor);
    cursor=cursor[0];
    tmp=cursor.label;
    ret++;
  }
  return ret;
}

template <class T, class D>
int connexComposants(Graph<T,D> graph, vector<Graph<T, D> >* composants){
  composants->clear();
  map<T,bool> state;
  vector<T> queue;
  bool allMarked=false;
  Vertice<T,D> pop;
  int ret=0;
  
  for(int i=0;i<graph.nbVertices;i++){
    state.insert(pair<T,bool>(graph.vertices[i].label, false));
  }
  
  while(!allMarked){
    Graph<int, D> composant;
    
    for(int i=0;i<graph.nbVertices;i++){
      if(!state[graph.vertices[i].label]){
	queue.push_back(graph.vertices[i].label);
	composant.addVertice(graph.vertices[i].label,graph.vertices[i].data);
	break;
      }
    }
    
    while(!queue.empty()){
      pop=*getVertice(queue.back());
      queue.pop_back();
      state[pop.label]=true;
      for(int j=0;j<pop.nbNeighbours;j++){
	if(!state[pop[j].label]){
	  if(!composant.contain(pop[j].label))
	    composant.addVertice(pop[j].label, pop[j].data);
	  composant.addEdge(pop[j].label, pop.label);
	  queue.push_back(pop[j].label);
	}
      }
      
    }
    composants->push_back(composant);
    ret++;
    allMarked=true;
    for(int i=0;i<graph.nbVertices;i++){
      allMarked &= state[graph.vertices[i].label];
    }
  }
  return ret;
}

template <class T, class D>
void getCycle(Graph<T,D> graph,Graph<T,D>* result){

    result->clear();
    map<T,int> state;
    vector<T> queue;
    T father;
    for(int i=0;i<graph.nbVertices;i++){
        state.insert(pair<T,int>(graph.vertices[i].label, false));
    }
    Vertice<T,D> pop = *getVertice(graph.vertices[0].label);
    queue.push_back(pop.label);

    state[pop.label]=true;
    result->addVertice(pop.label, pop.data);

    while(!queue.empty()){
        father=pop.label;
        pop=*getVertice(queue.back());
        queue.pop_back();
        for(int j=0;j<pop.nbNeighbours;j++){
            if(!state[pop[j].label]){
                state[pop[j].label]=true;
                result->addVertice(pop[j].label, pop.data);
                result->addOrientedEdge(pop[j].label, pop.label);
                queue.push_back(pop[j].label);
            }else{
                if(!(father==pop[j].label))
                    return;
            }
        }
    }
    result->clear();
}

