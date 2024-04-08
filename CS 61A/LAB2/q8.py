def is_prime(n):
    """
    >>> is_prime(10)
    False
    >>> is_prime(7)
    True
    """
    primeChecker = n - 1
   
    #run code while primechecker > 1
    while primeChecker > 1:
        #if that factor is divisible evenly then it is not prime
        if n % primeChecker == 0:
            return False
        #decrease the value by 1 and check if statement again
        primeChecker = primeChecker - 1
    #return True because then 1 becomes the only factor
    return True
