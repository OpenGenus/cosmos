using System;
using System.Collections.Generic;

namespace SandBox
{
	/// <summary>
	/// Acts as the "Director" class.
	/// An intermediary between the customer (main) and the manufacturer.
	/// </summary>
	class Dealer
	{
		/// <summary>
		/// Orders a vehicle (generic) from a Manufacturer.
		/// </summary>
		/// <param name="manufacturer">The manufacturer in which to order from</param>
		public void Order(Manufacturer manufacturer)
		{
			manufacturer.BuildVehicle();
		}
	}

	/// <summary>
	/// Template class for each Manufacturer to follow.
	/// </summary>
	abstract class Manufacturer
	{
		public Vehicle Vehicle { get; protected set; }

		public abstract Vehicle BuildVehicle();
	}

	class PriusManufacturer : Manufacturer
	{
		private string ManufacturerName = "Prius";
		public PriusManufacturer()
		{
		}

		public override Vehicle BuildVehicle()
		{
			var vehicle = new Vehicle(ManufacturerName);
			vehicle.Parts.Add("Battery", "SuperPoweredRecharging");
			vehicle.Parts.Add("Brakes", "Regenative");

			return vehicle;
		}
	}

	class TeslaManufacturer : Manufacturer
	{

	}

	/// <summary>
	/// Acts as item being built.
	/// Each manufacturer could add different parts.
	/// </summary>
	class Vehicle
	{
		public readonly string Make;
		public Dictionary<string, string> Parts = new Dictionary<string, string>();

		public Vehicle(string manufacturer)
		{
			this.Make = manufacturer;
		}

		public void Show()
		{
			Console.WriteLine("\n------------------------------");
			Console.WriteLine("Manufacturer: {0}", Make);

			foreach (var part in Parts)
				Console.WriteLine(" {0} : {1}", part.Key, part.Value);
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			
		}
	}
}
