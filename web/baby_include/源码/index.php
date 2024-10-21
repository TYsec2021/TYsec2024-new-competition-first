<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title></title>
</head>
<body>
<a href="index.php?file=flag.php">点击即送flag，走过路过不要错过</a>
<?php
if(isset($_GET['file'])) {
    $file = $_GET['file'];
    include($file);
}
?>
</body>
</html>