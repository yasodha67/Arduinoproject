<html>
<body>

<?php
$timestamp = $_GET['timestamp'];
$door_status = $_GET['door_status'];
$persons_detected = $_GET['persons_detected'];

// Database connection details
$servername = "localhost";
$username = "Yasodha";
$password = "ArduinoStarted.com";
$dbname = "db_door"; // Replace with your database name

// Create a connection
$conn = new mysqli($servername, $username, $password,$dbname); 

// Check the connection
if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

// Check if the POST request contains the sensor value
if (isset($_POST["door_status"]) && isset($_POST["persons_detected"])){
	$d = $_POST["door_status"];
	$p = $_POST["persons_detected"];
    $t = $_POST["timestamp"];

    // Prepare the SQL statement to insert data into the table
    $sql = "INSERT INTO motion (door_status,persons_detected) VALUES (".$d.", ".$p.",".$t.")";

    if ($conn->query($sql) === TRUE) {
        echo "Data stored successfully";
    } else {
        echo "Error storing data: " . $conn->error;
    }
} else {
    echo "Sensor value not received";
}

// Close the database connection
$conn->close();
?>

</body>
</html>
