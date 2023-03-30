#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "arraylist.h"

//normal array
typedef struct ArrayList {
    void **data;
    int capacity;
    int size;
} ArrayList;

ArrayList *createList(void) {
  ArrayList *local = NULL;
  local = malloc(sizeof(ArrayList));
  local->data = malloc(2*sizeof(void *));
  local->capacity = 2;
  local->size = 0;
    return local;
}

void append(ArrayList * l, void * data){
  if(l->capacity == l->size)
  {
    l->data = realloc(l->data, 2 * l->capacity);
    l->capacity = 2 * l->capacity;
  }
  l->data[l->size] = data;
  l->size ++;
}

void push(ArrayList * l, void * data, int i){
  if (i >= l->size) return;
  if(l->capacity == l->size)
  {
    l->data = realloc(l->data, 2 * l->capacity);
    l->capacity = 2 * l->capacity;
  }  
  for(int k = l->size; k != i; k--)
  {
    l->data[k] = l->data[k - 1];
  }
  l->data[i] = data;
  l->size ++;
}

void* pop(ArrayList * l, int i){
  void * dato = l->data[i];
  if (i >= l->size) return NULL;
   if(i < 0)
  {
    i = l->size - abs(i % l->size);
  }

  for(int k = i; k < l->size - 1; k++)
  {
    l->data[k] = l->data[k + 1];
  }
  l->size --;
  return dato;
}

void* get(ArrayList * l, int i){
  if(i > l->size) return NULL;
  if(i < 0)
  {
    i = l->size - abs(i % l->size);
  }
  return l->data[i];
}

int get_size(ArrayList * l){
    return l->size;
}

//remove elements
void clean(ArrayList * l){
    
}
