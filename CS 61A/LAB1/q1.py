def twenty_twenty_three():
    """Come up with the most creative expression that evaluates
    to 2023,using only numbers and the +, *, and - operators.
    >>> twenty_twenty_three()
    2023
    """
    return ((3 * 5) + 2) * ((2 * 60) - 1)

from operator import add, mul, sub
def twenty_twenty_three():
    """Come up with the most creative expression that evaluates
    to 2023,using only numbers and the +, *, and - operators.
    >>> twenty_twenty_three()
    2023
    """
    return mul(mul(17, 17), add(6,1))