class Node(object):

	def __init__(self, key = None, location = [None]*2, left_child = None, right_child = None):
		self.key = key
		self.location = location
		self.left_child = left_child
		self.right_child = right_child

def kdtree(point_list, depth=0):
	if not point_list:
       		return None
   	k = len(point_list[0])
   	axis = depth % k
   	if len(point_list) == 1:
		leaf = Node()
   		leaf.key = point_list[0][axis] 
   		leaf.location = point_list[0]
    		return leaf
 
	point_list.sort(key=lambda point: point[axis])
	if len(point_list) == 2:
   		median = 0
   	else:
   		median = len(point_list) // 2 
 
    	node = Node()
   	node.key = point_list[median][axis]
   	node.left_child = kdtree(point_list[:median + 1], depth + 1)
   	node.right_child = kdtree(point_list[median + 1:], depth + 1)
   	return node

def inorder(node):
	if node == None:
		return
	inorder(node.left_child)
	if node.location[0] != None:
		print node.location
	inorder(node.right_child)

def range_query(node,min_x,max_x,min_y,max_y):
	if node == None:
		return
	range_query(node.left_child,min_x,max_x,min_y,max_y)
	if node.location[0] != None:
		if min_x <= node.location[0] <=max_x and min_y <= node.location[1] <=max_y:
			print node.location
	range_query(node.right_child,min_x,max_x,min_y,max_y)


n = input("Enter the number of points ")
p = [[0 for x in range(2)] for x in range(n)]
print "Enter the (x,y) co_ordi of all points"
for i in range(n):
	co_ordi = raw_input()
	co_ordi = co_ordi.split()
	p[i][0] = int(co_ordi[0])
	p[i][1] = int(co_ordi[1])

root = kdtree(p)
inorder(root)

query = [[0 for x in range(2)] for x in range(2)]
print "Enter the range of the query"
for i in range(2):
	co_ordi = raw_input()
	co_ordi = co_ordi.split()
	query[i][0] = int(co_ordi[0])
	query[i][1] = int(co_ordi[1])

min_x = min(query[0][0], query[1][0])
max_x = max(query[0][0], query[1][0])
min_y = min(query[0][1], query[1][1])
max_y = max(query[0][1], query[1][1])

range_query(root,min_x,max_x,min_y,max_y)
