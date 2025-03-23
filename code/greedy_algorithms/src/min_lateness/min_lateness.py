def minimize_lateness(ttimes, dtimes):
    """Return minimum max lateness and the schedule to obtain it.
 
    (min_lateness, schedule) is returned.
 
    Lateness of a request i is L(i) = finish time of i - deadline of if
    request i finishes after its deadline.
    The maximum lateness is the maximum value of L(i) over all i.
    min_lateness is the minimum value of the maximum lateness that can be
    achieved by optimally scheduling the requests.
 
    schedule is a list that contains the indexes of the requests ordered such
    that minimum maximum lateness is achieved.
 
    ttime[i] is the time taken to complete request i.
    dtime[i] is the deadline of request i.
    """
    # index = [0, 1, 2, ..., n - 1] for n requests
    index = list(range(len(dtimes)))
    # sort according to deadlines
    index.sort(key=lambda i: dtimes[i])
 
    min_lateness = 0
    start_time = 0
    for i in index:
        min_lateness = max(min_lateness,
                           (ttimes[i] + start_time) - dtimes[i])
        start_time += ttimes[i]
 
    return min_lateness, index
 
 
n = int(input('Enter number of requests: '))
ttimes = input('Enter the time taken to complete the {} request(s) in order: '
              .format(n)).split()
ttimes = [int(tt) for tt in ttimes]
dtimes = input('Enter the deadlines of the {} request(s) in order: '
               .format(n)).split()
dtimes = [int(dt) for dt in dtimes]
 
min_lateness, schedule = minimize_lateness(ttimes, dtimes)
print('The minimum maximum lateness:', min_lateness)
print('The order in which the requests should be scheduled:', schedule)
