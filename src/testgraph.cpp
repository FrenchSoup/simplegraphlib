#include <iostream>
#include "graph.hpp"

using namespace std;

#define NB_TESTS 26
#define NOT_IMPLEMENTED_EXCEPTION "Not implemented yet"

void testConstructor();
void testOpBraces();
void testOpPlusGraph();
void testOpPlusVertice();
void testOpMinusGraph();
void testOpMinusVertice();
void testOpStream();
void testMap();
void testFilter();
void testForeach();
void testForeachParam();
void testGetNbVertices();
void testGetVerticeByIndex();
void testGetVerticeIndex();
void testContain();
void testAddVerticeCreate();
void testAddVertice();
void testAddNeighbour();
void testAddOrientedEdge();
void testAddEdge();
void testAddGraph();
void testRemoveVertice();
void testSubstract();
void testClear();
void testCopy();
void testPrintGraph();


int main() {

  void(*tests[])(void)  = {
    testConstructor,
    testOpBraces,
    testOpPlusGraph,
    testOpPlusVertice,
    testOpMinusGraph,
    testOpMinusVertice,
    testOpStream,
    testMap,
    testFilter,
    testForeach,
    testForeach,
    testGetNbVertices,
    testGetVerticeByIndex,
    testGetVerticeIndex,
    testContain,
    testAddVertice,
    testAddVertice,
    testAddNeighbour,
    testAddOrientedEdge,
    testAddEdge,
    testAddGraph,
    testRemoveVertice,
    testSubstract,
    testClear,
    testCopy,
    testPrintGraph
  };

  int errors=0;
  
  for(int i=0;i<NB_TESTS;i++){
    try{
      tests[i]();
    }
    catch(char const* error){
      cerr<<error<<", at function "<<i<<endl;
      errors++;
    }
  }
  
  if(errors==0)
    return 0;

  return 1;
}

void testConstructor(){
  Graph<int,int>* graph = new Graph<int, int>();
  if(graph->getNbVertices()!=0 || graph->vertices.size()!=0)
    throw "Constructor create non-empty graph";
}

void testOpBraces(){
  Graph<int,int>* graph = new Graph<int, int>();
  graph->vertices.push_back(Vertice<int,int>(0,0));
  graph->vertices.push_back(Vertice<int,int>(1,1));

  if((*graph)[0]!=graph->vertices[0])
    throw "Braces return wrong vertice";
}

void testOpPlusGraph(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}

void testOpPlusVertice(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}

void testOpMinusGraph(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testOpMinusVertice(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testOpStream(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testMap(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testFilter(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testForeach(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testForeachParam(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testGetNbVertices(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testGetVerticeByIndex(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testGetVerticeIndex(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testContain(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testAddVerticeCreate(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testAddVertice(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testAddNeighbour(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testAddOrientedEdge(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testAddEdge(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testAddGraph(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testRemoveVertice(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testSubstract(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testClear(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testCopy(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
void testPrintGraph(){
  throw NOT_IMPLEMENTED_EXCEPTION;
}
