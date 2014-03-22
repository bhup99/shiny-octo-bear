# A common but insecure method of encrypting text is to permute the
# letters of the alphabet. In other words, each letter of the alphabet
# is consistently replaced in the text by some other letter. To ensure
# that the encryption is reversible, no two letters are replaced by
# the same letter. Your task is to decrypt several encoded lines of
# text, assuming that each line uses a different set of replacements,
# and that all words in the decrypted text are from a dictionary of
# known words.
#
# Input
# The input consists of a line containing an integer n, followed by n
# lowercase words, one per line, in alphabetical order. These n words
# compose the dictionary of words which may appear in the decrypted
# text. Following the dictionary are several lines of input. Each line
# is encrypted as described above.
# There are no more than 1,000 words in the dictionary. No word
# exceeds 16 letters. The encrypted lines contain only lower case
# letters and spaces and do not exceed 80 characters in length.
#
# Output
# Decrypt each line and print it to standard output. If there are
# multiple solutions, any one will do. If there is no solution,
# replace every letter of the alphabet by an asterisk.
#
# Sample Input
# 6
# and
# dick
# jane
# puff
# spot
# yertle
# bjvg xsb hxsn xsb qymm xsb rqat xsb pnetfn
# xxxx yyy zzzz www yyyy aaa bbbb ccc dddddd
#
# Sample Output
# dick and jane and puff and spot and yertle
# **** *** **** *** **** *** **** *** ******

######################################################################
# assignment 1, problem 5
# saket panwar, b11032, chimpinchief@gmail.com
# to run this program, please type
#     $: cat input.txt | python cipher.py
# in the terminal.
import copy

##
## build the dictionary
num_dict_words = input()
dict_words = {}
for i in xrange(num_dict_words):
  word = raw_input()
  word_length = len(word)
  try:
    if dict_words[word_length]:
      dict_words[word_length].append(word)
    else:
      pass
  except:
    dict_words[word_length] = [word]

##
def build_char_map(dict_words, input_word_set, black_list=[]):
  """
  This function takes a list of certified words, dict_words,
  a "set" of words, an input_word_set and a black list of words
  and returns a map of characters which translate the words in
  input_word_set into valid words contained in dict_words.
  """
  dw = copy.deepcopy(dict_words)
  char_map = {}
  for word in input_word_set:
    complement = dw[len(word)].pop()
    for i in xrange(len(word)):
      if word[i] not in char_map:
        char_map[word[i]] = complement[i]
      elif char_map[word[i]] != complement[i]:
        if word in black_list:
          return build_char_map(dict_words, input_word_set[1:] + \
                                            input_word_set[:1])
        else:
          input_word_set.append(input_word_set.pop(input_word_set.index(word)))
          return build_char_map(dict_words, input_word_set, black_list+[word])
      else:
        pass

  return char_map

##
## stuff starts here
actual_line = raw_input()
input_word_set = list(set(actual_line.split()))
while actual_line != 'q':
  
  try:
    char_map = build_char_map(dict_words, input_word_set)
  except RuntimeError, er:
    char_map = {}
    for character in 'abcdefghijklmnopqrstuvwxyz':
      char_map[character] = '*'

  ##
  ## build the response now that we can decrypt the input
  response = ''
  for character in actual_line:
    if character is ' ':
      response += ' '
    else:
      response += char_map[character]

  print response
  
  # iterate again
  # type 'q' to quit
  actual_line = raw_input()
  input_word_set = list(set(actual_line.split()))
