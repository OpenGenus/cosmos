#include <string>
#include <iostream>

template<typename T>
class Singleton
{
public:
    static T* GetInstance();
    static void destroy();

private:

    Singleton(Singleton const&)
    {
    };
    Singleton& operator=(Singleton const&)
    {
    };

protected:
    static T* m_instance;

    Singleton()
    {
        m_instance = static_cast <T*> (this);
    };
    ~Singleton()
    {
    };
};

template<typename T>
T * Singleton<T>::m_instance = 0;

template<typename T>
T* Singleton<T>::GetInstance()
{
    if (!m_instance)
        Singleton<T>::m_instance = new T();

    return m_instance;
}

template<typename T>
void Singleton<T>::destroy()
{
    delete Singleton<T>::m_instance;
    Singleton<T>::m_instance = 0;
}

class TheCow : public Singleton<TheCow>
{
public:
    void SetSays(std::string &whatToSay)
    {
        whatISay = whatToSay;
    };
    void Speak(void)
    {
        std::cout << "I say" << whatISay << "!" << std::endl;
    };
private:
    std::string whatISay;
};

void SomeFunction(void)
{
    std::string say("moo");
    TheCow::GetInstance()->SetSays(say);
}

int main ()
{
    std::string say("meow");
    TheCow::GetInstance()->SetSays(say);
    SomeFunction();
    TheCow::GetInstance()->Speak();
}
