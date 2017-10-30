<?php

interface OutputInterface
{
    public function output(array $data);
}

class JsonOutput implements OutputInterface
{
    public function output (array $data)
    {
        return json_encode($data);
    }
}

class SerializeOutput implements OutputInterface
{
    public function output (array $data)
    {
        return serialize($data);
    }
}

class SomeController
{
    private $output;

    public function setOutput(OutputInterface $output)
    {
        $this->output = $output;
    }

    public function render()
    {
        $data = [
            'test',
            'abc'
        ];
        echo $this->output->output($data);
    }
}

$oController = new SomeController();
$oController->setOutput(new JsonOutput());
# $oController->setOutput(new SerializeOutput());
$oController->render();
