abstract class Store
{
    protected Store successor;
    protected int capacity;

    public function setNext(Store store)
    {
        this.successor = store;
    }

    public function getElectricity(int electricityToUse)
    {
        if (this.canGetElectricity(electricityToUse)) {
            System.out.println("Got "+electricityToUse + "KW using " + this.getClass().getName());
        } else if (this.successor!=null) {
            echo sprintf("Cannot get electricity using "+this.getClass().getName()+". Proceeding ..");
            successor.getElectricity(electricityToUse);
        } else {
            throw new Exception("None of the stores have enough capacity to handle this request");
        }
    }

    public boolean canGetElectricity(electricityNeeded) {
        return this.capacity >= electricityNeeded;
    }
}

class AreaStore extends Store {
    protected int capacity;

    public AreaStore(int capacity) {
        this.capacity = capacity;
    }
}

class CityStore extends Store {
    protected int capacity;

    public CityStore(int capacity) {
        this.capacity = capacity;
    }
}

class CountryStore extends Store {
    protected int capacity;

    public CountryStore(int capacity) {
        this.capacity = capacity;
    }
}


// We will prepare the following chain
//      areaStore -> cityStore -> countryStore
//
// First priority is to use the areaStore
//      If areaStore can't handle the request then cityStore
//      If cityStore can't handle the request then countryStore

areaStore = new AreaStore(100);          // areaStore with capacity 100
cityStore = new CityStore(500);      // cityStore with capacity 500
countryStore = new CountryStore(10000);    // countryStore with capacity 10000

areaStore.setNext(cityStore);
cityStore.setNext(countryStore);

// Let's try to get electricity using the first priority i.e. areaStore
areaStore->pay(600);

// Output will be
// ==============
// Cannot get electricity using AreaStore. Proceeding ..
// Cannot get electricity using CityStore. Proceeding ..:
// Got 600 KW using CountryStore!
