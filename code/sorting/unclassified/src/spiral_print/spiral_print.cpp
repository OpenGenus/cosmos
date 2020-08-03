/* Part of Cosmos by OpenGenus Foundation */
#include <vector>
#include <sstream>

std::string spiralPrint(std::vector<std::vector<int>> vec, int row, int col)
{
    int begRow = 0,
        endRow = row - 1,
        begCol = 0,
        endCol = col - 1;
    std::ostringstream res;

    while (begRow <= endRow && begCol <= endCol)
    {
        // Print the start row
        for (int i = begCol; i <= endCol; ++i)
            res << vec[begRow][i] << " ";
        ++begRow;

        // Print the end col
        for (int i = begRow; i <= endRow; ++i)
            res << vec[i][endCol] << " ";
        --endCol;

        // Print the end row
        if (endRow >= begRow)
        {
            for (int i = endCol; i >= begCol; --i)
                res << vec[endRow][i] << " ";
            --endRow;
        }

        // Print the start col
        if (begCol <= endCol)
        {
            for (int i = endRow; i >= begRow; --i)
                res << vec[i][begCol] << " ";
            ++begCol;
        }
    }

    auto s = res.str();
    if (!s.empty())
        s.pop_back();

    return s;
}
