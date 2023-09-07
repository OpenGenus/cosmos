<?php

class Node
{
    public $value, $next;

    public function __construct($value, $next) {
        $this->value = $value;
        $this->next = $next;
    }

    public function __toString() {
        return (string)$this->value;
    }
}

class CircularLinkedList
{
    private $head, $tail;

    public function __construct() {
        $this->head = null;
        $this->tail = null;
    }

    public function add(int $value): void {
        $node = new Node($value, $this->head);
        if ($this->isEmpty()) {
            $this->head = $this->tail = $node;
        } else {
            $this->tail->next = $node;
            $this->tail = $node;
        }
    }

    public function remove(int $value): void {
        if ($this->isEmpty()) {
            return;
        }

        if ($this->head === $this->tail) {
            $this->head = $this->tail = null;
            return;
        }

        $curr = $this->head;

        $prev = null;
        while ($curr->next !== $this->head) {
            if ($curr->value === $value) {
                $prev->next = $curr->next;
                return;
            }
            $prev= $curr;
            $curr = $curr->next;
        }

        if ($curr->value === $value) {
            $prev->next = $this->head;
            $this->tail = $prev;

        }
    }

    private function isEmpty(): bool {
        return $this->head === null;
    }

    public function print(): string {
        if ($this->isEmpty()) {
            return '';
        }

        $curr = $this->head;
        $output = "${curr}, ";
        while ($curr !== $this->tail) {
            $curr = $curr->next;
            $output .= "${curr}, ";
        }

        return substr($output, 0, -2);
    }
}

$list = new CircularLinkedList();
$list->add(1);
$list->add(7);
$list->add(104);

$result = $list->print() === '1, 7, 104' ? 'OK' : 'ERROR';
echo "add() test: ${result}", PHP_EOL;

$list->remove(7);
$result = $list->print() === '1, 104' ? 'OK' : 'ERROR';
$list->remove(8);
$result = $result && $list->print() === '1, 104' ? 'OK' : 'ERROR';
$list->remove(104);
$result = $result && $list->print() === '1' ? 'OK' : 'ERROR';
$list->remove(1);
$result = $result && $list->print() === '' ? 'OK' : 'ERROR';
echo "remove() test: ${result}", PHP_EOL;
