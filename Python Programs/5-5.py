def levenshtein(str1, str2):
    l1 = len(str1)
    l2 = len(str2)

    matrix = [range(l1 + 1)] * (l2 + 1)
    for i in range(l2 + 1):
      matrix[i] = range(i,i + l1 + 1)
    for i in range(0,l2):
      for j in range(0,l1):
        if str1[j] == str2[i]:
          matrix[i+1][j+1] = min(matrix[i+1][j] + 1, matrix[i][j+1] + 1, matrix[i][j])
        else:
          matrix[i+1][j+1] = min(matrix[i+1][j] + 1, matrix[i][j+1] + 1, matrix[i][j] + 1)
    return matrix[l2][l1]


str1 = raw_input('Enter first word: ')
str2 = raw_input('Enter second word: ')


distance = levenshtein(str1, str2)		
print 'The Levenshtein distance of ',str1, ' and ', str2, ' is ', distance
