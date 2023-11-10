package monads.monad

import scala.language.higherKinds

trait Monad[T, M[_]] {
  def flatMap[S](fA: T => M[S])(f: M[T]): M[S]
}

object MonadImplicits {
  implicit def listMonad[T]: Monad[T, List] = new Monad[T, List] {
    override def flatMap[S](fA: T => List[S])(f: List[T]): List[S] = f.flatMap(fA)
  }

  implicit def optionMonad[T]: Monad[T, Option] = new Monad[T, Option] {
    override def flatMap[S](fA: T => Option[S])(f: Option[T]): Option[S] = f.flatMap(fA)
  }
}
