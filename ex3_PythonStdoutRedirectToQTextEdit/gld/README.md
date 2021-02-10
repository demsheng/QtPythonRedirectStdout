## gld
2021-02-11

- 作者：李长圣
- 邮箱：sheng0619@163.com
- 功能：演示在如何重定向Python的标准输出print到c++的stdout
- 支持 `window10`  系统

### 使用方法
- 打开gld.pro，release模式编译，将生成 ../bin/gld.pyd 和 ../bin/test.py
- 进入../bin文件夹, 打开cmd，运行 `python test.py`输出
	```
	test1
	test2
	test3

	```
### 文件介绍
- `gldmodule.cpp`  命名格式为 xxmodule.cpp，xx为模块名，这里为gld
- `test.py` 在cmd中运行 `python test.py`，测试结果 
- `gld.dll` 编译后，将生成该动态链接库，gld.pro中会自动将其重命名为 `gld.pyd`供test.py调用
- `gld.pro` 演示了如何采用qmake命令重命名gld.dll为gld.pyd