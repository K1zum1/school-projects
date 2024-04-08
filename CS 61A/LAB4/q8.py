def ten_pairs(n):
    """Return the number of ten-pairs within positive integer n.
    >>> ten_pairs(7823952)
    3
    >>> ten_pairs(55055)
    6
    >>> ten_pairs(9641469)
    6
    """
    def digit_helper(d, nu):
        
        if nu < 10 and nu!= d:
            # the base case, if number is less than 10 and not equal to 'd', return 0
            return 0
        elif nu % 10 == d:
            # if the last digit is d, increment by 1 and call the count recursively
            return 1 + digit_helper(d, nu // 10)
        elif nu < 10 and nu == d:
            # if the number is less than 10 and equal to d, return 1 instead
            return 1
        else:
            # otherwise, recursively call on the remaining digits
            return digit_helper(d, nu // 10)

    def helper_ten_pairs(x):
        
        if x < 10:
            # if number is less than 10, return 0 since there cannot be any pairs
            return 0
        else:
            # call count_digit to count the number of times the complement of the last digit
            # then, add this count to the count of ten-pairs in the remaining digits. This way we return
            # all the possible pairs
            return digit_helper(10 - x % 10, x // 10) + helper_ten_pairs(x // 10)

    # call the helper function on the input number n to get the total count of ten-pairs
    return helper_ten_pairs(n)