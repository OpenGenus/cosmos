package monads.monad

import scala.language.higherKinds

trait Monad[M[_]] {
  def map[S, T](f: T => S): M[S]
  def flatMap[T,S](f: T => M[S]): M[S]
}
