<?php
error_reporting(0); 
include "./config.php"; 
include "./flag.php"; 
if(isset($_GET['bypass']) && !iconv("UTF-8","UTF-8//IGNORE",$_GET['bypass'])) exit(":P LOL!!");
if(isset($_GET['bypass']) && strlen($_GET['bypass'])>1) exit(":(");
if(preg_match('/ |\n|\r|\t/i', $_GET['bypass'])) exit(":(");
$black_list = "/admin|guest|&|limit|by|as|substr|mid|or|not|ascii|char|union|select|greatest|%00|\"|benchmark|"; 
$black_list .= "=|_|in|<|>|sqlauth| |-|_|\.|\(\)|regexp|and|if|database|where|concat|insert|havin|#|0x|0b|sleep/i"; 
if(preg_match($black_list, $_GET['pass'])) exit(":P");
if(preg_match('/\b=\b/i', $_GET['pass'])) exit("No =");
if(preg_match('/\bregexp\b/i', $_GET['pass'])) exit("No regexp");
if(preg_match('/\blike\b/i', $_GET['pass'])) exit("No like");
$query = "select user from back_to_sql{$_GET['bypass']}where user='guest' and pw='{$_GET[pass]}'"; 
$result = @mysql_fetch_array(mysql_query($query)); 
if($result['user'])
{
	echo "<h1>Hello ".$result['user']."</h1>";
}
$admin_info =  @mysql_fetch_array(mysql_query('select * from back_to_sql where user="admin"')); 
echo "<h2>query : {$query}</h2>";
if(($admin_info['pw']) && $admin_info['pw']===$_GET['pass']) 
{ 
    echo $flag;
} 
highlight_file(__FILE__);
?> 
