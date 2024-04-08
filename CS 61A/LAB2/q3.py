def two_of_three(a, b, c):
    """Return x*x + y*y, where x and y are the two largest members of the
    positive numbers a, b, and c.


    >>> two_of_three(1, 2, 3)
    13
    >>> two_of_three(5, 3, 1)
    34
    >>> two_of_three(10, 2, 8)
    164
    >>> two_of_three(5, 5, 5)
    50
    """
    #first get the max of the 3 digits
    # to find the second highest digit we must combined all 3 digits and subtract the highest and lowest to find the middle number
    return pow(max(a, b, c),2) + pow((a + b + c - max(a, b, c) - min(a, b, c)),2)