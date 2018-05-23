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
        public void DoDecipher(byte[] CipherText, byte[] PlainText)
        {
            byte[][] State = new byte[4][];
            int i, j;

            for(i = 0; i < 4; ++i)
            {
                State[i] = new byte[StateNB];
                for (j = 0; j < StateNB; ++j)
                    State[i][j] = CipherText[i + StateNB * j];
            }

            AddRoundKey(State, NR);

            for(i = NR - 1; i > 0; --i)
            {
                InvShiftRows(State);
                SubBytes(State, InvSubBytes_SBox);

                AddRoundKey(State, i);
                InvMixColumns(State);
            }

            InvShiftRows(State);
            SubBytes(State, InvSubBytes_SBox);

            AddRoundKey(State, 0);

            for(i = 0; i < 4; ++i)
            {
                for (j = 0; j < StateNB; ++j)
                    PlainText[i + StateNB * j] = State[i][j];
            }
        }

        protected void InvShiftRows(byte[][] State)
        {
            for(int i = 0; i < 4; ++i)
            {
                for(int j = 0; j < i; ++j)
                    Helpers.ShiftBytesRight(State[i]);
            }
        }

        protected void InvMixColumns(byte[][] State)
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
                State[0][i] = (byte)(GF_MulArray[buff[0][i], 5] ^ GF_MulArray[buff[1][i], 3] ^ GF_MulArray[buff[2][i], 4] ^ GF_MulArray[buff[3][i], 2]);
                State[1][i] = (byte)(GF_MulArray[buff[0][i], 2] ^ GF_MulArray[buff[1][i], 5] ^ GF_MulArray[buff[2][i], 3] ^ GF_MulArray[buff[3][i], 4]);
                State[2][i] = (byte)(GF_MulArray[buff[0][i], 4] ^ GF_MulArray[buff[1][i], 2] ^ GF_MulArray[buff[2][i], 5] ^ GF_MulArray[buff[3][i], 3]);
                State[3][i] = (byte)(GF_MulArray[buff[0][i], 3] ^ GF_MulArray[buff[1][i], 4] ^ GF_MulArray[buff[2][i], 2] ^ GF_MulArray[buff[3][i], 5]);
            }
        }
    }
}
