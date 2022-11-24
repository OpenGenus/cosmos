function catalan(n)
{
    if (n <= 1)
        return 1;
    let res = 0;
    for(let i = 0; i < n; i++)
        res += catalan(i) *
                catalan(n - i - 1);
    return res;
}