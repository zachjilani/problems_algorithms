"""
There is an undirected star graph consisting of n nodes
labeled from 1 to n. A star graph is a graph where there
is one center node and exactly n - 1 edges that connect
the center node with every other node.

You are given a 2D integer array edges where each
edges[i] = [ui, vi] indicates that there is an edge
between the nodes ui and vi. Return the center of
the given star graph.
"""

def findCenter(self, edges):
  """
  :type edges: List[List[int]]
  :rtype: int
  """
  counts = {}
  for e in edges:
    self.addCount(counts, e[0])
    self.addCount(counts, e[1])
  return max([[k, counts[k]] for k in counts.keys()], key = lambda i: i[1])[0]

def addCount(self, counter, num):
  if num not in counter:
    counter[num] = 0
  counter[num]+=1
