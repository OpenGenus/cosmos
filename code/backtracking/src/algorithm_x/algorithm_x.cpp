/*
 *      algo-x.cpp
 *      by Charles (@c650)
 *
 *      This code is from my repo at https://github.com/c650/knuth-algorithm-x
 *
 *      Path of Cosmos by OpenGenus Foundation
 */
#include <iostream>

#include <vector>

#include <algorithm>
#include <limits>

typedef std::vector<bool> matrix_row;
typedef std::vector<matrix_row> incidence_matrix;

/* implementing Knuth's Algorithm X */
bool
algo_x(const incidence_matrix& m, std::vector<bool> available_rows,
       std::vector<bool> available_cols, std::vector<size_t>& p_solution)
{

    if (available_rows.empty())
        available_rows.resize(m.size(), true);
    if (available_cols.empty())
        available_cols.resize(m[0].size(), true);

    /* if the current matrix has no columns, the current partial
     *      solution is a valid solution. terminate successfully */
    /* recursion terminating condition */
    if (available_cols.end() == std::find(available_cols.begin(), available_cols.end(), true))
    {
        /* we should do some printing or something. */
        std::cout << "Solution: \n";
        for (const size_t& st : p_solution)
            std::cout << char(st + 'A') << " ";
        std::cout << std::endl;

        return true;
    }

    /* debug */
    for (size_t i = 0; i < available_rows.size(); i++)
        if (available_rows[i])
            std::cout << "\t" << char(i + 'A') << " is still an available row.\n";
    for (size_t i = 0; i < available_cols.size(); i++)
        if (available_cols[i])
            std::cout << "\t" << i + 1 << " is still an available column.\n";

    /* Otherwise, deterministically choose a column. */
    size_t col_w_min_ones,
           min_ones,
           ones_in_col,
           num_col;
    num_col = m[0].size();
    min_ones = std::numeric_limits<size_t>::max();
    for (size_t i = 0; i < num_col; i++)
    {

        if (!available_cols[i])
            continue;

        ones_in_col = 0;
        for (size_t j = 0; j < m.size(); j++)
        {
            if (!available_rows[j])
                continue;                                   /* skip over deleted rows */

            if (m[j][i])
                ones_in_col++;
        }
        if (ones_in_col < min_ones)
        {
            min_ones = ones_in_col;
            col_w_min_ones = i;
        }

        /* if we don't have a min >= 1, we won't get
         *      an exact cover! :O */
        if (min_ones == 0)
            return false;
    }

    std::cout << "\tLeast ones in column: " << col_w_min_ones + 1
              << " with " << min_ones << " ones.\n";

    /* Choose the first row with a 1 in col_w_min_ones. */
    std::vector<bool> local_a_row, local_a_col;
    size_t curr_p_sol_len = p_solution.size();

    for (size_t i = 0; i < m.size(); i++)
        /* find the first row with the min number of ones*/
        if (m[i][col_w_min_ones] && available_rows[i])
        {

            std::cout << "\tPicking the row: " << char(i + 'A') << std::endl;

            /* include the row in the partial solution. */
            p_solution.push_back( i );

            local_a_row = available_rows;
            local_a_col = available_cols;

            /* "delete" all cols in row with value of 1 */
            for (size_t j = 0; j < m[i].size(); j++)
                if (m[i][j])
                {

                    local_a_col[j] = false;
                    std::cout << "\tDeleting column: " << j + 1 << std::endl;

                    /* all rows with a 1 in col j must go. */
                    for (size_t k = 0; k < m.size(); k++)
                    {
                        if (!available_rows[k])
                            continue;

                        if (m[k][j])
                        {
                            local_a_row[k] = false;
                            std::cout << "\tDeleting row: " << char(k + 'A') << std::endl;
                        }
                    }

                }                 /* end if */
            /* end for */

            /* call the function with the new subset in the partial solution
             *      and the deleted rows and cols updated accordingly. */
            if (algo_x(m, local_a_row, local_a_col, p_solution) )
                return true;
            std::cout << char(i + 'A') << " did not work!\n";
            p_solution.resize(curr_p_sol_len);

        }         /* end if */
    /* end for */

    /* default to return FALSE */
    return false;
}

int main()
{
    incidence_matrix m = {
        { 1, 0, 0, 1, 0, 0, 1 },
        { 1, 0, 0, 1, 0, 0, 0 },
        { 0, 0, 0, 1, 1, 0, 1 },
        { 0, 0, 1, 0, 1, 1, 0 },
        { 0, 1, 1, 0, 0, 1, 1 },
        { 0, 1, 0, 0, 0, 0, 1 }
    };

    std::vector<size_t> solution;
    algo_x(m, std::vector<bool>{}, std::vector<bool>{}, solution);
    return 0;
}
