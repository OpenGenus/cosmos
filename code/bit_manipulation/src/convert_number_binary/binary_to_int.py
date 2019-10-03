# Part of Cosmos by OpenGenus Foundation


def binary_to_int(binary_input):
    """
    Parameters
    ----------
    binary_input : String
    Returns
    -------
    integer_output : Integer
    """
    integer_output = 0
    """
    it reads from the left most to the right most.
    Eventually the left-most is going to have the largest value added 
    to the integer output.
    """
    for digit in binary_input:
        integer_output = integer_output * 2 + int(digit)

    return integer_output


# test

sample_binary_input = "01111101"
print(
    "Integer value of "
    + sample_binary_input
    + " is "
    + str(binary_to_int(sample_binary_input))
)
