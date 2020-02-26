<?php 
include ("../db/koneksi.php");
$temp = $_GET['suhu'];
$humi = $_GET['kelem'];
mysqli_query($konek, "INSERT INTO `data_sensor` (`suhu`, `kelem`) VALUES ( $temp, $humi)");
?> 