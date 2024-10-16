package functors.applicative.functor

import scala.language.higherKinds

/**
  * Applicative is an intermediate between functor and monad.
  *
  * Its importance are dominated by:
  *   - ability to apply functions of more parameters
  *     For example:
  *       val f = (x: Int)(y: Int) => x + y
  *       If we apply the above function to a functor Future(10).map(f),
  *         the result will be a Future(x => 10 + x). And you can't map that any further.
  *       A way to extract the result is needed, hence applicative functors, where you can do something like:
  *       val f = (x: Int)(y: Int) => x + y
  *       val r: Future[Int -> Int] = Future(10).map(f)
  *       Future(20).apply(r) => should return 30
  *
  *   - can apply functions wrapped into a functor context
  *
  *   - can combine multiple functors into one single product
  */

trait ApplicativeFunctor[F[_]] {
  def apply[A, B](fa: F[A])(f: F[A => B]): F[A] => F[B]
}
