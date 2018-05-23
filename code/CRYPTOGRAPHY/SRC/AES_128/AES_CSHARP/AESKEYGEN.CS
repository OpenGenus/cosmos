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
        byte[] vMainKey;
        public byte[] MainKey
        {
            get
            {
                return vMainKey;
            }

            set
            {
                switch(value.Length)
                {
                    case 16:
                        GenRoundKeys(value, 4);
                        break;

                    case 24:
                        GenRoundKeys(value, 6);
                        break;

                    case 32:
                        GenRoundKeys(value, 8);
                        break;

                    default:
                        throw new ArgumentException("Unknown main key size.");
                }
                vMainKey = value;
            }
        }

        public uint[] RoundKeys { get; protected set; }

        public int NK { get; protected set; }

        public int NR { get; protected set; }

        protected void GenRoundKeys(byte[] MainKey, int nk)
        {
            int nr = Helpers.GetAESNbRounds(nk),
                i, j,
                rk_size = AESCipher.StateNB * (nr + 1);
            uint tmp;
            byte rcon = 0x01;

            RoundKeys = new uint[rk_size];

            for(i = 0; i < nk; ++i)
                RoundKeys[i] = (uint)((MainKey[i * 4] << 24) +
                                      (MainKey[i * 4 + 1] << 16) +
                                      (MainKey[i * 4 + 2] << 8) +
                                      (MainKey[i * 4 + 3]));

            while(i < rk_size)
            {
                tmp = RoundKeys[i - 1];

                if (i % nk == 0)
                {
                    tmp = Helpers.ShiftWordLeft(tmp);
                    tmp = Helpers.SubWord(tmp, AESCipher.SubByte_SBox);

                    tmp ^= ((uint)rcon) << 24;
                    rcon = Helpers.X_Time(rcon);
                }

                else if (nk > 6 && i % nk == 4)
                    tmp = Helpers.SubWord(tmp, AESCipher.SubByte_SBox);

                RoundKeys[i] = tmp ^ RoundKeys[i - nk];
                ++i;
            }

            this.NK = nk;
            this.NR = nr;
        }
    }
}
