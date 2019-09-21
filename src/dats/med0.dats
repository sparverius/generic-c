sortdef T = t@ype

#define :: cons

datatype list (a:T) =
  | nil(a) of ()
  | cons(a) of (a, list(a))


extern
fun{a:T} foreach : (list(a), a -> void) -> void

implement{a} foreach(xs, f) =
    case+ xs of
      | cons(x, xs) => (f(x); foreach(xs, f))
      | nil() => ()

implement main0() = {
  val xs = 1::2::3::4::nil() : list(int)

  val () = foreach<int>(xs, lam x => print!(x, " "))
  val () = println!()
}
