def count_stair_ways(n):
    """
    >>> count_stair_ways(1)
    1
    >>> count_stair_ways(2)
    2
    >>> count_stair_ways(3)
    3
    >>> count_stair_ways(4)
    5
    >>> count_stair_ways(5)
    8
    """
    count = 0
    # this is the base case. if there is only 1 stair, then you can only take 1 step
    # if there is 0 stairs you do not need to take any steps
    if n == 1 or n == 0:
        return 1
    
    # utilize the given recursive function, but we have to add them together
    # to total the amount of steps we need to take. 
    return count_stair_ways(n - 1) + count_stair_ways(n - 2)