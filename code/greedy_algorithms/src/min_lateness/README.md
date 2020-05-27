# Scheduling tasks to minimize maximum lateness 
Given *n* tasks with their respective starting and finishing time, we would like to schedule the jobs in an order such that the maximum lateness for any task is minimized. 
Taking in consideration various possible greedy strategies, we at last decide that choosing jobs with nearest deadline gives best results. 

The algorithm for same can be devised as:
1. Sort the requests by their deadline
2. min_lateness = 0
3. start_time = 0
4. for i = 0 -> n
5.   min_lateness = max(min_lateness, (t[i] + start_time) - d[i])
6.   start_time += t[i]
7. return min_lateness; 

**Complexity**
* Time Complexity: O(nlogn)
* Space Complexity: O(1)

  
<p align="center">
	For more insights, refer to <a href="https://iq.opengenus.org/scheduling-to-minimize-lateness/">Scheduling to minimize lateness</a>
</p>

---
<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>
 
---
