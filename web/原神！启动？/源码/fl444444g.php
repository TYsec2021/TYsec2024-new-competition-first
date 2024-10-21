<?php
error_reporting(0);
highlight_file(__FILE__);

class Genshin_impact
{
    public $url="https://www.yuanshen.com/";
    public $element;
    public $skill;

    public function __destruct()
    {
        $role=$this->element;
        $role($this->skill);
    }
}
$payload=$_POST['payload'];
unserialize($payload);

?>