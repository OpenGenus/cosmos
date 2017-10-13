<?php

/**
 * Stack implementation
 * Part of Cosmos by OpenGenus Foundation
 * Note: To run this script, you need PHP >= 7.1
 * 
 * @author Lucas Soares Candalo <candalolucas@gmail.com>
 */
class Stack
{
    /**
     * @var array
     */
    private $elements = [];

    /**
     * Removes an item from the stack
     *
     * @return void
     */
    public function pop(): void
    {
        if (!$this->isEmpty()) {
            array_pop($this->elements);
        }
    }

    /**
     * Adds an item to the stack
     *
     * @param int $element
     * @return void
     */
    public function push(int $element): void
    {
        array_push($this->elements, $element);
    }

    /**
     * Gets the top element of the stack
     *
     * @return int
     */
    public function peek(): int
    {
        return end($this->elements);
    }

    /**
     * Checks if the stack is empty
     *
     * @return bool true if is empty, false otherwise
     */
    public function isEmpty(): bool
    {
        return empty($this->elements);
    }
}

class StackPrinter
{
    /**
     * Print stack elements
     *
     * @param Stack $stack
     * @return void
     */
    public function print(Stack $stack): void
    {
        $stackClone = clone $stack;

        echo "Stack elements:\n\n";
        while(!$stackClone->isEmpty()) {
            echo $stackClone->peek()."\n";
            $stackClone->pop();
        }
        echo "\n\n";
    }
}

$stack = new Stack();
$stackPrinter = new StackPrinter();

// Add a few elements to the stack
$stack->push(10);
$stack->push(20);
$stack->push(30);

// Print stack elements
$stackPrinter->print($stack);

// Remove top element from the stack
$stack->pop();

// Print stack elements again
$stackPrinter->print($stack);

// Remove top element from the stack
$stack->pop();

// Print stack elements again
$stackPrinter->print($stack);
