# Implement a complete binary tree of maximal hight h by means of an
# array. In a complete binary tree, every node has exactly two childs,
# except (perhaps) for the leaf level. Leaf nodes are all on the left
# side of the tree (or the tree is full).
# So the task is to map the binary tree structure to a linear array.
# Implement the find (key) operations.

######################################################################
# assignment 1, problem 1
# saket panwar, b11032, chimpinchief@gmail.com
import math

def mktree(a):
  """
  Given an array a. Return a tree.
  Format of tree: [root, left child, right child]
  """
  if len(a) < 4:
      return a

  ln = int(math.ceil( (len(a)-1) / 2.0 ))
  return [a.pop(0),
          mktree(a[:ln]),
          mktree(a[ln:])]

def is_key_there(t, key):
  """
  Return true if key is in tree t.
  """
  if type(t) is int:
      return t == key

  if key == t[0]:
      return True
  
  try:
      return is_key_there(t[1], key) or is_key_there(t[2], key)
  except:
      pass

  else:
      return False

tree = mktree([i for i in range(8)])
print is_key_there(tree, 7)
