#include "../../../src/lossless_compression/huffman/huffman.cpp"
#include <iostream>
#include <fstream>
#include <iterator>
using namespace std;

// test only for Huffman::base_type is 64bit
class HuffmanTest {
public:
    HuffmanTest()
    {
        if (sizeof(Huffman::base_type) != 8)
            cout << "the test require that Huffman::base_type based on 64bit\n";

        testCalculateFrequency();
        testImportDictionary();
        testExportDictionary();
        testSeperateHeaderAndCode();
        testSeperateCode();
        testStringToBinary();
        testBinaryToHex();
        testHexToBinary();
    }

    void testCalculateFrequency()
    {
        Huffman huf;

        assert(huf.frequency_.empty() == true);

        huf.frequency_.clear();
        huf.calculateFrequency("a");
        assert(huf.frequency_.size() == 1
               && huf.frequency_.find('a') != huf.frequency_.end()
               && huf.frequency_.find('a')->second == 1);

        huf.frequency_.clear();
        huf.calculateFrequency("aba");
        assert(huf.frequency_.size() == 2
               && huf.frequency_.find('a') != huf.frequency_.end()
               && huf.frequency_.find('a')->second == 2
               && huf.frequency_.find('b') != huf.frequency_.end()
               && huf.frequency_.find('b')->second == 1
               && huf.frequency_.find('c') == huf.frequency_.end());
    }

    void testImportDictionary()
    {
        Huffman huf;
        std::string parameter{};

        assert(huf.reverse_dictionary_.empty() == true);

        parameter.clear();
        huf.reverse_dictionary_.clear();
        parameter = "";
        huf.importDictionary(parameter);
        assert(huf.reverse_dictionary_.empty() == true);

        parameter.clear();
        huf.reverse_dictionary_.clear();
        parameter.append("c");
        parameter += huf.DELIMITER;
        parameter.append("123");
        parameter += huf.DELIMITER;
        huf.importDictionary(parameter);
        assert(huf.reverse_dictionary_.size() == 1
               && huf.reverse_dictionary_.find("123")->second == 'c');
    }

    void testExportDictionary()
    {
        Huffman huf;
        std::string res{};

        assert(huf.dictionary_.empty() == true);

        huf.dictionary_.insert(std::make_pair('c', "123"));
        assert(huf.dictionary_.size() == 1
               && huf.dictionary_.find('c')->second == "123");
    }

    void testSeperateHeaderAndCode()
    {
        Huffman huf;
        std::pair<std::string, std::string> res;
        res = huf.seperateHeaderAndCode(huf.addSeperateCode(""));
        assert(res.first == "" && res.second == "");

        res = huf.seperateHeaderAndCode(huf.addSeperateCode("123"));
        assert(res.first == "123" && res.second == "");

        res = huf.seperateHeaderAndCode(huf.addSeperateCode("123").append("456"));
        assert(res.first == "123" && res.second == "456");
    }

    void testSeperateCode()
    {
        Huffman huf;
        std::string res;
        res = huf.removeSeperateCode(huf.addSeperateCode(""));
        assert(res == "");

        res = huf.removeSeperateCode(huf.addSeperateCode(huf.addSeperateCode("")));
        assert(res == huf.addSeperateCode(""));

        res = huf.removeSeperateCode(huf.addSeperateCode("123"));
        assert(res == "123");

        res = huf.removeSeperateCode( \
            huf.addSeperateCode(huf.removeSeperateCode(huf.addSeperateCode("456"))));
        assert(res == "456");
    }

    void testStringToBinary()
    {
        Huffman huf;
        std::string res;
        huf.dictionary_.insert(std::make_pair('a', "0"));
        huf.dictionary_.insert(std::make_pair('b', "10"));
        huf.dictionary_.insert(std::make_pair('c', "11"));

        res = huf.stringToBinary("");
        assert(res == "");

        res = huf.stringToBinary("a");
        assert(res == "0");

        res = huf.stringToBinary("ab");
        assert(res == "010");

        res = huf.stringToBinary("abc");
        assert(res == "01011");

        res = huf.stringToBinary("abca");
        assert(res == "010110");

        res = huf.stringToBinary("cbabc");
        assert(res == "111001011");
    }

    void testBinaryToHex()
    {
        Huffman huf;
        std::string res, expect;
        std::string delim{}, bin{};

        bin = "";
        huf.binary_bit_ = bin.size();
        res = huf.binaryToHex(bin);
        expect = "";
        while (expect.size() % (int)(huf.GUARANTEE_BIT / sqrt(huf.HEX_BIT)))
            expect.push_back('0');
        assert(res == "");

        bin = "1011";
        huf.binary_bit_ = bin.size();
        res = huf.binaryToHex(bin);
        expect = "b000000000000000 ";
        assert(res == expect);

        bin = "10111110";
        huf.binary_bit_ = bin.size();
        res = huf.binaryToHex(bin);
        expect = "be00000000000000 ";
        assert(res == expect);

        bin = "101111101001";
        huf.binary_bit_ = bin.size();
        res = huf.binaryToHex(bin);
        expect = "be90000000000000 ";
        assert(res == expect);

        bin = "1011111010010111";
        huf.binary_bit_ = bin.size();
        res = huf.binaryToHex(bin);
        expect = "be97000000000000 ";
        assert(res == expect);

        bin = "10111110100101111010011100101000";
        huf.binary_bit_ = bin.size();
        res = huf.binaryToHex(bin);
        expect = "be97a72800000000 ";
        assert(res == expect);

        bin = ("10111110100101111010011100101000111");
        huf.binary_bit_ = bin.size();
        res = huf.binaryToHex(bin);
        expect = "be97a728e0000000 ";
        assert(res == expect);

        bin = ("1011111010010111101001110010100011100100111010001011111110110101" \
               "1011111010010111101001110010100011100100111010001011111110110101");
        huf.binary_bit_ = bin.size();
        res = huf.binaryToHex(bin); expect = "be97a728e4e8bfb5 be97a728e4e8bfb5 ";
        assert(res == expect);
    }

    void testHexToBinary()
    {
        Huffman huf;
        std::string hex, res;
        std::string delim{};

        hex = "";
        huf.binary_bit_ = hex.size() * 4;
        while (hex.size() % huf.GUARANTEE_BIT)
            hex.push_back('0');
        res = huf.hexToBinary(hex);
        assert(res == "");

        hex = "b00000000000000 ";
        huf.binary_bit_ = hex.size() * 4;
        res = huf.hexToBinary(hex);
        assert(res == "0000101100000000000000000000000000000000000000000000000000000000");

        hex = "be97a728e4e8bfb5 be97a728e4e8bfb5 ";
        huf.binary_bit_ = hex.size() * 4;
        res = huf.hexToBinary(hex);
        assert(res == ("1011111010010111101001110010100011" \
                       "1001001110100010111111101101011011" \
                       "1110100101111010011100101000111001" \
                       "0011101000101111111011010110111110"));
    }
};

int main()
{
    HuffmanTest test;

    Huffman huf;
    if (huf.decompression(huf.compression(huf.decompression(huf.compression("")))) != "")
        cout << "error empty\n";

    Huffman huf2;
    if (huf2.decompression(huf2.compression(huf2.decompression(huf2.compression("    "))))
        != "    ")
        cout << "error separate\n";

    Huffman huf6;
    if (huf6.decompression(huf6.compression(huf6.decompression(
                                                huf6.compression("COMPRESSION_TESTCOMPRESSION_TEST"))))
        != "COMPRESSION_TESTCOMPRESSION_TEST")
        cout << "error binary6\n";

    Huffman huf7;
    if (huf7.decompression(huf7.compression(huf7.decompression(huf7.compression(" ")))) != " ")
        cout << "error delimiter\n";

    // Huffman huf8;
    // fstream in, out;
    // in.open("input.png");
    // out.open("output.png", ios::out | ios::trunc);
    // if (in.fail() || out.fail())
    //     cout << "error find file\n";
    // else
    //     huf8.decompression(huf8.compression(in), out);
    // in.close();
    // out.close();

    return 0;
}
