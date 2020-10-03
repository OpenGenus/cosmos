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
trait Functor[A, F[_]] {
  // something might be fishy with the id
  def id: A
  def fmap[B](fA: F[A])(f: A => B): F[B]
}

object FunctorImplicits {
  implicit def listFunctor[A]: Functor[A, List] = new Functor[A, List] {
    override def id: A = ???

    override def fmap[B](fA: List[A])(f: A => B): List[B] = fA.map(f)
  }

  implicit def optionFunctor[A]: Functor[A, Option] = new Functor[A, Option] {
    override def id: A = ???

    override def fmap[B](fA: Option[A])(f: A => B): Option[B] = fA.map(f)
  }
}
