using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace AES
{
    public class StreamCipher
    {
        AESCipher TheCipher;

        public StreamCipher(byte[] MainKey)
        {
            TheCipher = new AESCipher(MainKey);
        }

        // Abstract stream ciphering
        public void DoCipher(Stream Src, Stream Dest)
        {
            DoTheJob(Src, Dest, true);
        }

        public void DoDecipher(Stream Src, Stream Dest)
        {
            DoTheJob(Src, Dest, false);
        }

        private void DoTheJob(Stream Src, Stream Dest, bool Cipher)
        {
            if (!Src.CanRead)
                throw new StreamCipherException(StreamCipherException.Code.CantRead);

            if (!Dest.CanWrite)
                throw new StreamCipherException(StreamCipherException.Code.CantWrite);

            byte[] SrcBuff = new byte[AES.AESCipher.BlockSize],
                   DestBuff = new byte[AES.AESCipher.BlockSize];

            int n, i;
            while((n = Src.Read(SrcBuff, 0, AESCipher.BlockSize)) != 0)
            {
                // If we read less caracters then the size of an AES block,
                // we fill remaining boxes with zeros.
                for (i = n; i < AESCipher.BlockSize; ++i)
                    SrcBuff[i] = 0;

                if (Cipher)
                    TheCipher.DoCipher(SrcBuff, DestBuff);

                else
                    TheCipher.DoDecipher(SrcBuff, DestBuff);

                Dest.Write(DestBuff, 0, AESCipher.BlockSize);
            }
        }
    }
}
