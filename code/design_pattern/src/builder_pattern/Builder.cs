using System;
using System.Collections.Generic;

namespace SandBox
{
	/// <summary>
	/// Acts as the "Director" class.
	/// 
	/// An intermediary between the customer (main) and the manufacturer.
	/// Unaware of the intracacies of building each product.
	/// </summary>
	class Dealer
	{
		/// <summary>
		/// Orders a vehicle from a Manufacturer.
		/// </summary>
		/// <param name="manufacturer">The manufacturer to order from</param>
		public Vehicle Order(Manufacturer manufacturer)
		{
			return manufacturer.BuildVehicle();
		}
	}

	/// <summary>
	/// Template class for each Manufacturer to follow.
	/// Allows for easy extensibility, while maintaining consistency.
	/// </summary>
	abstract class Manufacturer
	{
		public Vehicle Vehicle { get; protected set; }

		public abstract Vehicle BuildVehicle();
	}

	/// <summary>
	/// 1 of 3.
	/// An example of one of the many possible builder classes that extend the 
	/// abstract class Manufacturer.
	/// </summary>
	class MotorCycleManufacturer : Manufacturer
	{
		public string ManufacturerName = "MotorCycle";
		public MotorCycleManufacturer()
		{
		}

		public override Vehicle BuildVehicle()
		{
			var vehicle = new Vehicle(ManufacturerName);
			vehicle.Parts.Add("Body", "Bike");
			vehicle.Parts.Add("Handlebars", "Stock");
			vehicle.Parts.Add("Wheels", "Two-Wheeled");

			return vehicle;
		}
	}

	/// <summary>
	/// 2 of 3.
	/// An example of one of the many possible builder classes that extend the 
	/// abstract class Manufacturer.
	/// </summary>
	class SUVManufacturer : Manufacturer
	{
		private string ManufacturerName = "SUV";
		public SUVManufacturer()
		{
		}

		public override Vehicle BuildVehicle()
		{
			var vehicle = new Vehicle(ManufacturerName);
			vehicle.Parts.Add("Body", "Large-Box");
			vehicle.Parts.Add("Steering Wheel", "Stock");
			vehicle.Parts.Add("Wheels", "Four-Wheeled");

			return vehicle;
		}
	}

	/// <summary>
	/// 3 of 3.
	/// An example of one of the many possible builder classes that extend the 
	/// abstract class Manufacturer.
	/// </summary>
	class ConvertibleManufacturer : Manufacturer
	{
		private string ManufacturerName = "Convertible";
		public ConvertibleManufacturer()
		{
		}

		public override Vehicle BuildVehicle()
		{
			var vehicle = new Vehicle(ManufacturerName);
			vehicle.Parts.Add("Body", "Small-Sleek");
			vehicle.Parts.Add("Steering Wheel", "Stock");
			vehicle.Parts.Add("Wheels", "Four-Wheeled");
			vehicle.Parts.Add("Roof", "Soft-Top");

			return vehicle;
		}
	}

	/// <summary>
	/// Acts as the item being built.
	/// 
	/// Each item starts generic, then the manufacturer makes it unique. The
	/// process is abstracted from the item.
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
			Console.WriteLine("\n---------------------------");
			Console.WriteLine("Vehicle Type: {0}", Make);

			foreach (var part in Parts)
				Console.WriteLine("  {0} : {1}", part.Key, part.Value);
		}
	}

	class Program
	{
		static void Main(string[] args)
		{
			var MotorCycleManufacturer = new MotorCycleManufacturer();
			var motorCycle = MotorCycleManufacturer.BuildVehicle();
			motorCycle.Show();

			var SUVManufacturer = new SUVManufacturer();
			var suv = SUVManufacturer.BuildVehicle();
			suv.Show();

			var ConvertibleManufacturer = new ConvertibleManufacturer();
			var convertible = ConvertibleManufacturer.BuildVehicle();
			convertible.Show();
		}
	}
}
