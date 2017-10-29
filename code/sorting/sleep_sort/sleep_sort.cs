/* Part of Cosmos by OpenGenus Foundation */
using System;
using System.Threading;
using System.Linq;

namespace dotnetcore
{
  class Program
  {
    static void Main(string[] args)
    {
      SleepSort(new int[] {5, 4, 1, 2, 3});
    }

    static void SleepSort(int[] data)
    {
      data.AsParallel().WithDegreeOfParallelism(data.Length).Select(SleepAndReturn).ForAll(Console.WriteLine);
    }

    static int SleepAndReturn(int interval)
    {
      Thread.Sleep(interval*interval);
      return interval;
    }
  }
}
