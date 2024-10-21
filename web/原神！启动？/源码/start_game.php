<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <title>Are you sure this is true entrance?</title>
</head>
<body>
  <img src="./img/game.png" alt="" />
  <?php
    // 设置 Cookie 名称、值以及其他参数
    $cookie_name = "entrance";
    $cookie_value = "/fl444444g.php";

    // 设置 Cookie，有效期为 30 天
    setcookie($cookie_name, $cookie_value); // 86400 = 1 天
  ?>
</body>
</html>
