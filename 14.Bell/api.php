<?php
// Database configuration
$servername = "localhost";
$username = "root";
$password = "";
$database = "bell";

// Create connection
$conn = new mysqli($servername, $username, $password, $database);

// Check connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Fetch schedule from database
$sql = "SELECT * FROM bell_schedule";
$result = $conn->query($sql);

if ($result->num_rows > 0) {
    // Output data of each row
    $rows = array();
    while($row = $result->fetch_assoc()) {
        $rows[] = $row;
    }
    echo json_encode($rows);
} else {
    echo "0 results";
}
$conn->close();
?>
