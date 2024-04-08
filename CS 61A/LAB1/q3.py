#Question 3 JAY CHONG
def wears_jacket_with_if(temp, raining):
    """
    >>> wears_jacket_with_if(90, False)
    False
    >>> wears_jacket_with_if(40, False)
    True
    >>> wears_jacket_with_if(100, True)
    True
    """
    #Only returns a statement when temp < 60 or the boolean value of raining = True.
    return temp < 60 or raining

