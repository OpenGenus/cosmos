package functors.bifunctor

import scala.language.higherKinds

/**
  *
  *  Similar to a functor, the BiFunctor must satisfy the functor laws:
  *   1. bimap f id id  = id
  *      first f id = id
  *      second f id = id
  *
  *      Applying a function over the identity, should return the identity.
  *
  *   2. bimap f g = first f . second g
  *
  *     Asociativity: applying bimap f g should be equal to applying f to first and g to second.
  *
  *   BiFunctors include: Either, N-Tuples
  */
trait BiFunctor[F[_, _]] {
  def biMap[A, B, C, D](fab: F[A, B])(f: A => C)(g: B => D): F[B, D]

  def first[A, C](fab: F[A, _])(f: A => C): F[C, _]

  def second[B, D](fab: F[_, B])(f: B => D): F[_, D]
}
