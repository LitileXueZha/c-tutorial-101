/**
 * 02. 变量和数据类型
 * ============================================================================
 * 运行命令：gcc 02-variables-data-types.c && ./a.exe
 * 
 * Variables 变量是编程概念中的重要组成部分，程序在运行时实际上 CPU 是对变量的各种
 * 运算，它可能是内存中的一小块数据，或者仅指向某个内存地址（指针）。变量可声明为
 * 不可变的常量，这样就不能改变它，常量往往用于大型项目中的全局标识。
 * 
 * 声明变量时必须要定义它的 Data Types 数据类型，变量本质上是编程语言中对数据的表示
 * 形式，而内存中的二进制数据是无法直接进行编程，计算机识别的只有二进制，所以需要定义为
 * 人类可读的数据类型，例如数字和字符。
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <wchar.h>
#include <locale.h>
#include "util/win32.h"

/**
 * 变量的命名规则：
 *   1. 只能用数字、字母和下划线。对应正则元字符 \w
 *   2. 区分大小写
 *   3. 不能以数字开头
 *   4. 不能是关键字
 */
const char A = 'a';
int a, _b, c0;


/**
 * 变量的存储类别
 * ============================================================================
 * 一个变量，什么时候可用，什么时候销毁，取决于它的 Storage Classes 存储类别。主要
 * 分为 4 种：auto、extern、static、register。
 * 
 * auto 是 c 语言中分配变量的默认方式，也就是说未指明时默认 auto。这样的变量只在当前
 * 作用域有效，离开此作用域后会被销毁，且不再可用。作用域指的是被花括号 {} 括起来的
 * 代码。
 * 
 * extern 指明变量是外部的，已在其它文件初始化过的。在多文件项目中比较常见，这种变量
 * 通常是全局可用的。
 * 
 * static 有两种情况：一种在文件顶级作用域中使用，限制该变量只能在当前文件中使用；
 * 另一种往往在函数内部，指明变量无需再次初始化，保留上一次函数执行完后的值。
 * 
 * register 指明变量应该存储在 CPU 的寄存器中，而不是 RAM 内存里。这样的变量拥有
 * 最快的访问速度，但是不能被取址符 & 使用，而且和 auto 一样，只在当前作用域有效。
 * 需要注意的是，register 取决于硬件实现，并不真正意味着存到了寄存器里，有的编译器
 * 优化最佳执行速度时会忽视。
 */
extern char aa;
static char ab = 'a';
void StorageClasses() {
    char ab = 'a';          // 默认 auto，每次执行时重新初始化
    static char ac = 'a';   // 无需再次初始化
    register char ae;
}

/**
 * 常量，字面量，NULL
 * ============================================================================
 * 常量不能被修改，主要应用于全局标识。常量有 2 个约定俗称的写法：
 *   - 使用大写字符
 *   - 指针类型的函数参数，最好声明为常量
 * 
 * Literals 字面量就是代码里写的值，例如数字 1 或字符串 "abc" 等等，它有一些不同的
 * 写法：
 * 
 * --------+--------------------------------+-------------------
 * 类型       说明                             例子
 * --------+--------------------------------+-------------------
 * 前缀 0     八进制数值写法                    0777
 * 前缀 L     宽类型字符串                      L"中午"
 * 后缀 L     表示 long 类型整数                1L
 * 　　 LL    表示 long long 类型               11LL
 * 　　 F     表示 float 浮点数                 0.96F
 * 　　 U     表示 unsigned int，可与 L 结合    23U 23UL 23ULL
 * --------+--------------------------------+-------------------
 * 
 * 注：十六进制、科学计数法、Unicode 字符等写法都是通用的，不再赘述。
 * 
 * NULL 定义在标准库 <stddef.h> 里，是一个常见的宏，可能为空指针或数值 0，取决于
 * 编译器。
 */
const int VER = 0777;
const long long VVER = 11LL;
const unsigned long VER_UNSIGNED = 23UL;
const float PRICE = 0.96F;
const char VERSION[] = "版本1.0";
void emptyPointerParamFunc(const int *ptr) {/* empty */}


/**
 * 数据类型
 * ============================================================================
 * C 语言中常见的数据类型有数字、字符串、指针和结构。
 * 
 * 数字是 c 语言中最基本的数据类型，分为整数和浮点数，正负值在计算机中表示为有无符号，
 * 其存储大小决定了能够表示的范围，对于超出了变量范围的情况，称之为“溢出”。
 * 
 * ---------------+--------------+------------------------+------------
 *           类型   存储大小        范围                      小数精度
 * ---------------+--------------+------------------------+------------
 *           char   1 byte (8位)   -128~127 or 0~255
 *  unsigned char   1 byte         0~255
 *    signed char   1 byte         -128~127
 *            int   2 or 4 bytes   -32768~32767 or
 *                                 -2^33~(2^33-1)
 *   unsigned int   2 or 4 bytes   0~65535 or 0~(2^32-1)
 *          short   2 bytes
 * unsigned short   2 bytes
 *           long   8 bytes
 *  unsigned long   8 bytes        0~(2^64-1)
 *          float   4 bytes                                   6个
 *         double   8 bytes                                  15个
 *    long double  10 bytes                                  19个
 * ---------------+--------------+------------------------+------------
 * 
 * 注：正负号在二进制表示法中占 1 bit，无符号整数只能表示正整数，负数则需要带上符号。
 *     使用 sizeof() 可以判断变量的存储大小。
 *     https://stackoverflow.com/questions/512022/why-doesnt-c-have-unsigned-floats
 * 
 * 字符串实际上是 char 字符类型的数组，必须用双引号表示，而单个字符只能用单引号，要
 * 注意的是，单个字符只能表示 ASCII 里的文本，对于多字节的文本，譬如中文，即便只有一个
 * 字，也需要使用双引号，否则输出会有问题。
 * 
 * 字符在存储时对应的是字符集中的编码，也就是数字，因此可以进行算术运算，如果是多字节，
 * 则需要对每个字节进行运算。
 * 
 * 注：C 语言天生缺乏对字符串的处理，不能使用 + 号拼接 2 个字符串。
 */
void DataTypes() {
    int num1 = -1;
    unsigned int num2 = 2;
    short num3 = -3;
    unsigned long num4 = 444444;
    float num5 = -0.5;
    double num6 = 0.1234567;
    char str1 = 'a';
    char str2[] = "啊";
    char *str3 = "指针型字符串a";
    printf("DataTypes:\n\t%d %f %s\n", num2, num5, str3);
    char aLongString[] =
        "line 1\n"
        "line 2\n"
        "line 3";
}


/**
 * void，枚举，固定宽度整数，宽字符
 * ============================================================================
 * void 指明没有类型。一个函数，如果声明时加上 void，说明它不会返回任何东西，如果它的
 * 参数声明为 void，说明不需要参数。void 也应用在指针上，使得该变量可以是任何类型。
 * 
 * enum 枚举用来限定一个变量只能是一系列离散的值，比如性别、国家等。类似于常量，但
 * 由程序自动设置它的值，也可以手动指明。enum 实际上还是整型 int，提高代码可读性。
 * 
 * 有些系统实现整型时，存储时所用的字节大小不一，c 语言标准库 <stdint.h> 里定义了
 * 一系列固定宽度的整数类型，用以精确地控制字节大小。很少用到。
 * 
 * 通用的 UTF-8 编码的字符串是多字节的，一个字可能最多有 4 byte，如果想要精准地控制
 * 字节大小，基本不太可能，因此 c 语言提供了宽字符类型 wchar_t，固定了字节大小。它
 * 定义在标准库 <wchar.h> 里，想要声明为宽类型字符串需要加上前缀 L。很少用到，但桌面
 * 开发 win32 应用会有。
 * 
 * 注意：宽字符的实现方式是 UTF-16，不能直接输出到控制台，否则乱码，printf() 中有
 * 特殊的占位符 %lc, %ls 用以输出。此外，输出宽字符还需设定本地化环境 setlocale()
 */
void noReturnFunc() {}
int noNeedParamsFunc(void) {}
void EnumFixedWidth() {
    void *maybeAnyType = malloc(8);
    enum sex {MALE, FEMALE};
    enum country {
        CHINA = 99,
        JAPAN,
        US = -1
    };
    printf("EnumFixedWidth:\n\t%d %d\n", FEMALE, JAPAN); // 1, 100

    int8_t i8 = -1;
    int16_t i16 = 0;
    int32_t i32 = 0;
    int64_t i64 = 0;
    uint8_t u8 = 0; // 无符号整数
    uint64_t u64 = 0;
    uint_fast8_t uf8 = 0; // 使整数计算达到最快的类型
    int_fast64_t if64 = 0;
    uint_least8_t ul8 = 0;
    printf("\t%d %d %d\n", sizeof(i32), sizeof(u8), sizeof(if64));

    char str1 = 'a';
    wchar_t str2 = L'a';
    printf(
        "\t%c=%d %lc=%d\n",
        str1, sizeof(str1),
        str2, sizeof(str2)
    );
}


/**
 * 类型转换
 * ============================================================================
 * 不同数据类型的变量互相运算时，编译器会自动 Type Casting 类型转换，使它们变成相同的
 * 类型，这一过程是隐式的。
 * 
 * 算术运算时，占用字节小的会被隐式转换为占用更多的，这是为了防止截断，丢失数据导致
 * 非预期的结果。
 * -----------------------------------------------
 *               long double  ↑
 *                    double  ↑
 *                    float   ↑
 *      unsigned long long    ↑
 *               long long    ↑
 *           unsigned long    ↑
 *                    long    ↑
 *           unsigned int     ↑
 *                    int     ↑  Integer Promotion
 *                    char    ↑
 * ------------------------------------------------
 * 
 * 隐式类型转换有时会导致意料之外的结果，甚至会运行出错，应尽量避免。C 语言可以手动
 * 转换数据类型，进行显式转换：
 *      (data_type)variable_name;
 * 
 * 如果一个类型，转换为“更小的”类型，即便是显式的，仍然会导致截断 truncation，例如
 * 宽字符转普通字符，这样的情况需要额外注意，不能直接进行转换，需要借助函数。
 */
void TypeCasting() {
    char a = 'a';
    int i = 1;
    float j = 0.1;
    double k = 0.233;

    float n1 = i + j;
    double n2 = i - k;
    double n3 = j * k; // 隐式
    int m1 = i + (int)j;
    int m2 = (int)j + (int)k; // 显式，截断
    char *str = (char *)malloc(8);

    setlocale(LC_ALL, "");
    wchar_t *b = L"啊11";
    char bb[5];
    int bytes = wcstombs(bb, b, 5);
    printf("TypeCasting:\n\t%f %d %s %s %d\n", n3, m2, bb, (char *)b, bytes);
    perror("printf");
    free(str);
}


int main(int argc, char *argv) {
    Util_fixCmdEncoding();
    if (NULL == 0){
        puts("NULL==0");
    }
    if (0.1 + 0.2 == 0.3) {
        // 经典问题
        // 有的小数存储为二进制时是无限的，计算机只能存储有限的精度，这导致运算
        // 之后的结果丢失了部分精度，和预期结果不能完全匹配。
        puts("0.1+0.2==0.3");
    }
    printf("%f %f %s\n", (double)(0.1+0.2), 60*0.618, "我");
    printf("ok %s %d %s\n", "我🙄", sizeof(NULL), NULL);
    puts("我的天");
    perror("printf");
    DataTypes();
    EnumFixedWidth();
    TypeCasting();
    return 0;
}

// 注：对于非 ASCII 环境，例如中文，需要指定 gcc 编码，否则运行时会输出乱码。
// gcc -fexec-charset=gbk
// 或者输入 chcp 65001 切换到 UTF-8 编码（Windows cmd.exe）
