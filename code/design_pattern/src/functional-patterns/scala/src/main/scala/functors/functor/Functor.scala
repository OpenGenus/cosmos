package functors.functor

import scala.language.higherKinds

/**
  * ADT which aspires to be a functor must preserve 2 laws:
  *   1. fmap over the identity functor of the ADT should coincide with the original ADT
  *     fmap(identity, adt) === adt
  *
  *   2. The composition of 2 functions and mapping the resulting function over a functor
  *     should be the same as mapping the first function over the functor and then the second one.
  *     fmap(f compose g, adt) === fmap(f, fmap(g, adt))
  *
  * Some functors include: List, Set, Map, Option, etc.
  */
trait Functor[F[_]] {
  def fmap[A, B](fA: F[A])(f: A => B): F[B]
}