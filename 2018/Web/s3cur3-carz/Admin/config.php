<?php

$host = 'localhost';
$user = 'root';
$pass = 'toor';
$dbname = 'mock';

$conn = mysqli_connect($host, $user, $pass, $dbname);

if(!$conn)
	die("Error in Connection");

?>

