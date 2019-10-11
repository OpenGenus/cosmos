/*
 * observer_pattern.cpp
 *
 *  Created on: 26 May 2017
 *      Author: yogeshb2
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class IWeatherChanger
{
public:
    virtual ~IWeatherChanger()
    {
    }
    virtual void onTemperatureChange(int temperature) = 0;
};

class ITemperature
{
public:
    virtual ~ITemperature()
    {
    }
    virtual void addSubscriber(IWeatherChanger* w) = 0;
    virtual void removeSubscriber(IWeatherChanger* w) = 0;
    virtual void notifyAllSubscriber() = 0;
};

class Weather : public ITemperature
{
public:
    Weather() : temperature(0)
    {

    }
    void addSubscriber(IWeatherChanger* w)
    {
        if (w)
            subscriberlist.push_back(w);
    }
    void removeSubscriber(IWeatherChanger* w)
    {
        //TODO
        if (w)
        {
            vector<IWeatherChanger*>::iterator it =
                find(subscriberlist.begin(), subscriberlist.end(), w);
            if (it != subscriberlist.end())
                subscriberlist.erase(it);
            else
                cout << "Not a registered subscriber" << endl;
        }
    }
    void notifyAllSubscriber()
    {
        if (!subscriberlist.empty())
        {
            vector<IWeatherChanger*>::iterator it;
            for (it = subscriberlist.begin(); it != subscriberlist.end(); ++it)
                (*it)->onTemperatureChange(temperature);
        }
    }
    void changeTemperature(int temp)
    {
        temperature = temp;
        notifyAllSubscriber();
    }
private:
    int temperature;
    vector<IWeatherChanger*> subscriberlist;

};


class NewsChannel : public IWeatherChanger
{
public:
    NewsChannel()
    {

    }
    NewsChannel(string name)
    {
        this->name = name;
    }
    void onTemperatureChange(int temperature)
    {
        cout << "Channel name : " << name << " Temperature : " << temperature;
        cout << "\n";
    }
private:
    string name;

};

int main()
{
    Weather weather;
    NewsChannel fox("Fox News");
    NewsChannel times("Times News");
    weather.addSubscriber(&fox);
    weather.addSubscriber(&times);

    weather.changeTemperature(25);

    weather.changeTemperature(20);

    weather.removeSubscriber(&fox);

    weather.changeTemperature(10);

    return 0;
}
