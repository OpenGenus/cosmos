package structures

case class Epsilon(precision: Int) {
  require(precision > 0 && precision < 16)

  def apply(coefficients: List[Double]) = {
    coefficients.map(c => Math.floor(c * this.decimalsPower) / this.decimalsPower)
  }

  def truncate(a: Double): Double = {
    Math.floor(a * this.decimalsPower) / this.decimalsPower
  }

  val decimalsPower: Double = Math.pow(10, precision)

  val toNegative10: Double = Math.pow(10, - precision)
}
