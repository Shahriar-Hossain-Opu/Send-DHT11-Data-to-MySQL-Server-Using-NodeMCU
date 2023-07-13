<?php
if (isset($_GET["t"]) && isset($_GET["h"])) {
    $t = $_GET["t"];
    $h = $_GET["h"];
    $db = new mysqli("localhost", "root", "", "temphumidnew");
    $sql="INSERT INTO `DHT_Table`(`temp`, `hum`) VALUES ($t,$h)";
    $db->query($sql);
}