#include "share/atspre_staload.hats"

sortdef T = t@ype

#define :: cons

datatype list (a:T) =
  | nil(a) of ()
  | cons(a) of (a, list(a))


extern fun{a:T}{b:T} map : (list(a), a -> b) -> list(b)

implement{a}{b} map(xs, f) =
  case+ xs of
    | nil() => nil()
    | cons(x, xs) => cons(f(x), map(xs, f))



implement main0() = {
  val xs = 1::2::3::4::nil() : list(int)
  val xs = map<int><int>(xs, lam x => x * 2)
}
