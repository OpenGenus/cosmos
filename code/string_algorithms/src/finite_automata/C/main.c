/*
 * Part of Cosmos by OpenGenus.
 * Author : ABDOUS Kamel
 */

#include <stdio.h>
#include <stdlib.h>
#include "dfa.h"

int
main()
{
  dfa_t dfa;

  /* A DFA to recognize all strings with 01 as a substring */
  allocate_dfa(3, &dfa);

  /* States are labelled with positive integers */
  dfa.start_id = 0;
  dfa.states[2].is_final = true;

  dfa.transitions[0]['0'] = 1;
  dfa.transitions[0]['1'] = 0;

  dfa.transitions[1]['0'] = 1;
  dfa.transitions[1]['1'] = 2;

  dfa.transitions[2]['0'] = 2;
  dfa.transitions[2]['1'] = 2;

  printf("%d\n", recognize_string(&dfa, "0111"));
  printf("%d\n", recognize_string(&dfa, "10101010"));
  printf("%d\n", recognize_string(&dfa, "11110"));
  printf("%d\n", recognize_string(&dfa, "001001"));

  free_dfa(&dfa);
  return (0);
}
