#include <stdlib.h>

typedef void* boxed;
typedef void* funptr;

typedef struct {
  int x;
  boxed xs;
} type_list;

static boxed map(boxed arg0, funptr arg1)
{
  boxed tmpret4;
  int tmp5;
  boxed tmp6;
  int tmp7;
  boxed tmp8;

  do {
    if ((0 != (void*)(arg0))) {
      goto __atstmplab;
    };
    tmpret4 = ((void*)0);
    break;

  __atstmplab:
    tmp5 = ((type_list*)arg0)->x;
    tmp6 = ((type_list*)arg0)->xs;
    tmp7 = ((int(*)(int))(arg1))(tmp5);

    tmp8 = map(tmp6, arg1);

    tmpret4 = malloc(sizeof(type_list));
    ((type_list*)(tmpret4))->x = tmp7;
    ((type_list*)(tmpret4))->xs = tmp8;
    break;

  } while(0);

  return (tmpret4);
}

static int __patsfun_4(int arg0)
{
  int tmpret21;

  tmpret21 = arg0 * 2;

  return (tmpret21);
}

int main()
{
  type_list* cons0;
  type_list* cons1;
  type_list* cons2;
  type_list* cons3;
  type_list* nil;
  type_list* result;

  nil = ((void*)0);

  cons3 = malloc(sizeof(type_list));
  cons2 = malloc(sizeof(type_list));
  cons1 = malloc(sizeof(type_list));
  cons0 = malloc(sizeof(type_list));

  cons3->x = (4);
  cons3->xs = nil;

  cons2->x = (3);
  cons2->xs = cons3;

  cons1->x = (2);
  cons1->xs = cons2;

  cons0->x = (1);
  cons0->xs = cons1;

  result = map(cons0, __patsfun_4);

  /* foreach(tmp15, (__patsfun_7)) ; */
  /* atspre_fprint_newline(stdout) ; */

  /* return 0; */
}
