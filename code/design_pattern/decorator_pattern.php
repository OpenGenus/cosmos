class SimpleSay
{
    public function say() {
        echo 'hi';
    }
}

class NumberSayDecorator extends SimpleSay
{
    public function say() {
        parent::say();
        echo '123';
    }
}

class QuietSayDecorator extends SimpleSay 
{
    public function say()
    {
    }
}
