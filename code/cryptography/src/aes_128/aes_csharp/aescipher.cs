/*
 * Part of Cosmos by OpenGenus Foundation.
 * Author : ABDOUS Kamel
 */
 
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AES
{
    public partial class AESCipher
    {
        // Size of MainKey will determine which version of AES to use.
        // An ArgumentException is thrown in case of unknown size.
        public AESCipher(byte[] MainKey)
        {
            this.MainKey = MainKey;
        }

        // Cipher a block of size AESCipher.BlockSize (see AESConsts.cs).
        // The array CipherText must be of size AESCipher.BlockSize.
        public void DoCipher(byte[] PlainText, byte[] CipherText)
        {
            byte[][] State = new byte[4][];
            int i, j;

            for(i = 0; i < 4; ++i)
            {
                State[i] = new byte[StateNB];
                for (j = 0; j < StateNB; ++j)
                    State[i][j] = PlainText[i + StateNB * j];
            }

            AddRoundKey(State, 0);

            for(i = 1; i < NR; ++i)
            {
                SubBytes(State, SubByte_SBox);
                ShiftRows(State);

                MixColumns(State);
                AddRoundKey(State, i);
            }

            SubBytes(State, SubByte_SBox);
            ShiftRows(State);
            AddRoundKey(State, NR);

            for(i = 0; i < 4; ++i)
            {
                for (j = 0; j < StateNB; ++j)
                    CipherText[i + StateNB * j] = State[i][j];
            }
        }

        protected void SubBytes(byte[][] State, byte[,] sbox)
        {
            for(int i = 0; i < 4; ++i)
                Helpers.SubBytes(State[i], sbox);
        }

        protected void ShiftRows(byte[][] State)
        {
            for(int i = 0; i < StateNB; ++i)
            {
                for (int j = 0; j < i; ++j)
                    Helpers.ShiftBytesLeft(State[i]);
            }
        }

        protected void MixColumns(byte[][] State)
        {
            byte[][] buff = new byte[4][];
            int i, j;

            for(i = 0; i < 4; ++i)
            {
                buff[i] = new byte[StateNB];
                State[i].CopyTo(buff[i], 0);
            }

            for(i = 0; i < StateNB; ++i)
            {
                State[0][i] = (byte)(GF_MulArray[buff[0][i], 0] ^ GF_MulArray[buff[1][i], 1] ^ buff[2][i] ^ buff[3][i]);
                State[1][i] = (byte)(buff[0][i] ^ GF_MulArray[buff[1][i], 0] ^ GF_MulArray[buff[2][i], 1] ^ buff[3][i]);
                State[2][i] = (byte)(buff[0][i] ^ buff[1][i] ^ GF_MulArray[buff[2][i], 0] ^ GF_MulArray[buff[3][i], 1]);
                State[3][i] = (byte)(GF_MulArray[buff[0][i], 1] ^ buff[1][i] ^ buff[2][i] ^ GF_MulArray[buff[3][i], 0]);
            }
        }

        protected void AddRoundKey(byte[][] State, int round)
        {
            uint rkey;
            int cpt = 24;

            for(int i = 0; i < 4; ++i)
            {
                rkey = RoundKeys[StateNB * round + i];
                for(int j = 0; j < StateNB; ++j)
                {
                    State[j][i] ^= (byte)((rkey >> cpt) & 0x000000ff);
                    cpt -= 8;
                }
            }
        }
    }
}
