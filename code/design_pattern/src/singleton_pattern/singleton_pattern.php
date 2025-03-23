<?php

/**
 * Singleton class
 */
final class Singleton
{
    private static ?Singleton $instance = null;

    /**
     * New instance is created here in method getInstance
     */
    public static function getInstance()
    {
        if (static::$instance == null) {
            static::$instance = new static();
        }

        return static::$instance;
    }

    /**
     * Constructor is declared as protected to prevent creating new instance outside of the class
     */
    protected function __construct()
    {
        //
    }

    /**
     * Clone method is declared as private to prevent clone an instance of the class
     */
    private function __clone()
    {
        //
    }

    /**
     * Wakeup method is delcared to private  to prevent unserializing
     */
    private function __wakeup()
    {
        //
    }
}

// Initializing Singleton instance
$singleton = Singleton::getInstance();
