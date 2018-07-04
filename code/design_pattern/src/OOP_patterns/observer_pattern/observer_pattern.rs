// Part of Cosmos by OpenGenus Foundation
use std::collections::HashMap;

#[derive(Debug, Clone, Copy)]
enum WeatherType {
    Clear,
    Rain,
    Snow,
}

#[derive(Debug, Clone, Copy)]
enum WeatherObserverMessage {
    WeatherChanged(WeatherType),
}

trait WeatherObserver {
    fn notify(&mut self, msg: WeatherObserverMessage);
}

struct WeatherObserverExample {
    name: &'static str,
}

impl WeatherObserver for WeatherObserverExample {
    fn notify(&mut self, msg: WeatherObserverMessage) {
        println!("{} was notified: {:?}", self.name, msg);
    }
}

struct Weather {
    weather: WeatherType,
    observers: HashMap<usize, Box<WeatherObserver>>,
    observer_id_counter: usize
}

impl Weather {
    pub fn attach_observer(&mut self, observer: Box<WeatherObserver>) -> usize {
        self.observers.insert(self.observer_id_counter, observer);
        self.observer_id_counter += 1;
        self.observer_id_counter - 1
    }

    pub fn detach_observer(&mut self, id: usize) -> Option<Box<WeatherObserver>> {
        self.observers.remove(&id)
    }

    pub fn set_weather(&mut self, weather_type: WeatherType) {
        self.weather = weather_type;
        self.notify_observers(WeatherObserverMessage::WeatherChanged(weather_type));
    }

    pub fn notify_observers(&mut self, msg: WeatherObserverMessage) {
        for obs in self.observers.values_mut() {
            obs.notify(msg);
        }
    }
}

fn main() {
    let mut weather = Weather {
        weather: WeatherType::Clear,
        observers: HashMap::new(),
        observer_id_counter: 0
    };

    let first_obs = weather.attach_observer(Box::new(WeatherObserverExample {
        name: "First Observer",
    }));

    weather.set_weather(WeatherType::Rain);

    weather.detach_observer(first_obs);

    weather.attach_observer(Box::new(WeatherObserverExample {
        name: "Second Observer",
    }));

    weather.set_weather(WeatherType::Snow);
}
