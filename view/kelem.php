<?php
include ("../db/get_data.php");
echo data('humi')."%";
mysqli_close($konek);
?>