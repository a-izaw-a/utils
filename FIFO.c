#include <stdio.h>
#include <stdlib.h>
#include "FIFO.h"

FList *FInit(void){
  FList* header	= (FList*)malloc(sizeof(FList));
  // FList *new = malloc(sizeof(FList));
  if(header == NULL){
    printf("fail to initialize\n");
    abort();
  }
  
  header->newer = header;
  header->older = NULL;
  header->space = NULL;

  FSec(header);
  
  return header;
}

/* I want to devide operation with FINI */
void FSec(FList *header){
  FList *new;
  FList *tmp = header->space;
  for(int i = 0; i < FINI; i++){
    new = (FList*)malloc(sizeof(FList));

    new->older = tmp;
    tmp = new;
    //    tmp = header->space;
  }
  header->space = new;
}

void FPush(FList *header, void *target){
  FList *add = header->space;
  header->space = add->older;
  FList *tmp = header->newer;

  header->newer = add;
  add->newer = tmp;
  add->older = NULL;
  tmp->older = add;

  add->contents = target;
}

void *FPop(FList *header){
  if(header->older == NULL){
    return NULL;
  }
  FList *oldest = header->older;
  void *target = oldest->contents;
  header->older = oldest->older;
  return target;
}

int FDel(FList *header, void *target){
  return 0;
}

int FCompare(FList *header, void *target){
  return 3;
}

int FDes(FList *header){
  int res = 0;
  FList *space = header->space;
  FList *tmp1;

  while(header != NULL){
    tmp1 = header;
    header = header->older;
    free(tmp1);
  }
  free(space);

  return res;
}
