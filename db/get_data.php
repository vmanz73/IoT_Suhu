<?php
function data($val){
    include ("koneksi.php");
    $db = mysqli_query($konek, "SELECT * FROM `dht` ORDER BY `time` DESC");
    if ($data = mysqli_fetch_array($db) ){
        
        return $data[$val];
    }
}
?>