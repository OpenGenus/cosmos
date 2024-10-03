module Subject
  def initialize
    @observers = []
  end

  def register_observer(observer)
    @observers << observer
  end

  def remove_observer(observer)
    @observers.delete(observer)
  end

  def notify_observers
    @observers.each { |observer| observer.update(self) }
  end
end

class WeatherData
  include Subject

  attr_reader :temperature, :humidity, :pressure

  def set_measurements(t, h, p)
    @temperature = t
    @humidity = h
    @pressure = p
    notify_observers
  end

  def temperature=(new_temp)
    @temperature = new_temp
    notify_observers
  end

  def humidity=(new_hum)
    @humidity = new_hum
    notify_observers
  end

  def pressure=(new_pre)
    @pressure = new_pre
    notify_observers
  end
end

class CurrentConditionDisplay
  def initialize(wd)
    @weather_data = wd
    wd.register_observer(self)
  end

  def update(wd)
    @temperature = wd.temperature
    @humidity = wd.humidity
    display
  end

  def display
    puts "Current condition: #{@temperature}F degrees #{@humidity}% humidity"
  end
end

class WeatherStation
  def initialize
    @weather_data = WeatherData.new
    @current_display = CurrentConditionDisplay.new(@weather_data)
    @weather_data.set_measurements(80, 65, 30.4)
    @weather_data.set_measurements(82, 70, 29.2)
    @weather_data.set_measurements(78, 90, 29.2)
  end
end

WeatherStation.new
