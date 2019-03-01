# Banker's Algorithm
## Description
Banker's algorithm is an conservative algorithm to check if a resource can be granted to a process if it is not used by any process in the system. It is used for deadlock management.
## Logic
The algorithm relies on the following quantities:
* *R(k)*: total amount of resource R<sub>k</sub> presesnt in the system.
* *T<sub>i</sub>(k)*: total amount of resource R<sub>k</sub> that process P<sub>i</sub> will need during its execution.
* *A<sub>i</sub>(k)*: amount of R<sub>k</sub> currently allocated to process P<sub>i</sub>.
* *C(k)*: total amount of resource R<sub>k</sub> available currently in the system.
* *N<sub>i</sub>(k)*: amount of resource R<sub>k</sub> that process P<sub>i</sub> currently need to complete.

When a process request a certain resource R<sub>k</sub>, the banker's algorithm will determine if grant the resource will lead the system to **safe state**. The safe state is defined as for an arbitary sequence of execution of all processes in the system, if for each processes in the system, it is possible to allocate enough resources to finish each process, then the state is said to be safe. Clearly, if grant the resource will lead to safe state, deadlocks are avoided.The algorithm check if grant the resource will lead to safe state by checking if there is a sequence of execution that all processes will finish.

```
stateIsSafe():
  W(k) <- C(k) for each resource
  Pi <- init to CannotFinish
  while Pi exists and Pi CannotFinish and Ni(k) <= W(k) for all k
    Pi <- CanFinish
    W(k) <- W(k) + Ai(k) for all k
  endwhile
  if Pi CanFinish for all i
    return true
   else
    return false
  endif
end
```


