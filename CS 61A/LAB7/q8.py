def make_joint(withdraw, old_password, new_password):
    """Return a password-protected withdraw function that has joint access to
    the balance of withdraw.

    >>> w = make_withdraw(100, 'hax0r')
    >>> w(25, 'hax0r')
    75
    >>> make_joint(w, 'my', 'secret')
    'Incorrect password'
    >>> j = make_joint(w, 'hax0r', 'secret')
    >>> w(25, 'secret')
    'Incorrect password'
    >>> j(25, 'secret')
    50
    >>> j(25, 'hax0r')
    25
    >>> j(100, 'secret')
    'Insufficient funds'

    >>> j2 = make_joint(j, 'secret', 'code')
    >>> j2(5, 'code')
    20
    >>> j2(5, 'secret')
    15
    >>> j2(5, 'hax0r')
    10

    >>> j2(25, 'password')
    'Incorrect password'
    >>> j2(5, 'secret')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    >>> j(5, 'secret')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    >>> w(5, 'hax0r')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    >>> make_joint(w, 'hax0r', 'hello')
    "Your account is locked. Attempts: ['my', 'secret', 'password']"
    """
    # we use the withdraw function to test if the old_password is correct
    error = withdraw(0, old_password)
    # we use the type error suggested by the lab to test if the value of the error
    # is a string or not, if it is a string then we return error
    if type(error) == str:
            return error
    # if it isnt a string then we can define the function joint 
    # that takes in amount and attempt
    def joint(amount, attempt):
        # if the attempt is equal to the new password taken in by the make_joint function
        if attempt == new_password:
            # then we can return the withdraw function with the amount and the old password
            return withdraw(amount, old_password)
        else:
            # otherwise return amount and attempt
            return withdraw(amount, attempt)
    # return the join function so that we can use it later
    return joint

def make_withdraw(balance, password):
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

