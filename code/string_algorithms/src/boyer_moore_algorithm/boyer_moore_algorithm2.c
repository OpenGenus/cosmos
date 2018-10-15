/* Part of Cosmos by OpenGenus Foundation */
/* 
 * Pointer based implementation of the Boyer-Moore String Search Algorithm 
 */
#include <stdio.h>
#include <string.h>

/*
 * Number of characters in the text alphabet used by the search and pattern strings
 * For 8-bit strings, use 256
 */
#define NO_OF_CHARS 256

/*
 * The core of Boyer-Moore algorithm is the skip value array used to advance more than
 *   a single character on mismatches encountered while searching
 */
static void 
InitSkip(char const *const pattern, int skip[], size_t alphabetLen, int patternLen)
{
	/* The length of the pattern is the default skip value */
	for (int *skipVal = skip; alphabetLen; --alphabetLen, ++skipVal)
		*skipVal = patternLen;

	/*
	 * Examining the search pattern from left to right, set the skip value to the rightmost occurence
	 *  of each unique character in the search pattern
	 */
	char const *patChar = pattern;
	int i = patternLen;
	while (*patChar && i)
		skip[*patChar++] = --i;
}

static const char *
NextSearchBegin(const char *const curSearch, int skip)
{
	return (curSearch + ((skip < 1) ? 1 : skip));
}

/* 
 * Searches txt for the first occurence of pattern using the Boyer-Moore searching algorithm
 * If found return a pointer to the matching string in txt
 * If not found return null (0)
 * This matches the function declaration of the strstr() function
 */
const char * 
BoyerMooreSearch(char const * const txt, char const * const pattern)
{
	if (!pattern || !txt)
		return (0);

	const int patternLen = strlen(pattern);
	const int txtLen = strlen(txt);
	if (patternLen > txtLen)
		return (0);

	int skip[NO_OF_CHARS];
	InitSkip(pattern, skip, NO_OF_CHARS, patternLen);

	const char *const patternEnd = pattern + (patternLen - 1);
	const char *const end = txt + (txtLen - patternLen);
	const char *searchBegin = txt;
	while (searchBegin <= end) {
		const char *patternChar = patternEnd;
		const char *searchChar = searchBegin + (patternLen - 1);

		/* Compare right to left */
		while (searchChar >= searchBegin && *searchChar == *patternChar)
			--searchChar, --patternChar;

		if (searchChar < searchBegin) /* All characters matched the pattern */
			return (searchBegin);

		searchBegin = NextSearchBegin(searchBegin, skip[*searchChar]);
	}

	return (0); /* pattern not found in txt */
}

/* Usage Example */
int 
main()
{
	const char *testText;
	const char *testPattern;
	const char *result;
	int spaces;
	char *matchMarker = "^";

	testText = "A string searching example consisting of this sentence.";
	testPattern = "sting";
	result = BoyerMooreSearch(testText, testPattern);
	puts(testText);
	if (result) {
		spaces = result - testText;
		while (spaces--)
			putc(' ', stdout);
		puts(matchMarker);
	}
	else
		puts("Pattern not found.");

	return (0);
}
