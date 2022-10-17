#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


void* heap_top(Heap* pq)
{
  heapElem e = pq->heapArray[0];
  void *d = e.data;
  
  if(pq->size > 0)
  {
    return(d);
  }
  
  return (NULL);
}



void heap_push(Heap* pq, void* data, int priority)
{
  heapElem elemento, aux;
  int s;
  elemento.data = data;
  elemento.priority = priority;

  if(pq->size == pq->capac)
  {
    pq->capac = (pq->capac*2) + 1;
    pq->heapArray = (heapArray) realloc (pq->heapArray, pq->capac); 
  }
  pq->heapArray[pq->size] = elemento;
  
  s = pq->size;
  while(pq->heapArray[s].priority > pq->heapArray[(s - 1)/2].priority)
  {
    if(pq->heapArray[s].priority > pq->heapArray[(s - 1)/2].priority)
    {
      aux = pq->heapArray[(s - 1)/2];
      pq->heapArray[(s - 1)/2] = pq->heapArray[s];
      pq->heapArray[s] = aux;
      s = (s-1)/2;
    }
  }
  pq->size++;
}


void heap_pop(Heap* pq){

}

Heap* createHeap()
{
  Heap* h = (Heap*) malloc (sizeof(Heap));
  
  h->heapArray = (heapElem*) malloc (sizeof(heapElem)*3);
  
  h->size = 0;
  h->capac = 3;
  
  return (h);
}
