#include <iostream>

#include "encode.h"
#include "Writer.h"
#include "decode.h"

int main() {
    Writer wr("enc");
    Reader rd("file.txt");
    encode(rd,wr);

    return 0;
}
