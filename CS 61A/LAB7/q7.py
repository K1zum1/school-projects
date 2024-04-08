def make_withdraw(balance, password):
    """Return a password-protected withdraw function.
    >>> w = make_withdraw(100, 'hax0r')
    >>> w(25, 'hax0r')
    75
    >>> error = w(90, 'hax0r')
    >>> error
    'Insufficient funds'
    >>> error = w(25, 'hwat')
    >>> error
    'Incorrect password'
    >>> new_bal = w(25, 'hax0r')
    >>> new_bal
    50
    >>> w(75, 'a')
    'Incorrect password'
    >>> w(10, 'hax0r')
    40
    >>> w(20, 'n00b')
    'Incorrect password'
    >>> w(10, 'hax0r')
    "Your account is locked. Attempts: ['hwat', 'a', 'n00b']"
    >>> w(10, 'l33t')
    "Your account is locked. Attempts: ['hwat', 'a', 'n00b']"
    >>> type(w(10, 'l33t')) == str
    True
    """
    # create a list to store the incorrect passwords
    count_attempts = []

    # define a function that takes amount, and attempt
    def withdraw(amount, attempt):
        # make the variables non local
        nonlocal balance, password, count_attempts
        # if the length of the list is equal to 3, then return this string 
        # which will print the the phrase and the list of the incorrect passwords
        # len checks the length of the count_attempts list
        if len(count_attempts) == 3:
            return "Your account is locked. Attempts: " + str(count_attempts)
        # else if the attempt is not equal to the password then append the attempt
        # to the list we made and return the string
        elif attempt != password:
            count_attempts.append(attempt)
            return "Incorrect password"
        # or if amount if bigger than the availible balance then return the string
        elif amount > balance:
            return "Insufficient funds"
        # if the balance is sufficient then we can subtract the amount
        # from the balance and then return whatever is left
        else:
            balance -= amount
            return balance
    # return the function
    return withdraw
