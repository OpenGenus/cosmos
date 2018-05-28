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
