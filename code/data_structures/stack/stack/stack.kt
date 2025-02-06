/* Part of Cosmos by OpenGenus Foundation */

import java.util.ArrayList

internal class Stack<T>(private val maxSize: Int) {
    private val stackArray: ArrayList<T> = ArrayList()
    private var top: Int = 0

    val isEmpty: Boolean
        get() = top == -1

    val isFull: Boolean
        get() = top + 1 == maxSize

    init {
        top = -1
    }

    fun push(value: T) {
        if (!isFull) { //Checks for a full stack
            top++
            if (stackArray.size <= top)
                stackArray.add(top, value)
            else
                stackArray[top] = value
            //stackArray[top] = value;
        } else {
            println("The stack is full, can't insert value")
        }
    }

    fun pop(): T {
        return if (!isEmpty) { //Checks for an empty stack
            stackArray[top--]
        } else {
            throw IndexOutOfBoundsException()
        }
    }

    fun peek(): T {
        return if (!isEmpty) { //Checks for an empty stack
            stackArray[top]
        } else {
            throw IndexOutOfBoundsException()
        }
    }

    fun makeEmpty() { //Doesn't delete elements in the array but if you call
        top = -1             //push method after calling makeEmpty it will overwrite previous values
    }
}

object Stacks {
    /**
     * Main method
     *
     * @param args Command line arguments
     */
    @JvmStatic
    fun main(args: Array<String>) {
        val myStack = Stack<Int>(4) //Declare a stack of maximum size 4
        //Populate the stack
        myStack.push(5)
        myStack.push(8)
        myStack.push(2)
        myStack.push(9)

        println("*********************Stack Array Implementation*********************")
        println(myStack.isEmpty) //will print false
        println(myStack.isFull) //will print true
        println(myStack.peek()) //will print 9
        println(myStack.pop()) //will print 9
        println(myStack.peek()) // will print 2
    }
}
