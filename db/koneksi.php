<?php
$servername = "127.0.0.1";
$database = "mytest";
$username = "vmanz73";
$password = "vmanz1997";
$konek = mysqli_connect ($servername, $username, $password, $database); 
$sql = "SELECT * FROM `dht`";
if (!$konek) {
    die("Connection failed: " . mysqli_connect_error());
}


?>