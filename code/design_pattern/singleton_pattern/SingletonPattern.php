<?php

/**
 * Singleton Design Pattern
 * 
 * @author Anton Vendin
 * @version 1.0
 * 
 */

class Singleton
{

	private static $singletonInstance;

	public static function getInstance() {

		if (static::$singletonInstance === null ) {
			static::$singletonInstance = new Singleton();
		}
		return static::$singletonInstance;
	}
}

$instance = Singleton::getInstance();
print $instance === Singleton::getInstance();
