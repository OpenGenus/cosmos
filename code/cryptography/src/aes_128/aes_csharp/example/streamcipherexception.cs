using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace AES
{
    public class StreamCipherException : Exception
    {
        public enum Code
        {
            CantRead, CantWrite
        }

        public Code ErrorCode { get; set; }

        public StreamCipherException(Code ErrorCode) : base()
        {
            this.ErrorCode = ErrorCode;
        }
    }
}
