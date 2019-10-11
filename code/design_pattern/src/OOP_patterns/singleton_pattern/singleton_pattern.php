<?php

/**
* Simple singleton class which could only have one instance
* Part of Cosmos by OpenGenus Foundation
*/
class Singleton
{
}

/**
* Class which creates instance of Singleton if it does not exists
*/
class SingletonInstanter 
{
    private static $instance;
    
    public static function getInstance() {
        if (empty(self::$instance)) {
            self::$instance = new Singleton();
        }
        return self::$instance;
    }
}
