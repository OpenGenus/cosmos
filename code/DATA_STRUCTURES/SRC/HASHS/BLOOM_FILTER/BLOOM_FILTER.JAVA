/**
 * Project: Cosmos
 * Package: main
 * File: BloomFilter.java
 * 
 * @author sidmishraw
 *         Last modified: Oct 18, 2017 6:25:58 PM
 */
package main;

import java.util.ArrayList;
import java.util.List;

/**
 * <p>
 * {@link BloomFilter} This is a unoptimized version of a Bloom filter. A Bloom
 * filter is a data structure designed to tell you, rapidly and
 * memory-efficiently, whether an element is present in a set. The price paid
 * for this efficiency is that a Bloom filter is a <i>probabilistic data
 * structure</i>: it tells us that the element either definitely is not in the
 * set or may be in the set.
 * 
 * For more information see:
 * <a href="https://llimllib.github.io/bloomfilter-tutorial/"> Bloom filter
 * tutorial</a>
 * 
 * This implementation is going to have 2 hash functions:
 * FNV and FNV-1a hashes.
 * 
 * @author sidmishraw
 *
 *         Qualified Name:
 *         main.BloomFilter
 *
 */
public class BloomFilter {

  /**
   * Default bit vector size for the {@link BloomFilter}
   */
  private static final int BIT_VECTOR_SIZE = 16;

  /**
   * <p>
   * This is the base data structure of a bloom filter.
   * 
   * <p>
   * To add an element to the Bloom filter, we simply hash it a few times and
   * set the bits in the bit vector at the index of those hashes to true.
   * 
   * <p>
   * To test for membership, you simply hash the object with the same hash
   * functions, then see if those values are set in the bit vector. If they
   * aren't, you know that the element isn't in the set. If they are, you only
   * know that it might be, because another element or some combination of
   * other elements could have set the same bits.
   */
  private boolean[] bitvector;

  /**
   * The list of hash functions used by the bloom filter
   */
  private List<HashFunction> hashFunctions;

  /**
   * The number of elements added to the bloom filter, this influences the
   * probability of membership of an element, when checking membership.
   */
  private int nbrElements;

  /**
   * 
   */
  public BloomFilter() {

    this.bitvector = new boolean[BIT_VECTOR_SIZE];
    this.nbrElements = 0;
    this.hashFunctions = new ArrayList<>();

    this.hashFunctions.add(BloomFilter::fnv); // passing in the method
                                              // reference
                                              // this.hashFunctions.add(this::fvn1a); // passing in the method
                                              // reference,
                                              // // for the instance
  }

  /**
   * Creates and initializes a new Bloom filter with `m` slots in the bit
   * vector table
   * 
   * @param m
   *            The size of the bit vector of the bloom filter
   * @param hashFunctions
   *            The hash functions to be used by the bloom filter for
   */
  public BloomFilter(int m, HashFunction... hashFunctions) {

    this.bitvector = new boolean[m];

    this.nbrElements = 0;

    this.hashFunctions = new ArrayList<>();

    for (HashFunction func : hashFunctions) {

      this.hashFunctions.add(func);
    }

    if (this.hashFunctions.size() == 0) {

      this.hashFunctions.add(BloomFilter::fnv);
    }
  }

  /**
   * <p>
   * Adds the element into the bloom filter. To get added, it must pass
   * through the k hash functions of the bloom filter.
   * 
   * T:: O(k); where k is the number of hash functions
   * 
   * @param element
   *            The element
   */
  public void add(Stringable element) {

    byte[] toBeHashed = element.stringValue().getBytes();

    for (HashFunction hFunc : this.hashFunctions) {

      long hash = hFunc.hash(toBeHashed);

      this.bitvector[(int) (hash % this.bitvector.length)] = true;
    }

    this.nbrElements++;
  }

  /**
   * <p>
   * Checks if the element is a member of the bloom filter.
   * T:: O(k); where k is the number of hash functions
   * 
   * @param element
   *            The element that needs to be checked for membership
   * @return The result containing the probability of membership and if it is
   *         a member. The result is a valid JSON string of form
   *         <code>
   *         {
   *         "probability": "1",
   *         "isMember": "false"
   *         }
   *         </code>
   */
  public String check(Stringable element) {

    byte[] toBeHashed = element.stringValue().getBytes();

    boolean isMember = true;

    for (HashFunction hFunc : this.hashFunctions) {

      long hash = hFunc.hash(toBeHashed);

      isMember = isMember && this.bitvector[(int) (hash % this.bitvector.length)];
    }

    if (isMember) {

      return calcProbability();
    } else {

      return "{\"probability\": 1, \"isMember\": false}";
    }
  }

  /**
   * Computes the probability of membership using the formula : (1-e^-kn/m)^k
   * where ^ is exponentation and
   * m = number of bits in the bit vector table
   * n = number of elements in the bloom filter
   * k = number of hash functions
   * 
   * @return The membership probability, json
   */
  private final String calcProbability() {

    Double prob = Math.pow(
        (1 - Math.exp(((-1) * this.hashFunctions.size() * this.nbrElements) / (double) this.bitvector.length)),
        this.hashFunctions.size());

    return String.format("{\"probability\": %s, \"isMember\": true}", prob);
  }

  /**
   * <p>
   * Fetches m of the bloom filter
   * 
   * @return The number of bits in the bit vector backing the bloom filter
   */
  public int getM() {

    return this.bitvector.length;
  }

  /**
   * <p>
   * Fetches k of the bloom filter
   * 
   * @return The number of hash functions of the bloom filter
   */
  public int getK() {

    return this.hashFunctions.size();
  }

  /**
   * <p>
   * Fetches n of the bloom filter
   * 
   * @return The number of elements added to the bloom filter
   */
  public int getN() {

    return this.nbrElements;
  }

  /**
   * Just for testing
   */
  @Override
  public String toString() {

    StringBuffer buf = new StringBuffer();

    if (this.bitvector.length > 0) {

      buf.append("[");
      buf.append(String.format("(%d,%s)", 0, this.bitvector[0]));
    }

    for (int i = 1; i < this.bitvector.length; i++) {

      buf.append(String.format(",(%d,%s)", i, this.bitvector[i]));
    }

    buf.append("]");

    return buf.toString();
  }

  /**
   * <p>
   * {@link Stringable} are things that can give be made into a String.
   * 
   * @author sidmishraw
   *
   *         Qualified Name:
   *         main.Stringable
   *
   */
  public static interface Stringable {

    public String stringValue();
  }

  /**
   * <p>
   * The hashfunctions that can be used by the bloom filter
   * 
   * @author sidmishraw
   *
   *         Qualified Name:
   *         main.HashFunction
   *
   */
  @FunctionalInterface
  public static interface HashFunction {

    /**
     * Hashes the element(byte buffer) to an int
     * 
     * @param buffer
     *            The byte buffer of the element to be hashed
     * @return The hashed number
     */
    public long hash(byte[] buffer);
  }

  /**
   * The FNV hash function:
   * Uses the 32 bit FNV prime and FNV_OFFSET
   * 
   * FNV hashing using the FNVHash - v1 see
   * <a href="http://isthe.com/chongo/tech/comp/fnv/#history">link</a>,
   * uses:
   * 32 bit offset basis = 2166136261
   * 32 bit FNV_prime = 224 + 28 + 0x93 = 16777619
   * 
   * @param buffer
   *            The element to be hashed in bytes
   * @return The 32 bit FNV hash of the element
   */
  public static final long fnv(byte[] buffer) {

    final long OFFSET_BASIS_32 = 2166136261L;
    final long FNV_PRIME_32 = 16777619L;

    long hash = OFFSET_BASIS_32;

    for (byte b : buffer) {

      hash = hash * FNV_PRIME_32;
      hash = hash ^ b;
    }

    return Math.abs(hash);
  }

  /**
   * The FNV-1a hash function:
   * USes the 32 bit FNV prime and FNV_Offset
   * 
   * @param buffer
   *            The element to be hased, in bytes
   * @return The 32 bit FNV-1a hash of the element
   */
  public static final long fnv1a(byte[] buffer) {

    final long OFFSET_BASIS_32 = 2166136261L;
    final long FNV_PRIME_32 = 16777619L;

    long hash = OFFSET_BASIS_32;

    for (byte b : buffer) {

      hash = hash ^ b;
      hash = hash * FNV_PRIME_32;
    }

    return Math.abs(hash);
  }

  /**
   * For testing out the library
   * 
   * @param args
   */
  public static void main(String[] args) {

    BloomFilter b = new BloomFilter(15);

    System.out.println("FNV hash of 'hello' = " + BloomFilter.fnv("hello".getBytes()) % b.bitvector.length);

    System.out.println("FNV-1a hash of 'hello' = " + BloomFilter.fnv1a("hello".getBytes()) % b.bitvector.length);

    b.add(() -> "hello");
    b.add(() -> "helloWorld");
    b.add(() -> "helloDear");
    b.add(() -> "her");
    b.add(() -> "3456");

    System.out.println("hello in bloom filter = " + b.check(() -> "hello"));
    System.out.println("helloWorld in bloom filter = " + b.check(() -> "helloWorld"));
    System.out.println("helloDear in bloom filter = " + b.check(() -> "helloDear"));
    System.out.println("dear in bloom filter = " + b.check(() -> "dear"));
    System.out.println("3456 in bloom filter = " + b.check(() -> "3456"));
    System.out.println("3 in bloom filter = " + b.check(() -> "3"));
    System.out.println("4 in bloom filter = " + b.check(() -> "4"));
    System.out.println("5 in bloom filter = " + b.check(() -> "5"));
    System.out.println("6 in bloom filter = " + b.check(() -> "6"));
  }
}