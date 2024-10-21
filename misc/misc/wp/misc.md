## Misc

### 阿尼亚

奇数为伪加密，偶数为真加密

解决伪加密的办法：

1. 使用010editor去手动修改，把奇数改成00
2. 使用360压缩，直接无视伪加密

![685ad8ca5c0d29d31c778d5dd91a20c](F:\misc出题新\misc出题\wp\misc.assets\685ad8ca5c0d29d31c778d5dd91a20c.png)

![00e027a44c60d50a50e140973e3d717](F:\misc出题新\misc出题\wp\misc.assets\00e027a44c60d50a50e140973e3d717.png)

![c340c0a496b1a1adbdf6be36550c2ad](F:\misc出题新\misc出题\wp\misc.assets\c340c0a496b1a1adbdf6be36550c2ad.png)

即可打开压缩包，得到一张图片，可能是图片隐写

![4637b4600c4104a79de6e40982b9d86](F:\misc出题新\misc出题\wp\misc.assets\4637b4600c4104a79de6e40982b9d86.png)

在终端用 java -jar Stegsolve.jar打开隐写工具

![](F:\misc出题新\misc出题\wp\misc.assets\9a614a24d28e1015eec791ee5e5f6e2.png)

-->Analyse-->data extract(进行数据提取)

![0350d5a383743215e60cdbee21b8e69](F:\misc出题新\misc出题\wp\misc.assets\0350d5a383743215e60cdbee21b8e69.png)

可以获取文件的RGB信息即可得出flag

![69a523262aace0c30f28c52db7dc222](F:\misc出题新\misc出题\wp\misc.assets\69a523262aace0c30f28c52db7dc222.png)

TYCTF{Welc0me_t0_TYCTF_2024}

### 你知道我在哪吗

根据题目“雪点翠云裘”可知这首诗是江夏送友人，所描写的地方是武汉

![7dfccadd6a3ed4dca7f486c69764c41](F:\misc出题新\misc出题\wp\misc.assets\7dfccadd6a3ed4dca7f486c69764c41.png)

![3bcc6d2e689d05d3d1f61eaf98e9276](F:\misc出题新\misc出题\wp\misc.assets\3bcc6d2e689d05d3d1f61eaf98e9276.png)

远处看见招牌“周师傅”

![13245a7c833d7a4b12ae4baa1e13638](F:\misc出题新\misc出题\wp\misc.assets\13245a7c833d7a4b12ae4baa1e13638.png)

在高德地图上进行社工搜索，可得应是周师傅糕点，“正新鸡排”和“柠檬黄”可加以验证

![47fed9d44f6047d844a3dd9333ccadb](F:\misc出题新\misc出题\wp\misc.assets\47fed9d44f6047d844a3dd9333ccadb.png)

可得到此交叉路口为粮道街与胭脂路交出路口

![6b2d467bffbbf30489a26fafb4c0dee](F:\misc出题新\misc出题\wp\misc.assets\6b2d467bffbbf30489a26fafb4c0dee.png)

![f8ad1ccb640a01a4540de12223307c5](F:\misc出题新\misc出题\wp\misc.assets\f8ad1ccb640a01a4540de12223307c5.png)

TYCTF{武汉市武昌区粮道街与胭脂路交叉口}

### 一共多少集

压缩包加密，且没有提示，尝试暴力破解，密码为56987

![19720cc0bcec03655f54c8c86b11921](F:\misc出题新\misc出题\wp\misc.assets\19720cc0bcec03655f54c8c86b11921.png)

得到一张图片

![cfe960e33c421f23d973d822ca12e47](F:\misc出题新\misc出题\wp\misc.assets\cfe960e33c421f23d973d822ca12e47.png)

看着图片显示不全，用010改一下宽高

![5a2edfac20bd54fd2c1f58c67e00ead](F:\misc出题新\misc出题\wp\misc.assets\5a2edfac20bd54fd2c1f58c67e00ead.png)

得到一串字符串，显而易见的base64加密

![c9f408fe0066fe748fe7a851308acaf](F:\misc出题新\misc出题\wp\misc.assets\c9f408fe0066fe748fe7a851308acaf.png)

![128ca833d25042cd0a8cb7cbe8c113c](F:\misc出题新\misc出题\wp\misc.assets\128ca833d25042cd0a8cb7cbe8c113c.png)

TYCTF{Chen_qi_zuobu_daoa}