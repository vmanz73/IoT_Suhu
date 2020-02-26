<?php
include ("../db/get_data.php");
echo data('temp')."°C";
mysqli_close($konek);
?>