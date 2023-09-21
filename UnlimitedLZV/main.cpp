#include <iostream>

#include "encode.h"
#include "Writer.h"
#include "decode.h"

int main() {
    Writer wr("out4.jpg");
    Reader rd("enc4");
    decode(rd,wr);

    return 0;
}
