/**
 * 附录 Ⅰ. 格式化输出
 * ============================================================================
 * 运行命令：gcc -x c i-printf.h && ./a.exe
 * 
 * 格式字符串占位符：
 *          %[flags][width][.precision][length modifier]conversion
 *            -----  -----  ----------  --------------- ----------
 * %c       %                                                    c  一个字符
 * %d       %                                                    d  整数
 * %ld      %                                         l          d  long
 * %s       %                                                    s  字符串
 * %16s     %           16                                       s  固定长度 16
 * %f       %                                                    f  小数
 * %.8f     %                       .8                           f  固定精度 8
 * %p       %                                                    p  指针
 * %#llx    %     #                                  ll          x  long long
 *                                                                  前导 0x
 * %zd      %                                         z          d  size_t
 * 
 * 
 * @see https://man7.org/linux/man-pages/man3/printf.3.html
 */

#include <stdio.h>
#include <stdint.h>
#include <math.h>
#include <float.h>

int main() {
    printf("%8s  %c\n", "%c", 'a');
    printf("%8s  %d\n", "%d", -2);
    printf("%8s  %+d\n", "%+d", 2); // 显示正负号
    printf("%8s  %ld\n", "%ld", __STDC_VERSION__);
    printf("%8s  %s\n", "%s", "Hello world!");
    printf("%8s  %16s\n", "%16s", "Hello world!");
    printf("%8s  %.4s\n", "%.4s", "Hello world!"); // 只显示前几个字符
    printf("%8s  %f\n", "%f", 0.618);
    printf("%8s  %.8f\n", "%.8f", 0.618);
    printf("%8s  %16.2f\n", "%16.2f", 0.618);
    printf("%8s  %c\n", "%c", 'a');
    int i;
    printf("%8s  %p\n", "%p", &i);
#ifdef _WIN64
    printf("%8s  %#llx\n", "%#llx", &i);
#else
    printf("%8s  %#lx\n", "%#lx", &i);
#endif
    printf("%8s  %X\n", "%X", &i); // 大写十六进制
    printf("%8s  %g\n", "%g", DBL_MAX); // 6 位精度输出，超过显示为科学计数法
    printf("%8s  %.2G\n", "%.2G", DBL_MAX);
    printf("%8s  %zd\n", "%zd", sizeof(uint_fast8_t));
    int octal = (int)pow(8, 8) - 1;
    printf("%8s  %o\n", "%o", octal); // 八进制
    printf("%8s  %#o\n", "%#o", octal);
    printf("%*s  %d\n", 8, "%.*s", 1); // 占位符参数
    printf("%-8d  %-16f  %-4s\n", 1, 0.618, "end"); // 后填空格，左对齐
    printf("%-8d  %-16.2f  %-4s\n\n", 2, 0.618, "end");

    // 九九乘法表
    for (int i = 1; i <= 9; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%dx%d=%-3d", j, i, i * j);
        }
        putchar('\n');
    }
    return 0;
}
