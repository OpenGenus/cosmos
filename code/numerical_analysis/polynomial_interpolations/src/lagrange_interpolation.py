"""
    This program provides functionalities to carry out polynomial
    interpolation using Lagrange's polynomials.
    Reference: https://en.wikipedia.org/wiki/Lagrange_polynomial.
"""


class Lagrange:
    """
    This class implements interpolation using Lagrange's polynomial,
    For a given set of points (xj, yj) with no two xj values equal,
    the Lagrange polynomial is the polynomial of lowest degree that
    assumes at each value xj the corresponding value yj, so that the
    functions coincide at each point.

    >>> lagrange = Lagrange()
    >>> lagrange.fit([1, 2, 3], [7, 8, 9])
    >>> lagrange.interpolate(4)
    10.0
    >>> lagrange.interpolate(-2)
    4.0
    """

    def __init__(self):
        self.build_str = ""

    def fit(self, x_points: list, y_points: list) -> None:
        """
        Set up a the appropriate polynomial string for x_points, y_points
        values.

        Arguments:
            x_points, y_points: A list of x and corresponding y points
            through which the polynomial passes.
        """

        k = len(x_points)
        if k != len(y_points):
            raise Exception("x_points and y_points must be of the same length")
        build_str = ""
        for j in range(k):
            build_l = ""
            el = "((x - {xm}) / ({xj} - {xm}))"
            for m in range(k):
                if j != m:
                    build_l += el.format(xm=x_points[m], xj=x_points[j]) + " * "
            build_l = build_l[:-2]
            build_str += str(y_points[j]) + "*" + build_l + " + "

        self.build_str = build_str[:-2]

    def interpolate(self, x: float) -> float:
        """
        Interpolate the value of the polynomial at x for the fitted values.
        Returns the interpolated value.
        """
        ev = self.build_str.replace("x", str(x))
        return eval(ev)


if __name__ == "__main__":
    import doctest

    doctest.testmod()
