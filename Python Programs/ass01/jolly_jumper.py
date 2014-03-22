# A sequence of n > 0 integers is called a jolly jumper if the
# absolute values of the differences between successive elements take
# on all possible values 1 through n - 1. For instance, 1 4 2 3 is a
# jolly jumper, because the absolute differences are 3, 2, and 1,
# respectively. The definition implies that any sequence of a single
# integer is a jolly jumper. Write a program to determine
# whether each of a number of sequences is a jolly jumper.

######################################################################
# assignment 1, problem 3
# saket panwar, b11032, chimpinchief@gmail.com

sample_seq = [1, 4, 2, 3]

def is_jolly(seq):
  ln = len(seq)
  tmp = [0] * (ln-1)
  for i in range(ln-1):
    tmp[i] = abs(seq[i+1]-seq[i])

  tmp.sort()
  for i in range(ln-1):
    if i+1 != tmp[i]:
      return False

  return True

print is_jolly(sample_seq)
