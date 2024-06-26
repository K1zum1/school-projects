
#Constructor
def tree(label, branches=[]):
    for branch in branches:
        assert is_tree(branch)
    return [label] + list(branches)

#Selectors
def label(tree):
    return tree[0]

def branches(tree):
    return tree[1:]

def is_tree(tree):
    if type(tree) != list or len(tree) < 1:
        return False
    return True

def is_leaf(tree):
    return not branches(tree)

#Test Trees
t1 = tree(3, [tree(1), tree(2, [tree(1), tree(1)])])
t2 = tree('A', [tree('B'), tree('C', [tree('D'), tree('E')])])
t3 = tree(8,
          [tree(4,
                [tree(2), tree(3)]),
           tree(3,
                [tree(1), tree(1,
                               [tree(1), tree(1)])])])
def print_tree(t, indent=0):
    print('  ' * indent + str(label(t)))
    for b in branches(t):
        print_tree(b, indent + 1)
        
def height(t): 
    """Return the height of a tree. 
    >>> t = tree(3, [tree(5, [tree(1)]), tree(2)]) 
    >>> height(t) 
    2
    """
    # if the tree is a leaf then we simply return 0 because there is no height
    if is_leaf(t):
        return 0
    else:
        # otherwise return the max value, of height iterated by x through branches(t) 
        # we add one to account for the root branch at the top
        height1 = max(height(x) for x in branches(t)) + 1
        # simply return the value
        return height1