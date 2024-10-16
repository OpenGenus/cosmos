from typing import Union, Callable, List

"""
    The Adams–Bashforth methods allow us explicitly
    to compute the approximate solution at an instant
    time from the solutions in previous instants.
    This module allows you compute approximations
    using fourth-order Adams-Bashforth method.

    Reference: https://www.sciencedirect.com/science/article
    /pii/S0898122110007777#:~:text=The%20Adams%E2%80%93Bashforth
    %20methods%20allow,by%20means%20of%20Newton's%20method.
"""


class AdamBashforth:
    """
    This class provides methods to compute the approximation
    solution of functions with Adam-Bashforth Predictor/Corrector
    methods.

    >>> adam = AdamBashforth()
    >>> adam.predict("1 + y**2", [0, 0.2, 0.4, 0.6], [0, 0.2027, 0.4228,
    ... 0.6841],0.2)
    1.023375031
    >>> adam.predict("(x+y)/2", [0, 0.5, 1, 1.5], [2, 2.636, 3.595, 4.968],0.5)
    6.87078125
    >>> adam.correct()
    6.873104492187499
    >>> adam.predict(lambda x, y: 1 + y**2, [0, 0.2, 0.4, 0.6], [0, 0.2027,
    ... 0.4228, 0.6841],0.2)
    1.023375031
    """

    def predict(
        self,
        function: Union[Callable[[float, float], float], str],
        x_points: List[float],
        y_points: List[float],
        h_val: float,
    ) -> float:
        """
        Use Adam-Bashford predictor method to compute the approximation
        of the function whose differential equation is given by
        dy/dx = function(x, y) at x = x_points[3]+h_val.
        """
        self.y_points = y_points
        self.x_points = x_points
        self.h_val = h_val
        if len(x_points) != 4 and len(y_points) != 4:
            raise Exception(
                "x_points and \
                y_points must be lists of 4 values respectively"
            )
        if isinstance(function, str):

            def func_(x, y):
                return eval(function.replace("x", str(x)).replace("y", str(y)))

        elif hasattr(function, "__call__"):
            func_ = function
        else:
            raise Exception("func_ must be a callable object or a string")

        self.func_ = func_

        self.pred = y_points[3] + (h_val / 24) * (
            (55 * func_(x_points[3], y_points[3]))
            - (59 * func_(x_points[2], y_points[2]))
            + (37 * func_(x_points[1], y_points[1]))
            - (9 * func_(x_points[0], y_points[0]))
        )

        return self.pred

    def correct(self) -> float:
        """
        Compute a corrected value of the prediction from
        the `predict` method.
        """
        func_ = self.func_
        x = self.x_points
        y = self.y_points
        h = self.h_val
        corrected = y[3] + (h / 24) * (
            9 * func_(x[3] + h, self.pred)
            + (19 * func_(x[3], y[3]))
            - (5 * func_(x[2], y[2]))
            + (func_(x[1], y[1]))
        )
        return corrected


if __name__ == "__main__":
    import doctest

    doctest.testmod()
