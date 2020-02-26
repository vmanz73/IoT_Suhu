<?php
$servername = "127.0.0.1";
$database = "workshop";
$username = "vmanz73";
$password = "vmanz1997";
$konek = mysqli_connect ($servername, $username, $password, $database); 
if (!$konek) {
    die("Connection failed: " . mysqli_connect_error());
}


?>