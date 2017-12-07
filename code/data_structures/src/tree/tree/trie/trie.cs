using System;
using System.Collections.Generic;
using Xunit;
using Xunit.Abstractions;

namespace Cosmos
{
    // XUnit test to test Trie data structure.
	public class TriestTest
	{
		private readonly TrieBuilder _trieBuilder = new TrieBuilder();

		public TriestTest(ITestOutputHelper output) : base(output)
		{
		}

		[Fact]
		public void TestCreation()
		{
			//var words = new[] {"abc", "abgl", "cdf", "abcd", "lmn"};
			var words = new[] {"abc", "abgl"};

			TrieNode root = _trieBuilder.BuildTrie(words);
			Console.WriteLine(root);
		}

		[Theory]
		[MemberData(nameof(GetCompleteWordData))]
		public void TestCompleteWordSearch(bool expected, string word, string[] source)
		{
			var trieNode = _trieBuilder.BuildTrie(source);
			var sut = new Trie(trieNode);
			var actual = sut.SearchCompleteWord(word);

			Assert.Equal(expected, actual);
		}

		[Theory]
		[MemberData(nameof(GetPrefixData))]
		public void TestPrefixWordSearch(bool expected, string prefix, string[] source)
		{
			var trieNode = _trieBuilder.BuildTrie(source);
			var trie = new Trie(trieNode);
			var actual = trie.SearchPrefix(prefix);
			
			Assert.Equal(expected, actual);
		}

		public static IEnumerable<object[]> GetPrefixData()
		{
			yield return new object[] { true, "abc", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { true, "ab", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { true, "a", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { true, "cdf", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { true, "cd", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { true, "c", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "x", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "abd", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "abx", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "cda", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "swyx", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
		}

		public static IEnumerable<object[]> GetCompleteWordData()
		{
			yield return new object[] { true, "abc", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { true, "abgl", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { true, "cdf", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { true, "abcd", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { true, "lmn", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "ab", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "abg", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "cd", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "abcx", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "abglx", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "cdfx", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "abcdx", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
			yield return new object[] { false, "lmnx", new[] { "abc", "abgl", "cdf", "abcd", "lmn" } };
		}

	}

	public class Trie
	{
		public TrieNode Root { get; set; }

		public Trie(TrieNode root)
		{
			Root = root;
		}

		/// <summary>
		/// Search for a complete word, not a prefix search.
		/// </summary>
		public bool SearchCompleteWord(string word)
		{
			var current = Root;
			foreach (char c in word)
			{
				if (current.Children.TryGetValue(c, out TrieNode node))
					current = node;
				else
					return false;
			}

			return current.IsCompleteWord;
		}

		public bool SearchPrefix(string prefix)
		{
			if (string.IsNullOrWhiteSpace(prefix)) return false;

			var current = Root;
			foreach (char c in prefix)
			{
				if (current.Children.TryGetValue(c, out TrieNode node))
					current = node;
				else
					return false;
			}

			return true;
		}
	}

	public class TrieNode
	{
		public bool IsCompleteWord { get; set; } = false;

		public Dictionary<char, TrieNode> Children { get; } = new Dictionary<char, TrieNode>();
	}

	/// <summary>
	/// Based on https://www.youtube.com/watch?v=AXjmTQ8LEoI by Tushar Roy
	/// </summary>
	public class TrieBuilder
	{
		public TrieNode BuildTrie(IEnumerable<string> words)
		{
			TrieNode root = new TrieNode();
			foreach (var word in words)
			{
				Insert(root, word);
			}

			return root;
		}

		private void Insert(TrieNode current, string word)
		{
			foreach (char c in word)
			{
				current.Children.TryGetValue(c, out TrieNode node);
				if (node == null)
				{
					node = new TrieNode();
					current.Children.Add(c, node);
				}
				current = node;
			}

			current.IsCompleteWord = true;
		}
	}
}