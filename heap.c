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
  elemento.data = data;
  elemento.priority = priority;

  if(pq->size == pq->capac)
  {
    pq->capac = (pq->capac*2) + 1;
    pq->heapArray = realloc (pq->heapArray, pq->capac); 
  }
  pq->heapArray[pq->size] = elemento;
  

  while(elemento != pq->heapArray[0].data)
  {
    if(elemento.priority > pq->heapArray[(pq->size - 1)/2].priority)
    {
      aux = pq->heapArray[(size-1)/2];
      pq->heapArray[(size-1)/2] = pq->heapArray[size];
      pq->heapArray[size] = aux;
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
