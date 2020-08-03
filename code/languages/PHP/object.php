<?php

class heroes{
    var $name;
    var $uni;
    
    function setName($nam){
        $this->name=$nam;
    }
    function getName(){
        echo $this->name;
    }
    
}
$hulk=new heroes;
$hulk->setName('Bruce');
$hulk->getName();

?>