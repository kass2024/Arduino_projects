<?php 
    $serverName = "localhost";
    $userName = "root";
    $password = "password";
    $dbName = "database_name";

    //creat connection
    $conn = new mysqli($serverName,$userName, $password, $dbName);

    $query = "Select * FROM status ORDER BY id DESC LIMIT 1";
    $res = mysqli_query($conn, $query);
    $data = mysqli_fetch_array($res);
    $i_status = $data['Led_on'];
    echo $i_status;

?>
    