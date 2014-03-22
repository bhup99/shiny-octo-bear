class Vertex:  
    def __init__(self, name):  
        self.name = name         
        self.distance = 1000         
        self.prev = None        
        self.flag = 0           
     
     
  
class EdgeSetdge:  
    def __init__(self, u, v, length):  
        self.start = u  
        self.end = v  
        self.length = length  
    
    
  
def generateGraph(V, EdgeSet):
    vtx= ['a','b','c','d','e','f','o','t']
    for x in vtx:
        V.append(Vertex(x))
        
    EdgeSet.append(EdgeSetdge('a','b',2))
    EdgeSet.append(EdgeSetdge('a','o',2))
    EdgeSet.append(EdgeSetdge('a','d',7))
    EdgeSet.append(EdgeSetdge('a','f',12))
    EdgeSet.append(EdgeSetdge('b','a',2))
    EdgeSet.append(EdgeSetdge('b','o',5))
    EdgeSet.append(EdgeSetdge('b','d',4))
    EdgeSet.append(EdgeSetdge('b','c',1))
    EdgeSet.append(EdgeSetdge('b','e',3))
    EdgeSet.append(EdgeSetdge('c','b',1))
    EdgeSet.append(EdgeSetdge('c','e',4))
    EdgeSet.append(EdgeSetdge('c','o',4))
    EdgeSet.append(EdgeSetdge('d','b',4))
    EdgeSet.append(EdgeSetdge('d','a',7))
    EdgeSet.append(EdgeSetdge('d','a',1))
    EdgeSet.append(EdgeSetdge('d','t',5))
    EdgeSet.append(EdgeSetdge('e','d',1))
    EdgeSet.append(EdgeSetdge('e','b',3))
    EdgeSet.append(EdgeSetdge('e','b',3))
    EdgeSet.append(EdgeSetdge('e','t',7))
    EdgeSet.append(EdgeSetdge('f','a',12))
    EdgeSet.append(EdgeSetdge('o','a',2))
    EdgeSet.append(EdgeSetdge('o','b',5))
    EdgeSet.append(EdgeSetdge('o','c',4))
    EdgeSet.append(EdgeSetdge('t','f',3))
    EdgeSet.append(EdgeSetdge('t','d',5))
    EdgeSet.append(EdgeSetdge('t','e',7))
        
   
  
def pickSmallestVertex(V):  
    minVertex = None  
    for vertex in V:  
        if vertex.flag == 0:  
            minVertex = vertex  
            break  
    if minVertex == None:  
        return minVertex  
    for vertex in V:  
        if vertex.flag == 0 and vertex.distance < minVertex.distance:  
            minVertex = vertex  
    return minVertex  
    
    
  
def pickEdgeSetdgesList(u, EdgeSet):  
    uv=[]  
    for edge in EdgeSet:
        
        if edge.start == u.name:
            uv.append(edge)  
    return uv  
    
def findShortestPath(V, EdgeSet, S, A):  
    for vertex in V:  
        if vertex.name == A:  
            vertex.distance = 0  
    
        u = pickSmallestVertex(V)  
        while u != None:  
            u.flag = 1
            
            uv = pickEdgeSetdgesList(u, EdgeSet)
                           
            v = None
            for edge in uv:  
                for vertex in V:  
                    if vertex.name == edge.end:  
                        v = vertex  
                        break  
                if v.distance > u.distance + edge.length:  
                    v.distance = u.distance + edge.length  
                    v.prev = u
                    
            u = pickSmallestVertex(V)  
              
    
 

def print_shortestpath(V):
    print ('distanceance from a is')
    for vertex in V:
        previous = vertex.prev       
        if previous == None:  
            print vertex.name,"\t", vertex.distance
        else:  
            print vertex.name,"\t", vertex.distance
          
            
def main():  
    V = []  
    EdgeSet = []  
    S = []  
    generateGraph(V, EdgeSet)       
    findShortestPath(V, EdgeSet, S, 'a')  
    print_shortestpath(V)  
        
main()  
