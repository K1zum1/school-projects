#Question 2 JAY CHONG
from math import pi
def sphere_area(r):
    """
    >>> sphere_area(4)
    201.06192982974676
    >>> sphere_area(5)
    314.1592653589793
    """
   
    """Area of a sphere with radius r."""
    return (pow(r,2) * 4 * pi)


def sphere_volume(r):
    """
    >>> sphere_volume(4)
    268.082573106329
    >>> sphere_volume(5)
    523.5987755982989
    """
   
    """Volume of a sphere with radius r."""
    return (pow(r,3) * (4/3) * pi)
