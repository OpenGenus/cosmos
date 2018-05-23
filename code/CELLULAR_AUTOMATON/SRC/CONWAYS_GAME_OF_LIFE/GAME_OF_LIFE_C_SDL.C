/*
 * Part of Cosmos by OpenGenus Foundation
 * This program uses SDL 1.2
 * Author : ABDOUS Kamel
 */

#include <stdlib.h>
#include <time.h>
#include <SDL/SDL.h>


/* -------------------------------------------------------------------- */
/* Change automaton state delay */ 
#define RESPAWN_DELAY 25

/*
 * When SIMPLE_MODE = 1, the program displays dead cels in black, & alive cels in green.
 * When SIMPLE_MODE = 0, the program also displays the reborn cells & cells that are going to die.
 */
#define SIMPLE_MODE 1

int X_NB_CELLS = 800, Y_NB_CELLS = 600, /* Number of cels */
    X_CELL_SIZE = 1, Y_CELL_SIZE = 1, /* Size of cels */
    WINDOW_WIDTH, WINDOW_HEIGHT; /* Calculated in main */
/* -------------------------------------------------------------------- */

/* This struct is passed as parameter to the SDL timer. */
typedef struct
{
    int **cels, /* Cels matrix */
        **buffer; /* This buffer is used to calculate the new state of the automaton */

} UpdateCelsTimerParam;

typedef enum
{
    DEAD,
    ALIVE,
    REBORN,
    DYING

} CelsState;

/* Function to call to launch the automaton */
int 
launch_app(SDL_Surface* screen);

/* Updates the state of the automaton.
 * That's a SDL timer callback function.
 */
Uint32 
update_cels(Uint32 interval, void* param);

/* Inc neighborhood according to game of life rules. */
void 
inc_neighborhood(int cel, int* neighborhood);

/* Returns the new state of cel regarding the value of neighborhood */
int 
live_cel(int cel, int neighborhood);

void 
display_cels(int** cels, SDL_Surface* screen);

void 
display_one_cel(int cel, int x, int y, SDL_Surface* screen);

/* Function used to initialise the two matrices cels & buffer as size_x * size_y matrices. */
void 
alloc_cels(int*** cels, int*** buffer, int size_x, int size_y);

void 
free_cels(int** cels, int** buffer, int size_x);

/* Helper function that colores one pixel. */
void 
set_pixel(SDL_Surface* surf, int x, int y, Uint32 color);

int 
main()
{
    srand(time(NULL));

    if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER) != 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de la SDL : %s\n", SDL_GetError());
        return (EXIT_FAILURE);
    }

    WINDOW_WIDTH = X_NB_CELLS * X_CELL_SIZE;
    WINDOW_HEIGHT = Y_NB_CELLS * Y_CELL_SIZE;
    SDL_Surface* screen = SDL_SetVideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, 32, SDL_HWSURFACE | SDL_DOUBLEBUF);

    if (screen == NULL) {
        fprintf(stderr, "Can't create application window : %s\n", SDL_GetError());
        SDL_Quit();
        return (EXIT_FAILURE);
    }

    int exit_code = launch_app(screen);

    SDL_FreeSurface(screen);
    SDL_Quit();
    return (exit_code);
}

/* Function to call to launch the automaton */
int 
launch_app(SDL_Surface* screen)
{
    int **cels = NULL, **buffer;
    alloc_cels(&cels, &buffer, X_NB_CELLS, Y_NB_CELLS);

    SDL_Event event;
    int stop = 0;

    /* The SDL timer params */
    UpdateCelsTimerParam timer_param = {cels, buffer};
    SDL_AddTimer(RESPAWN_DELAY, update_cels, &timer_param);

    while (!stop) {
        SDL_PollEvent(&event);
        switch (event.type) {
            case SDL_QUIT:
                stop = 1;
                break;
        }

        SDL_FillRect(screen, NULL, SDL_MapRGB(screen->format, 0, 0, 0));
        display_cels(cels, screen);
        SDL_Flip(screen);
    }

    free_cels(cels, buffer, X_NB_CELLS);
    return (EXIT_SUCCESS);
}

/* Updates the state of the automaton.
 * That's a SDL timer callback function.
 */
Uint32 
update_cels(Uint32 interval, void* param)
{
    UpdateCelsTimerParam* param_struct = param;

    int **cels = param_struct->cels,
        **buffer = param_struct->buffer;

    int i = 0, j = 0, neighborhood;

    /* Here we update the automaton state in the buffer */
    while (i < X_NB_CELLS) {
        j = 0;
        
        /* Conditions in this loop are just an application of the game of life rules */
        while (j < Y_NB_CELLS) {
            if (cels[i][j] == REBORN)
                buffer[i][j] = ALIVE;

            else if (cels[i][j] == DYING)
                buffer[i][j] = DEAD;

            /* Number of useful cels in the neighborhood */
            neighborhood = 0;
            if (i != 0) {
                inc_neighborhood(cels[i - 1][j], &neighborhood);
                
                if (j != 0)
                    inc_neighborhood(cels[i - 1][j - 1], &neighborhood);

                if (j != Y_NB_CELLS - 1)
                    inc_neighborhood(cels[i - 1][j + 1], &neighborhood);
            }

            if (i != X_NB_CELLS - 1) {
                inc_neighborhood(cels[i + 1][j], &neighborhood);
                
                if(j != 0)
                    inc_neighborhood(cels[i + 1][j - 1], &neighborhood);

                if(j != Y_NB_CELLS - 1)
                    inc_neighborhood(cels[i + 1][j + 1], &neighborhood);
            }

            if (j != 0)
                inc_neighborhood(cels[i][j - 1], &neighborhood);

            if (j != Y_NB_CELLS - 1)
                inc_neighborhood(cels[i][j + 1], &neighborhood);

            buffer[i][j] = live_cel(cels[i][j], neighborhood);
            j++;
        }

        ++i;
    }

    /* Here we copy the new state in the cels matrix */
    for (i = 0; i < X_NB_CELLS; ++i) {
        for (j = 0; j < Y_NB_CELLS; ++j)
            cels[i][j] = buffer[i][j];
    }

    return (interval);
}

/* Inc neighborhood according to game of life rules. */
void 
inc_neighborhood(int cel, int* neighborhood)
{
    if (cel == ALIVE || cel == REBORN)
        (*neighborhood)++;
}

/* Returns the new state of cel regarding the value of neighborhood */
int 
live_cel(int cel, int neighborhood)
{
    if (!SIMPLE_MODE) {
        if (cel == ALIVE || cel == REBORN) {
            if(neighborhood == 2 || neighborhood == 3)
                return (ALIVE);

            else
                return (DYING);
        }

        else {
            if(neighborhood == 3)
                return (REBORN);

            else
                return (DEAD);
        }
    }

    else {
        if (cel == ALIVE)
            return (neighborhood == 2 || neighborhood == 3);

        else
            return (neighborhood == 3);
    }
}

void 
display_cels(int** cels, SDL_Surface* screen)
{
    int i = 0, j = 0;
    
    while (i < X_NB_CELLS) {
        j = 0;
        while (j < Y_NB_CELLS) {
            display_one_cel(cels[i][j], i, j, screen);
            ++j;
        }

        ++i;
    }
}

void 
display_one_cel(int cel, int x, int y, SDL_Surface* screen)
{
    int i = 0, j = 0,
        r = 0, g = 0, b = 0;

    if (!SIMPLE_MODE) {
        if (cel == ALIVE)
            g = 255;
        else if (cel == DEAD)
            r = 255;
        else if (cel == REBORN)
            b = 255;
        else {
            r = 255;
            g = 140;
        }
    }

    else {
        if (cel == DEAD)
            return;

        g = 255;
    }

    while (i < X_CELL_SIZE) {
        j = 0;
        while (j < Y_CELL_SIZE) {
            set_pixel(screen, x * X_CELL_SIZE + i, y * Y_CELL_SIZE + j, SDL_MapRGB(screen->format, r, g, b));
            ++j;
        }

        ++i;
    }
}

/* Function used to initialise the two matrices cels & buffer as size_x * size_y matrices. */
void 
alloc_cels(int*** cels, int*** buffer, int size_x, int size_y)
{
    *cels = malloc(sizeof(int*) * size_x);
    *buffer = malloc(sizeof(int*) * size_x);

    int i = 0, j = 0;
    while (i < size_x) {
        (*cels)[i] = malloc(sizeof(int) * size_y);
        (*buffer)[i] = malloc(sizeof(int) * size_y);

        j = 0;
        while (j < size_y) {
            /* The initial state is picked randomly */
            (*cels)[i][j] = rand() % 2;
            ++j;
        }

        i++;
    }
}

void 
free_cels(int** cels, int** buffer, int size_x)
{
    int i = 0;
    while (i < size_x) {
        free(cels[i]);
        free(buffer[i]);
        ++i;
    }

    free(cels);
    free(buffer);
}

/* --------------------------------------------------------------------------------- */
/* Helper function that colores one pixel. */
void 
set_pixel(SDL_Surface* surf, int x, int y, Uint32 color)
{
    int bpp = surf->format->BytesPerPixel;
    Uint8* p = (Uint8*)surf->pixels + y * surf->pitch + x * bpp;

    switch (bpp) {
        case 1:
            *p = color;
            break;

        case 2:
            *(Uint16*)p = color;
            break;

        case 3:
            if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
                p[0] = (color >> 16) & 0xff;
                p[1] = (color >> 8) & 0xff;
                p[2] = color & 0xff;
            }

            else {
                p[0] = color & 0xff;
                p[1] = (color >> 8) & 0xff;
                p[2] = (color >> 16) & 0xff;
            }
            break;

        case 4:
            *(Uint32*)p = color;
            break;
    }
}
