<?php 
include ("../db/koneksi.php");
$temp = $_GET['suhu'];
$humi = $_GET['kelem'];
mysqli_query($konek, "INSERT INTO `dht` (`id`, `temp`, `humi`, `time`) VALUES (NULL, $temp, $humi, CURRENT_TIMESTAMP)");
?> 