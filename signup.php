<?php
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Retrieve data from the form
    $username = $_POST['username'];
    $password = $_POST['password'];

    // Your database connection code goes here
    // Replace with your own database connection details
    $servername = "localhost";
    $dbUsername = "root";
    $dbPassword = "";
    $dbName = "ecobin";

    // Create connection
    $conn = new mysqli($servername, $dbUsername, $dbPassword, $dbName);

    // Check connection
    if ($conn->connect_error) {
        die("Connection failed: " . $conn->connect_error);
    }
    $x = $_POST["username"];
    $y = $_POST["password"];
    // Create a SQL query (you might want to hash the password for security)
    $sql = "SELECT *FROM ecobin WHERE username = '$x' AND password = '$y'";
    $result = $conn->query($sql);

    if ($result->num_rows>0) {
        header("Location: analytics.html");
    } else {
        echo "Error: " . $sql . "<br>" . $conn->error;
    }

    $conn->close();
}
?>
