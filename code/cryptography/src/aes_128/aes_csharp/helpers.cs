/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 */

﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AES
{
    public class Helpers
    {
        // Shift all bytes left by one position.
        public static void ShiftBytesLeft(byte[] bytes)
        {
            byte tmp = bytes[0];
            int i;

            for(i = 0; i < bytes.Length - 1; ++i)
                bytes[i] = bytes[i + 1];

            bytes[i] = tmp;
        }

        // Shift all bytes right by one position
        public static void ShiftBytesRight(byte[] bytes)
        {
            byte tmp = bytes.Last();
            int i;

            for (i = bytes.Length - 1; i > 0; --i)
                bytes[i] = bytes[i - 1];

            bytes[0] = tmp;
        }

        public static uint ShiftWordLeft(uint word)
        {
            byte[] b = new byte[4];

            b[0] = (byte)((word & 0xff000000) >> 24);
            b[1] = (byte)((word & 0x00ff0000) >> 16);
            b[2] = (byte)((word & 0x0000ff00) >> 8);
            b[3] = (byte)(word & 0x000000ff);

            return (uint)(b[0] + (b[3] << 8) + (b[2] << 16) + (b[1] << 24));
        }

        public static void SubBytes(byte[] bytes, byte[,] sbox)
        {
            byte row, col;

            for(int i = 0; i < bytes.Length; ++i)
            {
                row = (byte)((bytes[i] & 0xf0) >> 4);
                col = (byte)(bytes[i] & 0x0f);

                bytes[i] = sbox[row, col];
            }
        }

        public static uint SubWord(uint word, byte[,] sbox)
        {
            int i, row, col, cpt = 24;
            uint mask = 0xff000000, ret = 0;
            byte b;

            for(i = 0; i < 4; ++i)
            {
                b = (byte)((word & mask) >> cpt);
                row = (b & 0xf0) >> 4;
                col = b & 0x0f;

                ret += (uint)(sbox[row, col] << cpt);

                mask >>= 8;
                cpt -= 8;
            }

            return ret;
        }

        public static byte X_Time(byte a)
        {
            int tmp = a & 0x80;
            a <<= 1;

            if (tmp == 0x80)
                a ^= 0x1b;

            return a;
        }

        public static int GetAESNbRounds(int nk)
        {
            return 10 + nk - 4;
        }
    }
}
