#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "array_divide.h"

#define cache_ways 20
#define hex_format 4
#define mask_display 1
#define ways_for_kernel 2
#define max_group_size 18
#define allow_overlap 1

typedef struct group_infomation{
  int cgroup_no;
  int cgroup_size;
  int* cways;
  int* coverlaps;
}cgroups_t;



int bin_to_hex(int* arr){
  int value;
  value = 0;
  int i;
  for(i = 0; i < hex_format; i++){
    value = value + (*(arr+i) * pow(2,(3-i)));
  }
    return value;

}

void displaymask(int* arr, int size){
  int i;
  /*debug element*/  int bb = 0;
  int iter = 0;
  int* ar;
  int* mini_ar;
  int j = 0;
  int* hex_display;
  int k;
  int* division_array;
  int* partial_division_array;
  division_array = (int*)malloc((cache_ways/hex_format) * hex_format * sizeof(int));
  hex_display = (int*)malloc((cache_ways/hex_format) * sizeof(int));
  partial_division_array = (int*)malloc(hex_format * sizeof(int));

  ar = (int*)malloc(cache_ways * sizeof(int));
  for(i = 0; i < cache_ways; i++){
    *(ar + i) = 0;
  }
  for(i = 0; i < size; i++){
    *(ar + cache_ways-(*(arr + i))) = 1;
  }
//DEBUGGING START
  for(i = 0; i < cache_ways; i++)
    printf("%d ", *(ar+i));
  printf("\n" );
//DEBUGGING STOP
  division_array = divide_array(ar,hex_format,cache_ways);
  //DEBUGGING START:
    /*i = 0;
    printf("\n Division array is : ");
    printf("\n");
    while(i < cache_ways){
      for(j = 0; j < hex_format; j++){
        printf("%d ",*(division_array + i + j));
      }printf("\n");
      i = i + hex_format;
    }*/
  //DEBUGGING STOP
  printf("\nThe mask for cache way allocation\n" );
  for(i = 0; i < cache_ways; i = i + hex_format){
    for(j = 0; j < hex_format; j++){
      *(partial_division_array + j) = *(division_array + i + j);
    }
    //DEBUGGING START
      /*printf("\n ARRAY ENTERING THE bin_to_hex FUNCTION : \n");
      for(bb = 0; bb < hex_format; bb ++){
        printf("%d ", *(partial_division_array + bb));
      }*/
    //DEBUGGING STOP
    *(hex_display + iter) = bin_to_hex(partial_division_array);
    if(*(hex_display + iter) < 10)
      printf("%d ", *(hex_display + iter));
    else if(*(hex_display + iter) == 10)
      printf("a ");
    else if(*(hex_display + iter) == 11)
      printf("b ");
    else if(*(hex_display + iter) == 12)
      printf("c ");
    else if(*(hex_display + iter) == 13)
      printf("d ");
    else if(*(hex_display + iter) == 14)
      printf("e ");
    else
      printf("f ");
    //i = i + hex_format;
    iter ++;
  }

  /*iter = 0;
  printf("DISPLAY MASK");
  for(iter = 0; iter < (cache_ways/hex_format); iter ++){
      printf("%d ",*(hex_display + iter));
  }*/


}

int* fill_cache_ways(int k, int size){
  int j;
  int* arr;
  int b = 0;
  arr = (int*)malloc(size * sizeof(int));
  for(j = k; j < (k + size); j++){
    *(arr+b) = j;
    b++;
  }

  return arr;
}

void display_group_info(cgroups_t* p){

  int i;
  printf("\n Group number is %d \n",p->cgroup_no);
  printf("\n Group size is %d \n",p->cgroup_size);
  printf("\n the cache way numbers are :  ");
  for(i = 0; i < p->cgroup_size; i++){
    printf("%d  ",*(p->cways + i) );
  }
  printf("\n ");
  displaymask(p->cways, p->cgroup_size);
  printf("\n");

}

int main(int argc, char** argv){


  int i = 1;
  int group_size = 2;
  cgroups_t* ptr;
  ptr = (cgroups_t*)malloc(sizeof(cgroups_t));

/*  do{
      if(strcmp(argv[i],"--set_group_size") == 0)
        group_size = atoi(argv[i+1]);
      if(strcmp(argv[i],"--display_mask"))
        mask_display = 1;
      if(strcmp(argv[i],"--kernel_ways"))
        ways_for_kernel = atoi(argv[i+1]);
      if(strcmp(argv[i],"--set_max_group_size"))
        max_group_size = atoi(argv[i+1]);
      if(strcmp(argv[i],"--overlap_yes"))
        allow_overlap = 1;
      i++;
  }while(i < argc);*/

  //printf("line 68 cleared");
  i = 1;

  static int num = 0;
  if(allow_overlap == 1){
    while(group_size <= max_group_size){
        for(i = 1; i <= (20 - ways_for_kernel-(group_size) + 1); i ++){
          num = num + 1;
          ptr->cgroup_no = num;
          ptr->cgroup_size = group_size;
          ptr->cways = (int*)malloc(group_size * sizeof(int));
          ptr->cways = fill_cache_ways(i, group_size);
          //displaymask(cways,group_size);
          display_group_info(ptr);
    }
        group_size ++;
}
}
  else
  {
    while(group_size < max_group_size){
        for(i = 1; i < (20 - ways_for_kernel-(group_size)); i + group_size){
          num = num + 1;
          ptr->cgroup_no = num;
          ptr->cgroup_size = group_size;
          ptr->cways = (int*)malloc(group_size * sizeof(int));
          ptr->cways = fill_cache_ways(i, group_size);
          //displaymask(cways,group_size);
          display_group_info(ptr);
    }
        group_size ++;
}

  }

  return 0;



}
