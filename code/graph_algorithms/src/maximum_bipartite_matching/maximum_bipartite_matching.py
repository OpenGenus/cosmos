# Part of Cosmos by OpenGenus Foundation

""" Python program to find maximal Bipartite matching.
    This is taking corresponding to graph of applicants and 
    their corresponding job positions.
"""


class Graph:
    def __init__(self, graph):
        self.graph = graph  # residual graph
        self.ppl = len(graph)
        self.jobs = len(graph[0])

    # A DFS based recursive function that returns true if a
    # matching for vertex u is possible
    def bpm(self, u, matchR, seen):

        # Try every job one by one
        for v in range(self.jobs):

            # If applicant u is interested in job v and v is
            # not seen
            if self.graph[u][v] and seen[v] == False:
                seen[v] = True  # Mark v as visited

                """If job 'v' is not assigned to an applicant OR
                previously assigned applicant for job v (which is matchR[v]) 
                has an alternate job available. 
                Since v is marked as visited in the above line, matchR[v] 
                in the following recursive call will not get job 'v' again"""
                if matchR[v] == -1 or self.bpm(matchR[v], matchR, seen):
                    matchR[v] = u
                    return True
        return False

    # Returns maximum number of matching
    def maxBPM(self):
        """An array to keep track of the applicants assigned to
        jobs. The value of matchR[i] is the applicant number
        assigned to job i, the value -1 indicates nobody is
        assigned."""
        matchR = [-1] * self.jobs
        result = 0  # Count of jobs assigned to applicants
        for i in range(self.ppl):
            # Mark all jobs as not seen for next applicant.
            seen = [False] * self.jobs
            # Find if the applicant 'u' can get a job
            if self.bpm(i, matchR, seen):
                result += 1
        return result


bpGraph = [
    [0, 1, 1, 0, 0, 0],
    [1, 0, 0, 1, 0, 0],
    [0, 0, 1, 0, 0, 0],
    [0, 0, 1, 1, 0, 0],
    [0, 0, 0, 0, 0, 0],
    [0, 0, 0, 0, 0, 1],
]

g = Graph(bpGraph)

print("Maximum matching number of applicants that can get job is %d " % g.maxBPM())
