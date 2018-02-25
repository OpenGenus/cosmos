/*
 * Part of Cosmos by OpenGenus.
 * Author : ABDOUS Kamel
 */

#include "dfa.h"
#include <stdlib.h>

/* This array is used when doing a dfs */
static dfs_color_t* dfs_colors;

/* Tells if a state is accessible, when removing useless states */
static bool* access_bits;

/* Stores the new ids of states, when removing useless states */
static state_id_t* states_new_ids;

/* Stores the number of coaccessible states of a given DFA */
static int coaccess_states_nb;

/*
 * Depth-first search subroutine for accessible states.
 */
static void
not_accessible_subroutine(dfa_t* dfa, state_id_t root, state_link_t* access_list);

/*
 * Reverse depth-first search subroutine for coaccessible states.
 */
static state_link_t*
not_coaccessible_subroutine(dfa_t* dfa, state_id_t root, state_link_t* coaccess_list);

/*
 * Allocate necessary data structure for the given dfa.
 * States ID's are initialized.
 * Initialize all transitions to -1.
 * @return 0 on success, -1 on failure.
 */
int
allocate_dfa(int states_nb, dfa_t* dfa)
{
  dfa->alpha_size = 256;
  dfa->states_nb = states_nb;

  dfa->states = malloc(sizeof(state_t) * states_nb);
  if (dfa->states == NULL)
    return (-1);

  dfa->transitions = malloc(sizeof(state_id_t*) * states_nb);
  if (dfa->transitions == NULL) {
    free(dfa->states);
    return (-1);
  }

  int i, j;

  for (i = 0; i < states_nb; ++i) {
    dfa->states[i].id = i;
    dfa->states[i].is_final = false;

    dfa->transitions[i] = malloc(sizeof(state_id_t) * dfa->alpha_size);

    /* Error, free allocated memory */
    if (dfa->transitions[i] == NULL) {
      --i;
      while (i >= 0) {
        free(dfa->transitions[i]);
        --i;
      }

      free(dfa->transitions);
      free(dfa->states);

      return (-1);
    }

    else {
      for (j = 0; j < dfa->alpha_size; ++j)
        dfa->transitions[i][j] = -1;
    }
  }

  return (0);
}

/*
 * Free data structures of given DFA.
 */
void
free_dfa(dfa_t* dfa)
{
  free(dfa->states);

  int i;
  for (i = 0; i < dfa->states_nb; ++i)
    free(dfa->transitions[i]);

  free(dfa->transitions);
}

/*
 * Remove not accessible and not co-accessible states of dfa.
 * @return -1 if the resulting automaton is empty, 0 otherwise.
 */
int
remove_useless_states(dfa_t* dfa)
{
  int i;

  dfs_colors = malloc(sizeof(*dfs_colors) * dfa->states_nb);
  for (i = 0; i < dfa->states_nb; ++i)
    dfs_colors[i] = WHITE;

  access_bits = calloc(dfa->states_nb, sizeof(*access_bits));

  /* Used to store accessible states */
  state_link_t* access_list = alloc_state_link(dfa->start_id);

  /* Get all accessible states in access_list */
  not_accessible_subroutine(dfa, dfa->start_id, access_list);

  /* Now we will get co-accessible states from accessible states */
  state_link_t *coaccess_list = NULL, *coaccess_back,
               *next_save, *tmp_link;

  states_new_ids = malloc(sizeof(state_id_t) * dfa->states_nb);

  for (i = 0; i < dfa->states_nb; ++i) {
    dfs_colors[i] = WHITE;
    states_new_ids[i] = -1;
  }

  coaccess_states_nb = 0;

  /* Loop over accessible states */
  while (access_list != NULL) {
    next_save = access_list->next;

    if (dfa->states[access_list->state].is_final && dfs_colors[access_list->state] == WHITE) {
      tmp_link = alloc_state_link(access_list->state);

      if (coaccess_list == NULL)
        coaccess_list = coaccess_back = tmp_link;

      else
        coaccess_back->next = tmp_link;

      coaccess_back = not_coaccessible_subroutine(dfa, tmp_link->state, tmp_link);
    }

    /* We don't need this link anymore, so we free it */
    free(access_list);
    access_list = next_save;
  }

  /* End of depth-first search */
  free(access_bits);
  free(dfs_colors);

  /* Time to construct the new DFA */
  if (coaccess_states_nb == 0) {
    free(states_new_ids);
    return (-1);
  }

  else if (coaccess_states_nb == dfa->states_nb) {
    free(states_new_ids);
    return (0);
  }

  else {
    state_t* old_states = dfa->states;
    state_id_t** old_transitions = dfa->transitions;
    int new_start_id;

    /* Allocate new states and transitions */
    dfa->states = malloc(sizeof(state_t) * coaccess_states_nb);
    dfa->transitions = malloc(sizeof(state_id_t*) * coaccess_states_nb);

    for (i = 0; i < coaccess_states_nb; ++i)
      dfa->transitions[i] = malloc(sizeof(state_id_t) * dfa->alpha_size);

    i = 0;
    int j;

    /* Copy coaccessible states and transitions of coaccessible states */
    while (coaccess_list != NULL) {
      dfa->states[i].id = i;
      dfa->states[i].is_final = old_states[coaccess_list->state].is_final;

      if (coaccess_list->state == dfa->start_id)
        new_start_id = i;

      for (j = 0; j < dfa->alpha_size; ++j) {
        if (old_transitions[coaccess_list->state][j] != -1)
          dfa->transitions[i][j] = states_new_ids[old_transitions[coaccess_list->state][j]];

        else
          dfa->transitions[i][j] = -1;
      }

      /* We free this link, we don't need it anymore */
      next_save = coaccess_list->next;
      free(coaccess_list);

      coaccess_list = next_save;
      ++i;
    }

    free(old_states);
    for (i = 0; i < dfa->states_nb; ++i)
      free(old_transitions[i]);

    free(old_transitions);
    dfa->states_nb = coaccess_states_nb;
    dfa->start_id = new_start_id;

    free(states_new_ids);
  }

  return (0);
}

/*
 * Depth-first search subroutine for accessible states.
 */
static void
not_accessible_subroutine(dfa_t* dfa, state_id_t root, state_link_t* access_list)
{
  state_link_t* new_link;
  int new_root;

  dfs_colors[root] = BLACK;
  access_bits[root] = true;

  int i;
  for (i = 0; i < dfa->alpha_size; ++i) {
    new_root = dfa->transitions[root][i];

    if (new_root != -1 && dfs_colors[new_root] == WHITE) {
      new_link = alloc_state_link(new_root);

      access_list->next = new_link;
      not_accessible_subroutine(dfa, new_root, new_link);
    }
  }
}

/*
 * Reverse depth-first search subroutine for coaccessible states.
 */
static state_link_t*
not_coaccessible_subroutine(dfa_t* dfa, state_id_t root, state_link_t* coaccess_list)
{
  state_link_t* new_link;
  dfs_colors[root] = BLACK;
  states_new_ids[root] = coaccess_states_nb;
  coaccess_states_nb++;

  int i, j;
  for (i = 0; i < dfa->states_nb; ++i) {
    /* We do nothing if this state isn't accessible */
    if (access_bits[i]) {
      for (j = 0; j < dfa->alpha_size; ++j) {
        if (dfa->transitions[i][j] == root && dfs_colors[i] == WHITE) {
          new_link = alloc_state_link(i);

          coaccess_list->next = new_link;
          coaccess_list = not_coaccessible_subroutine(dfa, i, new_link);

          break;
        }
      }
    }
  }

  return (coaccess_list);
}

/*
 * Make the dfa complete (all transitions are defined).
 */
void
complete_dfa(dfa_t* dfa)
{
  /* ID of dead state */
  state_id_t dead_id = dfa->states_nb;

  /* The DFA is complete until we found a -1 transition */
  bool complete = true;

  int i, j;
  for (i = 0; i < dfa->states_nb; ++i) {
    for (j = 0; j < dfa->alpha_size; ++j) {
      if (dfa->transitions[i][j] == -1) {
        complete = false;
        dfa->transitions[i][j] = dead_id;
      }
    }
  }

  /* The DFA is to be completed */
  if (!complete) {
    dfa->states_nb++;
    dfa->states = realloc(dfa->states, sizeof(state_t) * dfa->states_nb);

    dfa->states[dead_id].id = dead_id;
    dfa->states[dead_id].is_final = false;

    dfa->transitions = realloc(dfa->transitions, sizeof(state_id_t*) * dfa->states_nb);
    dfa->transitions[dead_id] = malloc(sizeof(state_id_t) * dfa->alpha_size);

    for (i = 0; i < dfa->alpha_size; ++i)
      dfa->transitions[dead_id][i] = dead_id;
  }
}

/*
 * @return 1 if string is on the language of dfa.
 *         0 otherwise.
 */
int
recognize_string(dfa_t* dfa, char* string)
{
  state_id_t cur_state = dfa->start_id;
  int i;

  for (i = 0; string[i] != '\0'; ++i) {
    cur_state = dfa->transitions[cur_state][(unsigned int)string[i]];

    if (cur_state == -1)
      return (0);
  }

  return (dfa->states[cur_state].is_final);
}

/*
 * Construct the complement of the given dfa.
 */
void
complement_dfa(dfa_t* dfa)
{
  complete_dfa(dfa);

  int i;
  for (i = 0; i < dfa->states_nb; ++i)
    dfa->states[i].is_final = !dfa->states[i].is_final;
}
