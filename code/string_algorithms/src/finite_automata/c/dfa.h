/*
 * Part of Cosmos by OpenGenus.
 * Author : ABDOUS Kamel
 */

#ifndef AUTOMATA_DFA_H
#define AUTOMATA_DFA_H

#include "types.h"

/*
 * Definition of a DFA.
 */
typedef struct dfa_s
{
  int alpha_size;

  state_t* states;
  int states_nb;

  state_id_t start_id;

  /*
   * This is a transition matrix.
   * -1 indicates that the transition isn't defined.
   */
  state_id_t** transitions;

} dfa_t;

/*
 * Allocate necessary data structure for the given dfa.
 * States ID's are initialized.
 * Initialize all transitions to -1.
 * @return 0 on success, -1 on failure.
 */
int
allocate_dfa(int states_nb, dfa_t* dfa);

/*
 * Free data structures of given DFA.
 */
void
free_dfa(dfa_t* dfa);

/*
 * Remove not accessible and not co-accessible states of dfa.
 * @return -1 if the resulting automaton is empty, 0 otherwise.
 */
int
remove_useless_states(dfa_t* dfa);

/*
 * Make the dfa complete (all transitions are defined).
 */
void
complete_dfa(dfa_t* dfa);

/*
 * @return 1 if string is on the language of dfa.
 *         0 otherwise.
 */
int
recognize_string(dfa_t* dfa, char* string);

/*
 * Construct the complement of the given dfa.
 */
void
complement_dfa(dfa_t* dfa);

#endif // AUTOMATA_DFA_H
