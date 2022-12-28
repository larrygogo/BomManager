#include "file.h"

void createFile(char *filePath) {
    //文件指针
    FILE *fileP;
    //使用“读入”方式打开文件
    fileP = fopen(filePath, "r");
    //如果文件不存在
    if (fileP == NULL) {
        //使用“写入”方式创建文件
        fileP = fopen(filePath, "w");
    }
    //关闭文件
    fclose(fileP);
}

