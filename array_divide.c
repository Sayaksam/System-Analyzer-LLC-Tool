#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "array_divide.h"


int* divide_array(int* array_given, int div_size, int array_length){

  assert((array_length % div_size) == 0);
    int i = 0;
    int j = 0;
    int k = 0;
    int* mini_array;
    int* sending_array = (int*)malloc((array_length/div_size) * div_size * sizeof(int)) ;
    /*printf("\n THE BIG ARRAY IS: \n");
    for(i = 0; i < array_length; i++){
      printf("%d ", *(array_given + i));
    }*/
    for(i = 0; i <= array_length-div_size; i += div_size){
        mini_array = (int*)malloc(div_size * sizeof(int));
        for(j = 0; j < div_size; j++){
          *(mini_array + j) = *(array_given + i + j);
          *(sending_array + k + j) = *(array_given + i + j);
          //printf("\n sarr %d ",*(sending_array + k + j) );
        }
        k = k + (div_size);
        /*printf("\n MINI ARRAYS ARE : ");
        for(j = 0; j < div_size; j++){
          printf("%d ",*(mini_array + j));
        }*/
      //  printf("\n");

}
        //fre e(mini_array);
        return sending_array;
}
/*int main(int argc, char** argv){
    assert(argc == 3);
     int i,j;
     int* big_array;
     int* small_array;
     int my_size, my_div;
     my_size = atoi(argv[1]);
     my_div = atoi(argv[2]);
     big_array = (int*)malloc(my_size * sizeof(int));
     int* arr = (int*)malloc((my_size/my_div) * my_div * sizeof(int));
     for(i = 0; i < my_size; i++){
       *(big_array + i) = i;
     }
     /*printf("THE BIG ARRAY IS: \n");
     for(i = 0; i < my_size; i++){
       printf("%d ", *(big_array + i));
     }*/
     /*arr = array_divide(big_array, my_div, my_size);
     printf(" \n ");
     printf("MATRIX TO BE SEND : \n");
       i = 0;
       while(i < my_size){
         for(j = 0; j < my_div; j++){
           printf("%d ",*(arr +i + j));
         }
         printf("\n");
         i = i + my_div;
       }
     /*for(i = 0; i < (my_size/my_div) * my_div; i++)
          printf("%d ", *(arr+i));*/
     /*for(i = 0; i < (my_size/my_div); i++){
       small_array = (int*)malloc(my_div * sizeof(int));
       small_array = array_divide(big_array, my_div, my_size);
       printf("SMALL_ARRAYS ARE : ");
       for(j = 0; j < my_div; j++)
        printf( " %d ", *(small_array + j));
        printf("\n");
       free(small_array);
     }*/




//}
