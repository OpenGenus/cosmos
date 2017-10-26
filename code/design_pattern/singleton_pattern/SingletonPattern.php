<?php

class Singleton
{
    private static $instance;

    /**
     * The constructor is declared as protected to prevent creating
     * a new instance outside of the class via the new operator.
     */
    private function __construct() {}

    /**
     * The magic method __clone() is declared as private to prevent
     * cloning of an instance of the class via the clone operator.
     */
    private function __clone() {}

    /**
     * The magic method __wakeup() is declared as private to prevent
     * unserializing of an instance of the class via the global function
     * unserialize().
     */
    private function __wakeup() {}

    /**
     * @return Singleton
     */
    public static function getInstance()
    {
        if (null === self::$instance) {
            self::$instance = new Singleton();
        }

        return self::$instance;
    }
}

$singleton = Singleton::getInstance();
