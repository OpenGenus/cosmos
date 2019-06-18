# cosmos
> Your personal library of every algorithm and data structure code that you will ever encounter

# Von Neumann Cellular Automaton

Jonh Von Neumann worked for years on a simple model for a logical cellular automaton with the purpose of building a self-replicating machine. But what kind of logical organization would an automaton need to have in order to control itself in a way that it reproduces itself? To answer that, Von Neumann thought of logical operations and states with different objectives, capable of constructing and deconstructing other states on their own. This lead to the Von Neumann Cellular System.

## States

To maintain simplicity, Von Neumann limited the automaton to only 29 states, which is the minimum needed to build a self-replicating machine. These states can be divided into four groups:

 - The **blank state** or unexcitable state (**U**) is the basic and initial state; when it is excited it will become one of the transmission states or a confluent state. If another state has been deconstructed, that cell returns to the blank state.

 - The **transmission state** behaves like a conductor wire, where pulses and signals can move from one place another. They are sub-divided into ordinary transmission (represented by simple arrows in the four directions: → ↓ ← ↑) and special transmission (represented by double arrows). This separation is justified because of the deconstruction mechanism which will be discussed later. Each one of the directions has two states, the unexcited and excited one. All in all, we have 16 transmission states which transport binary pulses to the cell that it is pointing for. They can receive these signals from other transmission states or from a confluent state.

 - The **confluent states** (**C**) are four in total. This element can be used as a bridge for communication between the ordinary transmission states and the special transmission states. It also has a delay of one unit of time to receive the input and release from other states. The four Confluent States are all the combinations of 1's and 0's for two digits (C<sub>00</sub> C<sub>01</sub> C<sub>10</sub>, C<sub>11</sub>) representing this delay. To become excited, a confluent element has to receive a pulse from all the neighbors transmission states which are pointing at it, simulation a AND port (the transmission states simulated a OR port). After the delay, the state releases the information at all the neighbor's transmission states that are not pointing directly at it. Confluent states do not transmit information to another confluent state.

 - The **transition states** or sensitive states (**S**) are used to construct all the others starting from a blank state. The output states are created according to the signals that cells receive during their transition process. So, to be able to create all the nine quiescent states (C00 and the unexcited transmission states) there are eight transition states (S, S<sub>0</sub>, S<sub>00</sub>, S<sub>000</sub>, S<sub>01</sub>, S<sub>1</sub>, S<sub>10</sub>, S<sub>11</sub>)

![Von Neumann's states](https://iq.opengenus.org/content/images/2019/02/States.png)

## Construction

The construction mechanism starts when a blank state (**U**) is excited by a transmission state in its neighborhood. At this moment the cell becomes **"sensitive"** (**S**), passing through the transition states until it stops in one of the ordinary or special transmission states, or in a confluent state. The chosen state is determined by the sequence of input signals that arrive on that cell. The options of that sequence can be represented by a binary tree.

![Binary Tree for the Construction Mechanism](https://iq.opengenus.org/content/images/2019/02/ChoiceTree.png)

## Deconstruction

Von Neumann builds your automaton model to be able to deconstruct cells back to the blank state (**U**). Some additional rules determinate the situations where a cell will be destroyed.

 - If a confluent state receives an input from a special transmission state that confluent state will be reduced to U.
 - If an ordinary transmission state receives an input from a special transmission state that ordinary transmission state will be reduced to U.
 - if a special transmission state receives an input from an ordinary transmission state that special transmission state will be reduced to U.

---

<p align="center">
	A massive collaborative effort by <a href="https://github.com/OpenGenus/cosmos">OpenGenus Foundation</a> 
</p>

---
