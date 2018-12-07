<?php

include('flag.php');

highlight_file('index.php');

$a = $_GET['key1'];

if($a==56 || $a>256){
  die("Really???");
}
elseif(chr($a)==="8"){
  echo "Carry on" . "<br>";
  echo $flag1 . "<br>";
}
else{
  die("You are not good");
}

$b = $_GET['key2'];

if(strpos($b,'8')!==false){
  die("It won't be that easy");
}
for($i=0;$i<=1;$i++){
  ++$b;
}
if($b==10){
  echo "Good luck" . "<br>";
  echo $flag2 . "<br>";
}
else{
  die("No Luck");
}

$m = md5($_GET['rq']);

if($_GET['fp'] == $m){
  echo $flag3."<br>";
}
elseif(isset($fp)){
  die("You failed");
}

$n = hash('ripemd160',$_GET['np']);

if($_GET['nq'] === $n){
  echo $flag4."<br>";
}
elseif(isset($np)){
  die("You failed");
}

$hell=$_GET['key3'];
if(strpos($hell, 'i')!==false || strpos($hell, 'I')!==false){
  die("You...can't...");
}
$data = unserialize($hell);
if ($data['username'] == $adminName && $data['password'] == $adminPassword) {
 echo $flag5 . "<br>";
} else {
 die("useless");
}

?>
