/**
    Part of Cosmos by OpenGenus Foundation.

    Implementation of Repository Pattern in Kotlin.
    
    References:
    - https://martinfowler.com/eaaCatalog/repository.html
    - https://medium.com/swlh/repository-pattern-in-android-c31d0268118c

    Author: Ezra Lazuardy
    Website: https://ezralazuardy.com
    License: MIT License
 */

interface CoffeeAction {
    
    fun drink()
}

enum class CoffeeType {
    
    MOCCACINO, LATTE, AMERICANO, ESPRESSO
}

sealed class Coffee: CoffeeAction {
    
    data class Moccacino(val espressoAmount: Coffee.Espresso, val withMilk: Boolean): Coffee() {
        
        override fun drink() =
        	println("drinking a cup of ${this::class.java.simpleName}${if(withMilk) " (with a steamed milk)" else ""}.")
    }
    
    data class Latte(val espressoAmount: Coffee.Espresso, val withMilk: Boolean): Coffee() {
        
        override fun drink() =
        	println("drinking a cup of ${this::class.java.simpleName}${if(withMilk) " (with a steamed milk)" else ""}.")
    }
    
    data class Americano(val espressoAmount: Coffee.Espresso, val hotWater: Int): Coffee() {
        
        override fun drink() =
        	println("drinking ${this::class.java.simpleName} (with $hotWater mg amount of hot water).")
    }
    
    data class Espresso(val coffeeAmount: Int, val hotWater: Int): Coffee() {
        
        override fun drink() =
        	println("drinking ${this::class.java.simpleName} (with $hotWater mg amount of hot water).")
    }
}

object CoffeeRepository {
    
    fun getMilkBasedCoffee(type: CoffeeType, withMilk: Boolean = true): Coffee =
        when(type) {
            CoffeeType.MOCCACINO -> Coffee.Moccacino(Coffee.Espresso(8, 8), withMilk)
            CoffeeType.LATTE -> Coffee.Latte(Coffee.Espresso(5, 8), withMilk)
            else -> throw IllegalArgumentException()
        }
    
    fun getBlackCoffee(type: CoffeeType, hotWater: Int = 10): Coffee =
        when(type) {
            CoffeeType.AMERICANO -> Coffee.Americano(Coffee.Espresso(10, 10), hotWater)
            CoffeeType.ESPRESSO -> Coffee.Espresso(15, hotWater)
            else -> throw IllegalArgumentException()
        }
}

class CoffeeFactory() {
    
    fun makeMoccacino(withMilk: Boolean = true): Coffee =
        CoffeeRepository.getMilkBasedCoffee(CoffeeType.MOCCACINO, withMilk)
    
    fun makeLatte(withMilk: Boolean = true): Coffee =
    	CoffeeRepository.getMilkBasedCoffee(CoffeeType.LATTE, withMilk)
        
    fun makeAmericano(hotWater: Int = 12): Coffee =
    	CoffeeRepository.getBlackCoffee(CoffeeType.AMERICANO, hotWater)
        
    fun makeEspresso(): Coffee =
    	CoffeeRepository.getBlackCoffee(CoffeeType.ESPRESSO)
}

fun main() {
    
    // initialize the factory
    val factory = CoffeeFactory()
    
    // make a moccacino
    val coffee = factory.makeMoccacino()
    
    // drink it!
    coffee.drink()
}