# L02详解版：演示与练习代码

在C语言编程目录运行以下检查。所有数值输入测试均限定在目标类型可表示范围内；不能把 `scanf` 的返回值检查当成任意输入的完整安全处理。

- 前六个示例：`python3 -B validation/verify_l02_extended.py`，结果保存到 `validation/L02_extended_evidence.json`。
- 四个输入输出示例：`python3 -B validation/verify_l02_io_expansion.py`，结果保存到 `validation/L02_io_expansion_evidence.json`；包含GCC/Clang严格C17编译、实际输入输出和输入示例的ASan/UBSan检查。
- 三个数据理解示例：`python3 -B validation/verify_l02_data_depth.py`，结果保存到 `validation/L02_data_depth_evidence.json`；核对普通int对象大小、科学计数法、声明/注释与不同输出精度，另有临时教师类型探针。
- 三个输出读法示例：`python3 -B validation/verify_l02_output_clarity.py`，结果保存到 `validation/L02_output_clarity_evidence.json`；核对调用、无符号整数进制输出和表格空格，并只编译`broken/wrong_printf_type.c`收集真实格式诊断。
- 类型边界查询：`python3 -B validation/verify_l02_type_ranges.py`，结果保存到`validation/L02_type_ranges_evidence.json`；用Python大整数及精确有理数独立复算，区分本机运行与其他目标的仅编译检查。

| 文件 | 课堂用途 |
|---|---|
| type_limits_probe.c | 教师查询本机整数范围、浮点精度参数与类型大小；不要求学生背探针实现或实测数值 |
| type_range_report.c | 教师查询int/long/long long、float/double/long double的范围及精度；负有限端点、MIN与TRUE_MIN分开；十进制打印值是约数，末尾十六进制数据用于精确核验 |
| data_basics.c | 观察字面量、字符与数值、bool及普通值复制；PPT只取相关小段 |
| format_demo.c | 对照最小字段宽度、输出精度和转义；精确小数展开标为本机观察 |
| char_input_raw.c | 教师演示 `%c` 直接取得换行；学生聚焦输入语句，辅助输出函数不作为L02学习要求 |
| char_input_skip.c | 教师演示 `" %c"` 跳过前导空白后读取字符 |
| length_report.c | 课内长度报告的完整参考实现；未验证长度的物理合理性，不把负数输出当作有效测量证明 |
| name_and_value.c | 对照引号中的固定文字、变量取值，以及标签与数值的组合输出 |
| numeric_text.c | 用键盘输入024说明：`%d`按十进制读得数值24，数字字符的个数不决定int对象大小；不与源码中的八进制常量024混淆 |
| multiple_input.c | 观察`%d %lf`两项转换的赋值次数、第一项成功后第二项失败，以及EOF；所有被观察对象先初始化 |
| comma_input.c | 观察`%d,%lf`中的普通逗号必须匹配；逗号本身不增加成功赋值项数 |
| object_storage.c | int值由9改成12000，比较赋值前后的`sizeof sample_count`及`sizeof(int)`；4 B和CHAR_BIT=8只代表本机 |
| scientific_values.c | 核对十进制指数含义；对同一小量比较`%.6f`、`%.2e`、`%.2f`，分清输出文本与对象的值 |
| declaration_layout.c | 分别初始化同类变量，并展示两种C17注释；全部实际读取的对象均先初始化 |
| call_reading.c | 读取一次printf调用：格式串是第1个实参，变量当前值是第2个实参；另含double正确格式的对应输出 |
| integer_base_output.c | 同一个unsigned int的当前值58按%u/%o/%x/%X显示，结果为58/72/3a/3A，保存的值不变 |
| aligned_report.c | 两列受控ASCII数字使用最小字段宽度；保留实际空格，分别核对4字符字段、3字符分隔和7字符字段 |

multiple_input.c与comma_input.c打印失败后的对象状态，只为说明哪些赋值已经发生，不是在输出有效业务结果。不能用初始标记判断成功，应检查返回项数；`ready=yes`仅表示本次两项转换赋值成功，不表示整行没有尾随内容或数值符合物理条件。成功、部分失败、完全不匹配、EOF和尾随文本分别测试，不运行超范围转换反例。

主课堂温度程序仍为上级目录的 `temperature_report.c`。这些补充程序不要求在90分钟内逐个输入，也不作为超出已讲知识的得分门槛。

输出错配例`../broken/wrong_printf_type.c`只编译、不执行；`%d`配double不属于可靠的自动转换。课程使用`-Werror`把格式警告视为错误，不能由此声称所有编译器都必然拒绝此类程序。表格课件中的圆点仅代表空格位置，并非实际输出字符。

当前记录以Linux x86-64、GCC 13.3和Clang 20为实测环境。换环境应先重跑，不能把固定字节数、ASCII码值或浮点展开当成C17对所有实现的保证。`_Generic`仅用于验证器在临时目录生成的教师类型探针，不放进学生示例。

本轮范围查询程序没有输入路径，不运行超范围转换或溢出反例。`FLT_LOWEST/DBL_LOWEST/LDBL_LOWEST`只是该程序的输出标签，不是标准宏；分别来自`-FLT_MAX/-DBL_MAX/-LDBL_MAX`。其他目标只以Clang进行无系统头文件的尺寸/类型断言编译，没有链接或运行Windows程序。原6例验证器按其负责的明确文件集检查，不将此目录后来增加的其他示例误判为缺文件。
