from numbers import Number
from collections import namedtuple


# noinspection PyBroadException
class Interval(namedtuple('IntervalBase', ['begin', 'end', 'data'])):
    __slots__ = ()  # Saves memory, avoiding the need to create __dict__ for each interval

    def __new__(cls, begin, end, data=None):
        return super(Interval, cls).__new__(cls, begin, end, data)
    
    def overlaps(self, begin, end=None):
        """
        Whether the interval overlaps the given point, range or Interval.
        :param begin: beginning point of the range, or the point, or an Interval
        :param end: end point of the range. Optional if not testing ranges.
        :return: True or False
        :rtype: bool
        """
        if end is not None:
            return (
                (begin <= self.begin < end) or
                (begin < self.end <= end) or
                (self.begin <= begin < self.end) or
                (self.begin < end <= self.end)
            )
        try:
            return self.overlaps(begin.begin, begin.end)
        except:
            return self.contains_point(begin)

    def contains_point(self, p):
        """
        Whether the Interval contains p.
        :param p: a point
        :return: True or False
        :rtype: bool
        """
        return self.begin <= p < self.end
    
    def range_matches(self, other):
        """
        Whether the begins equal and the ends equal. Compare __eq__().
        :param other: Interval
        :return: True or False
        :rtype: bool
        """
        return (
            self.begin == other.begin and 
            self.end == other.end
        )
    
    def contains_interval(self, other):
        """
        Whether other is contained in this Interval.
        :param other: Interval
        :return: True or False
        :rtype: bool
        """
        return (
            self.begin <= other.begin and
            self.end >= other.end
        )
    
    def distance_to(self, other):
        """
        Returns the size of the gap between intervals, or 0 
        if they touch or overlap.
        :param other: Interval or point
        :return: distance
        :rtype: Number
        """
        if self.overlaps(other):
            return 0
        try:
            if self.begin < other.begin:
                return other.begin - self.end
            else:
                return self.begin - other.end
        except:
            if self.end < other:
                return other - self.end
            else:
                return self.begin - other

    def is_null(self):
        """
        Whether this equals the null interval.
        :return: True if end <= begin else False
        :rtype: bool
        """
        return self.begin >= self.end

    def length(self):
        """
        The distance covered by this Interval.
        :return: length
        :type: Number
        """
        if self.is_null():
            return 0
        return self.end - self.begin

    def __hash__(self):
        """
        Depends on begin and end only.
        :return: hash
        :rtype: Number
        """
        return hash((self.begin, self.end))

    def __eq__(self, other):
        """
        Whether the begins equal, the ends equal, and the data fields
        equal. Compare range_matches().
        :param other: Interval
        :return: True or False
        :rtype: bool
        """
        return (
            self.begin == other.begin and
            self.end == other.end and
            self.data == other.data
        )

    def __cmp__(self, other):
        """
        Tells whether other sorts before, after or equal to this
        Interval.
        Sorting is by begins, then by ends, then by data fields.
        If data fields are not both sortable types, data fields are
        compared alphabetically by type name.
        :param other: Interval
        :return: -1, 0, 1
        :rtype: int
        """
        s = self[0:2]
        try:
            o = other[0:2]
        except:
            o = (other,)
        if s != o:
            return -1 if s < o else 1
        try:
            if self.data == other.data:
                return 0
            return -1 if self.data < other.data else 1
        except TypeError:
            s = type(self.data).__name__
            o = type(other.data).__name__
            if s == o:
                return 0
            return -1 if s < o else 1

    def __lt__(self, other):
        """
        Less than operator. Parrots __cmp__()
        :param other: Interval or point
        :return: True or False
        :rtype: bool
        """
        return self.__cmp__(other) < 0

    def __gt__(self, other):
        """
        Greater than operator. Parrots __cmp__()
        :param other: Interval or point
        :return: True or False
        :rtype: bool
        """
        return self.__cmp__(other) > 0

    def _raise_if_null(self, other):
        """
        :raises ValueError: if either self or other is a null Interval
        """
        if self.is_null():
            raise ValueError("Cannot compare null Intervals!")
        if hasattr(other, 'is_null') and other.is_null():
            raise ValueError("Cannot compare null Intervals!")

    def lt(self, other):
        """
        Strictly less than. Returns True if no part of this Interval
        extends higher than or into other.
        :raises ValueError: if either self or other is a null Interval
        :param other: Interval or point
        :return: True or False
        :rtype: bool
        """
        self._raise_if_null(other)
        return self.end <= getattr(other, 'begin', other)

    def le(self, other):
        """
        Less than or overlaps. Returns True if no part of this Interval
        extends higher than other.
        :raises ValueError: if either self or other is a null Interval
        :param other: Interval or point
        :return: True or False
        :rtype: bool
        """
        self._raise_if_null(other)
        return self.end <= getattr(other, 'end', other)

    def gt(self, other):
        """
        Strictly greater than. Returns True if no part of this Interval
        extends lower than or into other.
        :raises ValueError: if either self or other is a null Interval
        :param other: Interval or point
        :return: True or False
        :rtype: bool
        """
        self._raise_if_null(other)
        if hasattr(other, 'end'):
            return self.begin >= other.end
        else:
            return self.begin > other

    def ge(self, other):
        """
        Greater than or overlaps. Returns True if no part of this Interval
        extends lower than other.
        :raises ValueError: if either self or other is a null Interval
        :param other: Interval or point
        :return: True or False
        :rtype: bool
        """
        self._raise_if_null(other)
        return self.begin >= getattr(other, 'begin', other)

    def _get_fields(self):
        """
        Used by str, unicode, repr and __reduce__.
        Returns only the fields necessary to reconstruct the Interval.
        :return: reconstruction info
        :rtype: tuple
        """
        if self.data is not None:
            return self.begin, self.end, self.data
        else:
            return self.begin, self.end
    
    def __repr__(self):
        """
        Executable string representation of this Interval.
        :return: string representation
        :rtype: str
        """
        if isinstance(self.begin, Number):
            s_begin = str(self.begin)
            s_end = str(self.end)
        else:
            s_begin = repr(self.begin)
            s_end = repr(self.end)
        if self.data is None:
            return "Interval({0}, {1})".format(s_begin, s_end)
        else:
            return "Interval({0}, {1}, {2})".format(s_begin, s_end, repr(self.data))

    __str__ = __repr__

    def copy(self):
        """
        Shallow copy.
        :return: copy of self
        :rtype: Interval
        """
        return Interval(self.begin, self.end, self.data)
    
    def __reduce__(self):
        """
        For pickle-ing.
        :return: pickle data
        :rtype: tuple
        """
        return Interval, self._get_fields()
