#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef void* boxed;
typedef void* funptr;

typedef struct {
  int x ;
  boxed xs ;
} type_list ;

void foreach(boxed list, funptr f)
{
  int next_x;
  void* next_xs; // boxed

__loop:
  do {
    if ((0 == (void*)(list))) { goto __end; } // nil => ()

    next_x = ((type_list*)list)->x;
    next_xs = ((type_list*)list)->xs;

    // cons(x, xs) =>  f(x)
    ((void(*)(int))(f))(next_x);

    list = next_xs;

    goto __loop;

  __end:
    break;

  } while(0);

  return;
}

void __lam_fun(int x)
{
  fprintf(stdout, "%d ", x);
  return;
}

int main()
{
  type_list* cons0;
  type_list* cons1;
  type_list* cons2;
  type_list* cons3;
  void* nil;

  nil = ((void*)0);

  cons3 = malloc(sizeof(type_list));
  cons2 = malloc(sizeof(type_list));
  cons1 = malloc(sizeof(type_list));
  cons0 = malloc(sizeof(type_list));

  cons3->x = 4;
  cons3->xs = nil;

  cons2->x = 3;
  cons2->xs = cons3;

  cons1->x = 2;
  cons1->xs = cons2;

  cons0->x = 1;
  cons0->xs = cons1;

  foreach(cons0, __lam_fun);

  fprintf(stdout, "\n");
}
